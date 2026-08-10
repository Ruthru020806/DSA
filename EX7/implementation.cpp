#include "head.h"


CFManufacturer::CFManufacturer() : name(""), country(""), yoe(0.0f), priority(-1) {}

// Parameterized constructor
CFManufacturer::CFManufacturer(string b, string c, float p, int pr)
    : name(b), country(c), yoe(p), priority(pr) {}

// Copy constructor
CFManufacturer::CFManufacturer(const CFManufacturer &other)
{
    name = other.name;
    country = other.country;
    yoe = other.yoe;
    priority = other.priority;
}

// Displays the data in a formatted way
void CFManufacturer::display() const
{
    cout << name << "\t\t"
         << country << "\t\t"
         << yoe << "\t\t"
         << priority << endl;
}

// Getter for priority
int CFManufacturer::getPriority() const
{
    return priority;
}

// Setter for priority
void CFManufacturer::setPriority(int p)
{
    priority = p;
}


CFManufacturerPriorityQueue::CFManufacturerPriorityQueue()
{
    capacity = 31; // Default capacity
    heapSize = 0;
    heap = new CFManufacturer[capacity + 1]; // +1 for 1-based indexing
}

// Parameterized constructor: creates a heap based on tree height
CFManufacturerPriorityQueue::CFManufacturerPriorityQueue(int height)
{
    capacity = pow(2, (height + 1)) - 1;
    heapSize = 0;
    heap = new CFManufacturer[capacity + 1];
}

// Destructor: frees the dynamically allocated memory for the heap
CFManufacturerPriorityQueue::~CFManufacturerPriorityQueue()
{
    delete[] heap;
}

int CFManufacturerPriorityQueue::insert(CFManufacturer item)
{
    if (isFull())
    {
        cout << "Error: Priority queue is full." << endl;
        return -1;
    }
    heapSize++;
    int index = percolateUp(heapSize, item);
    heap[index] = item;
    return 1;
}

int CFManufacturerPriorityQueue::deleteMin()
{
    if (isEmpty())
    {
        return -1;
    }

    heap[1] = heap[heapSize--];

    if (!isEmpty())
    {
        percolateDown(1);
    }

    return 1;
}

CFManufacturer CFManufacturerPriorityQueue::returnMin()
{
    if (isEmpty())
    {
        return CFManufacturer();
    }
    return heap[1];
}

void CFManufacturerPriorityQueue::displayFManufacturer()
{
    if (isEmpty())
    {
        cout << "No Manufacturer in the queue.\n";
        return;
    }

    cout << "Name\t\tCountry\t\tYear Of Establishment\t\tPriority\n";
    cout << "----------------------------------------------------------\n";

    for (int i = 1; i <= heapSize; i++)
    {
        heap[i].display();
    }
}


int CFManufacturerPriorityQueue::percolateUp(int index, CFManufacturer item)
{
    while (index > 1 && heap[index / 2].getPriority() > item.getPriority())
    {
        heap[index] = heap[index / 2];
        index /= 2;
    }
    return index;
}

// Moves an item down the heap to its correct position.
void CFManufacturerPriorityQueue::percolateDown(int index)
{
    int child;
    CFManufacturer tmp = heap[index];

    for (; index * 2 <= heapSize; index = child)
    {
        child = index * 2;
        if (child != heapSize && heap[child + 1].getPriority() < heap[child].getPriority())
        {
            child++;
        }
        if (heap[child].getPriority() < tmp.getPriority())
        {
            heap[index] = heap[child];
        }
        else
        {
            break;
        }
    }
    heap[index] = tmp;
}

// Increase key by a given amount
int CFManufacturerPriorityQueue::increaseKeyBy(int index, int amount)
{
    if (index < 1 || index > heapSize || amount <= 0) return -1;
    int newPriority = heap[index].getPriority() + amount;
    return increaseKeyWith(index, newPriority);
}

// Increase key to a specific new value
int CFManufacturerPriorityQueue::increaseKeyWith(int index, int newPriority)
{
    if (index < 1 || index > heapSize || newPriority < heap[index].getPriority())
    {
        return -1;
    }
    heap[index].setPriority(newPriority);
    percolateDown(index);
    return 1;
}

// Decrease key by a given amount
int CFManufacturerPriorityQueue::decreaseKeyBy(int index, int amount)
{
    if (index < 1 || index > heapSize || amount <= 0) return -1;
    int newPriority = heap[index].getPriority() - amount;
    return decreaseKeyWith(index, newPriority);
}

// Decrease key to a specific new value
int CFManufacturerPriorityQueue::decreaseKeyWith(int index, int newPriority)
{
    if (index < 1 || index > heapSize || newPriority > heap[index].getPriority())
    {
        return -1;
    }
    CFManufacturer item = heap[index];
    item.setPriority(newPriority);
    int newIndex = percolateUp(index, item);
    heap[newIndex] = item;
    return 1;
}

// Build heap from existing items
int CFManufacturerPriorityQueue::buildHeap(CFManufacturer* items, int size)
{
    if (size > capacity)
    {
        return -1;
    }

    for (int i = 0; i < size; i++)
    {
        heap[i + 1] = items[i];
    }

    heapSize = size;

    for (int i = heapSize / 2; i > 0; i--)
    {
        percolateDown(i);
    }

    return 1;
}

int CFManufacturerPriorityQueue::isFull() const
{
    return heapSize == capacity;
}

int CFManufacturerPriorityQueue::isEmpty() const
{
    return heapSize == 0;
}
