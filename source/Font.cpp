#include "Font.h"

#include <iostream>
#include "Utils.h"
#include "Application.h"

dex::Font::Font(std::string fontFile, int fontSize) {

    renderer = Application::instance().getRenderer();

    font = TTF_OpenFont(filepath(fontFile).c_str(), fontSize);
    if (font == nullptr){
        logSDLError("TTF_OpenFont");
        exit(1);
    }
}

dex::Font::~Font() {
    TTF_CloseFont(font);
}

void dex::Font::renderText(std::string text, int x, int y) {
    SDL_Color color = {255, 255, 255, 255};
    renderText(text, x, y, color);
}

void dex::Font::renderText(std::string text, int x, int y, SDL_Color color) {
    //We need to first render to a surface as that's what TTF_RenderText
    //returns, then load that surface into a texture
    SDL_Surface *surf = TTF_RenderText_Blended(font, text.c_str(), color);
    if (surf == nullptr){
        TTF_CloseFont(font);
        logSDLError("TTF_RenderText");
        exit(1);
    }
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surf);
    if (texture == nullptr){
        logSDLError("CreateTexture");
        exit(1);
    }
    renderTexture(texture, x, y);
    SDL_FreeSurface(surf);
    SDL_DestroyTexture(texture);
}
