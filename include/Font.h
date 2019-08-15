#ifndef FONT_H_
#define FONT_H_

#include <string>
#include "SDL2/SDL.h"
#include "SDL2/SDL_ttf.h"

namespace dex{

    class Font{

    private:
        TTF_Font *font;
        SDL_Renderer *renderer;

    public:
        Font(std::string fontFile, int fontSize);
        ~Font();

        void renderText(std::string text, int x, int y);
        void renderText(std::string text, int x, int y, SDL_Color color);

    };

}

#endif