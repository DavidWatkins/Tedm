#include "environment.hpp"

Environment::Environment() {
}

Environment::~Environment() {
    background_file.close();
}

void Environment::add_background(std::string filename) {
    background_file.open(filename, std::ios::binary);
}