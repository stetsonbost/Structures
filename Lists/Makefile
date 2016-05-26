CXX = clang++
CXXFLAGS = -g -std=c++11 -pedantic -Wall -Wextra
OBJECTS = LinkedList.o

testAllMatrices: LinkedList.cc $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o testLL LinkedList.cc $(OBJECTS)

LinkedList.o: LinkedList.h LinkedList-private.h
	$(CXX) $(CXXFLAGS) -c LinkedList.cc

clean:
	rm -rf *.o testLL