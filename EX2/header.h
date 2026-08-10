#include <iostream>
#include <string>
using namespace std;

class FlightManufacturer
{
    friend class FNode;
private:
    string manufacturer;
    int modelNumber;
    string aircraftType;
    int capacity;
    string engine;

public:
    FlightManufacturer();
    FlightManufacturer(string, int, string, int, string);
    void displayData();

    string getManufacturer() const { return manufacturer; }
    int getModelNumber() const { return modelNumber; }
    string getAircraftType() const { return aircraftType; }
    int getCapacity() const { return capacity; }
    string getEngine() const { return engine; }

    void setManufacturer(string name) { manufacturer = name; }
    void setModelNumber(int number) { modelNumber = number; }
    void setAircraftType(string type) { aircraftType = type; }
    void setCapacity(int cap) { capacity = cap; }
    void setEngine(string engine) { engine = engine; }
};

class FNode {
    friend class FList;

private:
    FlightManufacturer data;
    FNode* next;

public:
    FNode();
    FNode(FlightManufacturer d, FNode* n = NULL);
};

class FList {
    friend class FlightManufacturer;

private:
    FNode* first;

public:
    FList();
    int isEmpty();
    int insertAtFirst(FlightManufacturer);
    int insertAtLast(FlightManufacturer);
    int insertAtPosition(int, FlightManufacturer);
    int deleteAtFirst();
    int deleteAtLast();
    int deleteByManufacturer(string);
    int deleteByPosition(int);
    int updateCapacity(string, int);
    int searchByAircraftType(string);
    int reverse();
    void display();
    int makeListEmpty();
};
