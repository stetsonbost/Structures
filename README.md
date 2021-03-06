# Lots-O-Structures!

For this project, I am implementing some of the data structures I have learned about from CS70 at HMC and Robert Sedgewick's *Algorithms in C++, Parts 1-4*.
I am starting this project in C++, but I may eventually work with different languages.
This project is only meant as my own personal exercise; I make no guarantee that the structures have been correctly, elegantly or efficiently implemented, but I'll try my best for all those.
Alas, I don't like writing tests, so I'm already behind on testing the containers. C'est la vie...

Every container will be templated on the type of elements it stores, but some containers may be more suitable for certain types of data. 
For example, the median heap makes most sense as a container for numbers, especially since it will require arithmetic computations in some instances. 
Additionally, all containers with some sort of order will probably require the type to support the `<` and `>` operators (as well as `==`).

For each structure, I want to be able to add elements, delete elements, and find elements, as well as other functionality that may depend on the type of container.
As a secondary goal, I want to maintain neat, consistent coding style throughout this project, as was enforced in CS70; this means adhering to the [Google C++ Style Guide](https://google.github.io/styleguide/cppguide.html) (more or less).

So far, I've worked on the following data structures:
  * Trees:
    * Basic BST (Unbalanced) - *implemented, untested*
  * Doubly-Linked List - *implemented, untested*
  * Heaps:
    * Max Heap - *implemented, untested*
    * Min Heap - *implemented, untested*
    * Median Heap - *in progress, [exciting!](https://github.com/stetsonbost/Structures/issues/6)*

I'm planning on implementing the following data structures, although not necessarily in the order listed here:
  * Hash Tables with the following collision resolution strategies:
    * Separate Chaining
    * Linear Probing
    * Quadratic Probing
    * Double Hashing
    * Cuckoo Hashing
  * Trees:
    * Random BST
    * Randomized BST
    * Splay BST
    * AVL BST
    * 2-3-4 Tree
    * Red-Black BST
  * Queues:
    * Normal (FIFO) queue
    * Steque
    * Deque
  * Stack
  * "Chunky" Container
  * Hexagonal Grid
  * Matrices
  * Bloom Filter
  * Skip list

These lists will change over time as I implement and learn about more data structures.
