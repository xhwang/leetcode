UNAME := $(shell uname)

ifeq ($(UNAME), Linux)
CXX = g++
else
CXX = clang++
endif

CXXFLAGS=-g -Wall -std=c++11

NAME=tree

all: $(NAME).o
	$(CXX) -o demo $(NAME).o

$(NAME).o: $(NAME).cpp
	$(CXX) $(CXXFLAGS) -c $(NAME).cpp

clean:
	rm -rf *.o demo
