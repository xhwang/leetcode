
CXX=g++
CXXFLAGS=-g -Wall -std=c++11

NAME=longest_substring

all: $(NAME).o
	$(CXX) -o demo $(NAME).o

$(NAME).o: $(NAME).cpp
	$(CXX) $(CXXFLAGS) -c $(NAME).cpp

clean:
	rm -rf *.o demo
