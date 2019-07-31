#ifndef IMAGE_H_
#define IMAGE_H_

#include <iostream>
#include <SDL2/SDL.h>

namespace dex{

    class Image{
    private:
        SDL_Renderer *renderer;
        SDL_Texture *texture;
    public:
        explicit Image(std::string filepath);

        void draw(int x, int y);
    };

}

#endif