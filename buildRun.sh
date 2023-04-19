#!/bin/bash

# for my own kate setup, dont expect it to work anywhere else

libsDir="./src"

if [ -d $libsDir ]; then
	echo Compiling main and libs...
	g++ $1.cpp ./src/*.cpp -o run -I./include && ./run
else
	echo Compiling standalone main...
	g++ $1.cpp -o run && ./run
fi
echo
read -p "Press [Enter] to exit..."
