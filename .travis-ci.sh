#!/bin/bash

APT="libsdl2-2.0 libsdl2-dev libsdl2-image-dev cmake libegl1-mesa-dev libgles2-mesa-dev"
	 	 
sudo apt clean
sudo apt update -qq
sudo apt install -qq $APT
mkdir build && cd build
cmake ..
make
