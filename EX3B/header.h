#include<iostream>
#include <string>
using namespace std;

class Node;
class Stack;

class Aircraft_data
{
private:
    string manufacturer;
    string model;
    int engineCount;
    int seatingCapacity;
    float cost;

public:
    Aircraft_data(){}
    Aircraft_data(string mfr, string mdl, int eng, int seat, float c)
    {
        manufacturer = mfr;
        model = mdl;
        engineCount = eng;
        seatingCapacity = seat;
        cost = c;
    }

    string getManufacturer()
    {
       return manufacturer;
    }
    string getModel()
    {
       return model;
    }
    int getEngineCount()
    {
       return engineCount;
    }
    int getSeatingCapacity()
    {
       return seatingCapacity;
    }
    float getCost()
    {
       return cost;
    }

    friend class Node;
    friend class Stack;
};

class Node
{
private:
    Aircraft_data data;
    Node* next;

public:
    Node(Aircraft_data a)
    {
        data = a;
        next = NULL;
    }

    friend class Stack;
};

class Stack
{
private:
    Node* top;
    int count;

public:
    Stack();
    int push(Aircraft_data a);
    int pop();
    int peek(Aircraft_data &a);
    int makeStackEmpty();
    int display_stack();
    int isEmpty();
    int size();
};
