#ifndef APPLICATION_H_
#define APPLICATION_H_

#include "Scene.h"
#include <SDL2/SDL.h>
#include <iostream>

namespace dex{

    class Application{

    private:
        Scene currentScene;
        bool shouldRun = true;
        SDL_Renderer *renderer;
        SDL_Window *window;

        Application();

    public:
        const int SCREEN_WIDTH = 1280;
        const int SCREEN_HEIGHT = 720;

        ~Application();
        static Application instance(){ static Application instance; return instance; }
        void setScene(Scene newScene);
        void setWindowTitle(std::string title){ SDL_SetWindowTitle(window, title.c_str()); }
        SDL_Renderer* getRenderer(){ return renderer; }
        void start();

    };

}

#endif