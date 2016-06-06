CXX = clang++
CXXFLAGS = -g -std=c++11 -pedantic -Wall -Wextra
OBJECTS = Heap.o

Heap: Heap.cc $(OBJECTS)
	$(CXX) $(CXXFLAGS) -c Heap.cc -o Heap.o
#	$(CXX) $(CXXFLAGS) -o testHeap Heap.cc $(OBJECTS)

header: Heap.h Heap-private.h
	$(CXX) $(CXXFLAGS) Heap.h

Heap.o: Heap.h Heap-private.h
	$(CXX) $(CXXFLAGS) -c Heap.cc

clean:
	rm -rf *.o *.gch # testHeap