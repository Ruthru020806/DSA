#include <iostream>
#include <string>
#include <cmath>
#include <limits> // Required for input error handling

using namespace std;

// Hardcode the technique value for QUADRATIC
const int QUADRATIC = 2;
// LINEAR constant removed, as it's not used in this set

class EmployeeData
{
  friend class QuadraticProbingHashTable;
  private:
    int id;
    string name;
    int phone;

  public:
    EmployeeData();
    EmployeeData(int, string, int);
    ~EmployeeData();
    void get();
    void displaydata();
    int getIdValue();
};

class QuadraticProbingHashTable
{
  friend class EmployeeData;
  private:
    int tablesize;
    int size; // Current number of elements
    EmployeeData *table;
    int technique; // This will always be QUADRATIC

  public:
    QuadraticProbingHashTable(int capacity); // Constructor changed
    ~QuadraticProbingHashTable();

    int IsEmpty();
    int IsFull();
    int Display();
    int MakeHashingEmpty();

    int Hash(int key);
    int Probe(int key, int i); // Calculates the probed index

    int Insert(EmployeeData emp);
    int Delete(int key);
    int Search(int key);
};
