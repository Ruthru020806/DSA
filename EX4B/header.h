#include <string>
using namespace std;

class CFlightManufacturer
{
public:
    CFlightManufacturer();
    CFlightManufacturer(string, string, int);
    ~CFlightManufacturer();

    void displayFlightManufacturer();

private:
    string name;
    string type;
    int aircraftcount;
};

class CAQueue
{
public:
    CAQueue();
    CAQueue(int);
    ~CAQueue();

    int enqueue(CFlightManufacturer);
    int dequeue();
    int displayFront();
    int displayRear();
    int makeQueueEmpty();
    int isFull();
    int isEmpty();
    int displayQueue();

private:
    int front, rear, capacity;
    CFlightManufacturer* queueArr;
};
