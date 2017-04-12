.PHONY: all

CXX=clang++
CXXFLAGS=-std=c++14 -Wall 

CXX_SRC=*.cpp

default: all

all: $(CXX_SRC)

clean:
