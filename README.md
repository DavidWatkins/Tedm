<a href="https://github.com/DavidWatkins/Tedm">
    <img src="https://cdn.rawgit.com/DavidWatkins/Tedm/274b01b5/resources/Tedm.png" alt="Tedm logo"
         title="Tedm Logo" align="right" />
</a>

[![Build Status](https://travis-ci.org/DavidWatkins/Tedm.svg?branch=master)](https://travis-ci.org/DavidWatkins/Tedm)
# [Tedm](https://github.com/DavidWatkins/Tedm)
A C++ game engine with an SDL backend

# Dependencies
This library is fairly lightweight, only relying on SDL2 to offer a cross platform graphics library solution. 
- For Ubuntu 16.10
```bash
$ sudo apt-get install libsdl2-2.0 libsdl2-dev libsdl2-image
```
or alternatively run 
```bash
$ sudo bash ./install-deps.sh
```
- For MAC OS X
```bash
$ brew install sdl2
```

# How to build
```bash
$ mkdir build && cd build
$ cmake .. && make
```

# Tutorial
[Tutorial for this project](Tutorial.md)

# Documentation
To build the documentation download doxygen and run:
```bash
$ doxygen doxygen_config
$ firefox documentation/html/index.html
```
