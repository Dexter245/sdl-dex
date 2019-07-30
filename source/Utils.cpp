#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <Application.h>

#include "Utils.h"

std::string dex::filepath(std::string path) {
#ifdef SWITCH
    path = "romfs:/" + path;
#else
    path = "romfs/" + path;
#endif
    return path;
}

void dex::logSDLError(const std::string &msg) {
    std::cout << msg << " error: " << SDL_GetError() << std::endl;
}

SDL_Texture *dex::loadTexture(const std::string &file) {
    //Initialize to nullptr to avoid dangling pointer issues
    SDL_Texture *texture = nullptr;
    //Load the image
    SDL_Surface *loadedImage = nullptr;
    std::string ext = file.substr(file.find("."), 3);
    if(ext == "BMP" || ext == "bmp"){//todo: load based on file extension
        loadedImage = SDL_LoadBMP(file.c_str());
    }else{
        loadedImage = IMG_Load( file.c_str() );
    }
    //If the loading went ok, convert to texture and return the texture
    if (loadedImage != nullptr){
        texture = SDL_CreateTextureFromSurface(dex::Application::instance().getRenderer(), loadedImage);
        SDL_FreeSurface(loadedImage);
        //Make sure converting went ok too
        if (texture == nullptr){
            logSDLError("CreateTextureFromSurface");
        }
    }
    else {
        dex::logSDLError("LoadBMP");
    }
    return texture;
}

void dex::renderTexture(SDL_Texture *tex, int x, int y) {
    //Setup the destination rectangle to be at the position we want
    SDL_Rect dst;
    dst.x = x;
    dst.y = y;
    //Query the texture to get its width and height to use
    SDL_QueryTexture(tex, NULL, NULL, &dst.w, &dst.h);
    SDL_RenderCopy(dex::Application::instance().getRenderer(), tex, NULL, &dst);
}

