#include <iostream>
#include <string>
#include <cmath>

using namespace std;

// Forward declaration of the priority queue class
class CFManufacturerPriorityQueue;

// Class to hold the data for each mobile phone in the queue
class CFManufacturer
{
    friend class  CFManufacturerPriorityQueue;

private:
    string name;
    string country;
    float yoe;
    int priority;

public:
    // Constructors
    CFManufacturer();
    CFManufacturer(string name, string country, float yoe, int priority);
    CFManufacturer(const  CFManufacturer &other);

    // Member functions
    void display() const;       // Display details
    int getPriority() const;    // Getter for priority
    void setPriority(int p);    // Setter for priority
};

// A Min-Heap implementation of a Priority Queue for Mobile Phones
class CFManufacturerPriorityQueue
{
private:
    CFManufacturer *heap;  // Array to represent the heap
    int capacity;   // Maximum heap size
    int heapSize;   // Current number of elements

    // Helper functions
    int percolateUp(int index, CFManufacturer item);
    void percolateDown(int index);

public:
    // Constructors and Destructor
    CFManufacturerPriorityQueue();
    CFManufacturerPriorityQueue(int height);
    ~CFManufacturerPriorityQueue();

    // Core operations
    int insert(CFManufacturer item);
    int deleteMin();
    CFManufacturer returnMin();
    void displayFManufacturer();

    // Key manipulation functions
    int increaseKeyBy(int index, int amount);
    int increaseKeyWith(int index, int newPriority);
    int decreaseKeyBy(int index, int amount);
    int decreaseKeyWith(int index, int newPriority);

    // Utility functions
    int buildHeap(CFManufacturer* items, int size);
    int isFull() const;
    int isEmpty() const;
};
