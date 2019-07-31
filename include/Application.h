#ifndef APPLICATION_H_
#define APPLICATION_H_

#include <SDL2/SDL.h>
#include <iostream>
#include "Controller.h"
#include "View.h"

namespace dex {

    class Application {

    private:
//        static Application *_instance = nullptr;
        dex::Controller *controller = nullptr;
        dex::View *view = nullptr;
        bool shouldRun = true;
        SDL_Renderer *renderer = nullptr;
        SDL_Window *window = nullptr;

        Application();

    protected:

    public:
        const int SCREEN_WIDTH = 1280;
        const int SCREEN_HEIGHT = 720;

        ~Application();

        static Application &instance() {
            static Application _instance;
            return _instance;
        }

        void setController(dex::Controller *newController);

        void setView(dex::View *newView);

        void setWindowTitle(std::string title) { SDL_SetWindowTitle(window, title.c_str()); }

        SDL_Renderer *getRenderer() { return renderer; }

        void start();

        void end();

        Application(Application const &) = delete;

        void operator=(Application const &) = delete;

    };

}

#endif