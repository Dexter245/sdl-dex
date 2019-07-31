#include "Image.h"
#include "Utils.h"


dex::Image::Image(std::string filepath) {
    this->texture = dex::loadTexture(dex::filepath(filepath));
}

void dex::Image::draw(int x, int y) {
    dex::renderTexture(texture, x, y);
}
