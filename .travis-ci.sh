#!/bin/bash

APT="libsdl2-2.0 libsdl2-dev libsdl2-image-dev cmake"
	 	 
sudo apt-get update -qq
sudo apt-get install -qq $APT
mkdir build && cd build
cmake ..
make
