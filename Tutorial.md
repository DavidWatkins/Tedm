#Introduction
Welcome to Tedm, a C++ game library which aims to help developers design simple C++ games that work across multiple operating systems. Unlike other libraries it is designed to be lightweight and take a lot of the complexity out of game design. It is solely reliant on SDL for the graphics design - however this is customizable as the library is only interactable through a series of interfaces. This library is heavily based on the design flow of [https://phaser.io](phaser.js)

#Requirements
Clone the repository from [here](https://github.com/DavidWatkins/Tedm) and the resources that exist in that repository. The code for this tutorial exists inside of the demos folder. 

In order to follow this tutorial you'll need a very basic understanding of C++. Some additional resources that might help you understand the library would include these tutorials on SDL:
- [http://lazyfoo.net/SDL_tutorials/](http://lazyfoo.net/SDL_tutorials/)
- [https://wiki.libsdl.org/Tutorials](https://wiki.libsdl.org/Tutorials)

Once you've downloaded everything and have a copy of the repository, you'll need to make sure you have a compatible system with the code. This system has only been tested on Ubuntu 16.10 and MAC OS X. You'll need to make sure you have a recent copy of cmake as well. In order to build for Ubuntu 16.10:
```bash
$ sudo bash ./install-deps.sh
$ mkdir build && cd build
$ cmake .. && make
```
To build for MAX OS X
```bash
$ brew install sdl2
$ mkdir build && cd build
$ cmake .. && make
```

Open the part1 tutorial and you'll see a basic game state which gives you a sense of boilerplate Tedm code. 