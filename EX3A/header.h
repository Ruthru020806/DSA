#include <iostream>
#include <string>
using namespace std;

class FlightManufacturerData
{
private:
    string manufacturerName;
    int manufacturerId;
    string country;
    int aircraftCount;
    string aircraftType;

public:
    FlightManufacturerData();
    FlightManufacturerData(string, int, string, int, string);
    void displaydat();

    string getManufacturerName()
    {
        return manufacturerName;
    }
    int getManufacturerId()
    {
        return manufacturerId;
    }
    string getCountry()
    {
        return country;
    }
    int getAircraftCount()
    {
        return aircraftCount;
    }
    string getAircraftType()
    {
        return aircraftType;
    }
};

class Stack
{
private:
    FlightManufacturerData* arr;
    int capacity;
    int top;

public:
    Stack(int);
    bool isEmpty();
    bool isFull();
    int push(FlightManufacturerData);
    int pop();
    //int updateAircraftCount(string, int);
    //int searchByManufacturerName(string);
    void display();
    FlightManufacturerData peek();
    void makeEmpty();
};
