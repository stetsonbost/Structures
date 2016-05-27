CXX = clang++
CXXFLAGS = -g -std=c++11 -pedantic -Wall -Wextra
OBJECTS = LinkedList.o

LinkedList: LinkedList.cc $(OBJECTS)
	$(CXX) $(CXXFLAGS) -c LinkedList.cc -o LinkedList.o
#	$(CXX) $(CXXFLAGS) -o testLL LinkedList.cc $(OBJECTS)

header: LinkedList.h LinkedList-private.h
	$(CXX) $(CXXFLAGS) LinkedList.h

LinkedList.o: LinkedList.h LinkedList-private.h
	$(CXX) $(CXXFLAGS) -c LinkedList.cc

clean:
	rm -rf *.o *.gch # testLL