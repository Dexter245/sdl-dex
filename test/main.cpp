#include <iostream>
#include "Application.h"

int main(int argc, char **argv){
    std::cout << std::endl << "main" << std::endl;

    dex::Application app = dex::Application::instance();
    app.start();
}
