
#include <Image.h>

#include "Image.h"
#include "Utils.h"


dex::Image::Image(std::string filepath) {
    this->texture = dex::loadTexture(dex::filepath(filepath));
}

dex::Image::~Image() {
    SDL_DestroyTexture(texture);
}

void dex::Image::draw(int x, int y) {
    dex::renderTexture(texture, x, y);
}

