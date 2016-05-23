#!/bin/bash
#compile and
# flag -r means also run

if [ "$1" != "" ]; then
  echo "Creating .o files"
  gcc -std=c++11 -c *.cpp
  echo "Linking and building Runnable file"
  g++ *.o -o "$1" -lsfml-graphics -lsfml-window -lsfml-system
  if [ "$2" == "-r" ]; then
    echo "starting"
    ./"$1"
  fi
fi
