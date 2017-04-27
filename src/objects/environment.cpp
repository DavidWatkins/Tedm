#include "objects/environment.h"

Environment::Environment() {
}

Environment::Environment(std::string filename) {
    background_file.open(filename, std::ios::binary);
}

Environment::~Environment() {
    background_file.close();
}

void Environment::add_background(std::string filename) {
    background_file.open(filename, std::ios::binary);
}
