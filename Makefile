.PHONY: default all clean

CC=clang
CFLAGS=-std=c99 -Wall -O2

CXX=clang++
CXXFLAGS=-std=c++14 -Wall -O2

CXX_SRC=$(wildcard *.cpp)

default: all

clean:
	$(RM) *.o
