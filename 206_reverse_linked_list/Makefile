
CXX=g++
CXXFLAGS=-g -O0 -Wall -std=c++11

all: demo.o
	$(CXX) -o demo demo.o

demo.o: demo.cpp
	$(CXX) $(CXXFLAGS) -c demo.cpp

clean:
	rm -rf *.o demo
