
CXX=g++
CXXFLAGS=-g -Wall -std=c++11

all: two_sum.o
	$(CXX) -o demo two_sum.o

two_sum.o: two_sum.cpp
	$(CXX) $(CXXFLAGS) -c two_sum.cpp

clean:
	rm -rf *.o demo
