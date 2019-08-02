#include "Application.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include "Utils.h"
#include "View1.h"
#include "Event.h"


#ifdef SWITCH
#include <switch.h>
#endif

dex::Application::Application() {

#ifdef SWITCH
    //Sets up the network sockets for nxlink
    socketInitializeDefault();
    //Sets up printf to be passed to our nxlink server on the computer
    nxlinkStdio();

    int rc = romfsInit();
    if (R_FAILED(rc)){
        printf("Error initializing romfs. error: %d", rc);
        exit(1);
    }

    printf("running on switch\n");
#else
    printf("running on linux\n");
#endif

    //Initialize PNG loading
    int imgFlags = IMG_INIT_PNG | IMG_INIT_JPG;
    if (!(IMG_Init(imgFlags) & imgFlags)) {
        printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
        exit(1);
    }

    //SDL_INIT_HAPTIC causes crash
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER | SDL_INIT_AUDIO |
                 SDL_INIT_JOYSTICK | SDL_INIT_GAMECONTROLLER | SDL_INIT_EVENTS) != 0) {
        dex::logSDLError("SDL_Init");
        exit(1);
    }

    window = SDL_CreateWindow("sdl-dex", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                              SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

    if (window == nullptr) {
        dex::logSDLError("CreateWindow");
        SDL_Quit();
        exit(1);
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == nullptr) {
        dex::logSDLError("CreateRenderer");
        dex::cleanup(window);
        SDL_Quit();
        exit(1);
    }
    if (TTF_Init() != 0) {
        dex::logSDLError("TTF_Init");
        SDL_Quit();
        exit(1);
    }


}

dex::Application::~Application() {

}

void dex::Application::start() {
    std::cout << "start" << std::endl;

    while (shouldRun) {
        std::cout << "mainloop, shouldRun: " << shouldRun << std::endl;


        //todo: calc delta time somehow somewhere

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        controller->update(0.16f);
        view->render();

        //todo: remove later, test only
        eventHandler.addEvent(dex::Event(dex::Event::EventType::KEY_DOWN, "test1"));

        SDL_RenderPresent(renderer);

        //todo: remove later
        SDL_Delay(5000);
//        end();

    }

}

void dex::Application::setController(dex::Controller *newController) {
    this->controller = newController;
}

void dex::Application::setView(dex::View *newView) {
    this->view = newView;
}

void dex::Application::end() {
    std::cout << "Application::end" << std::endl;
    this->shouldRun = false;
    SDL_DestroyWindow(window);
    cleanup(window, renderer);
    SDL_Quit();
#ifdef SWITCH
    //Clean up after we're done and close our sockets.
    socketExit();
#endif
}




