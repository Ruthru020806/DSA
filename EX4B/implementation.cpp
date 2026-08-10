#include "header.h"
#include <iostream>

CFlightManufacturer::CFlightManufacturer()
{
    name = "";
    type = "";
    aircraftcount = 0;
}

CFlightManufacturer::CFlightManufacturer(string n, string t, int d)
{
    name = n;
    type = t;
    aircraftcount = d;
}

CFlightManufacturer::~CFlightManufacturer() {}

void CFlightManufacturer::displayFlightManufacturer()
{
    cout << name<<"\t"<<type<<"\t"<<aircraftcount<<endl;
}

CAQueue::CAQueue()
{
    front = rear = -1;
    capacity = 5;
    queueArr = new CFlightManufacturer[capacity];
}

CAQueue::CAQueue(int c)
{
    front = rear = -1;
    capacity = c;
    queueArr = new CFlightManufacturer[capacity];
}

CAQueue::~CAQueue()
{
    delete[] queueArr;
    front = rear = -1;
    capacity = 0;
}

int CAQueue::enqueue(CFlightManufacturer ds)
{
    if (isFull()) { return -1; }

    if (isEmpty())
    {
        front = rear = 0;
        queueArr[rear] = ds;
        return 1;
    }
    else
    {
        rear = (rear + 1) % capacity;
        queueArr[rear] = ds;
        return 2;
    }
}

int CAQueue::dequeue()
{
    if (isEmpty()) { return -1; }

    if (front == rear)
    {
        queueArr[front] = CFlightManufacturer();
        front = rear = -1;
        return 1;
    }
    else
    {
        queueArr[front] = CFlightManufacturer();
        front = (front + 1) % capacity;
        return 2;
    }
}

int CAQueue::displayFront()
{
    if (isEmpty()) { return -1; }
    queueArr[front].displayFlightManufacturer();
    return 1;
}

int CAQueue::displayRear()
{
    if (isEmpty()) { return -1; }
    queueArr[rear].displayFlightManufacturer();
    return 1;
}

int CAQueue::makeQueueEmpty()
{
    if (isEmpty()) { return -1; }
    front = rear = -1;
    return 1;
}

int CAQueue::isEmpty()
{
    return (front == -1 && rear == -1);
}

int CAQueue::isFull()
{
    return ((rear + 1) % capacity == front);
}

int CAQueue::displayQueue()
{
    if (isEmpty()) { return -1; }
    cout<<"\n==========Flight Manufacturer Details====================\n";
    int i = front;
    cout<<"Name  |  Type  |  Aircraft Count\n";
    while (true)
    {
        queueArr[i].displayFlightManufacturer();
        if (i == rear) break;
        i = (i + 1) % capacity;
    }
    cout<<"\n===========================================================\n";
    return 2;
}
