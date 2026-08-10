#include "header1.h"

// --- EmployeeData Implementation ---
EmployeeData::EmployeeData() : id(-1), name(""), phone(-1) {}
EmployeeData::EmployeeData(int d, string n, int e) : id(d), name(n), phone(e) {}
EmployeeData::~EmployeeData() {}

void EmployeeData::get()
{
  cout << "Enter Employee ID, Name, Phone No : ";
  cin >> id >> name >> phone;
}

void EmployeeData::displaydata()
{
    if (id == -1) cout << "[SLOT EMPTY]" << endl;
    else if (id == -2) cout << "[SLOT DELETED/TOMBSTONE]" << endl;
    else {
        cout << "Employee ID: " << id << endl;
        cout << "Employee Name: " << name << endl;
        cout << "Employee Phone NO: " << phone << endl;
    }
}
int EmployeeData::getIdValue() { return id; }

// --- LinearProbingHashTable Implementation ---
LinearProbingHashTable::LinearProbingHashTable(int capacity)
{
  tablesize = capacity;
  size = 0;
  technique = LINEAR; // Always linear
  table = new EmployeeData[capacity];
  for (int i = 0; i < tablesize; i++) table[i] = EmployeeData();
}

LinearProbingHashTable::~LinearProbingHashTable()
{
  delete[] table;
}

int LinearProbingHashTable::IsEmpty() { return size == 0 ? 1 : 0; }
int LinearProbingHashTable::IsFull() { return tablesize == size ? 1 : 0; }

int LinearProbingHashTable::Display()
{
 if (IsEmpty()) return 1;
 cout << "\n--- Hash Table Contents (Linear Probing) ---\n";
 for(int i=0; i<tablesize; i++) {
  cout << "[" << i << "]: ";
  table[i].displaydata();
 }
 cout << "Current Elements: " << size << "/" << tablesize << "\n";
 cout << "------------------------------------------\n";
 return 0;
}

int LinearProbingHashTable::MakeHashingEmpty()
{
 if (IsEmpty()) return 1;
 for (int i = 0; i < tablesize; ++i) table[i] = EmployeeData();
 size = 0;
 return 0;
}

int LinearProbingHashTable::Hash(int k) { return (k % tablesize); }

// Only Linear Probing calculation
int LinearProbingHashTable::Probe(int key, int i)
{
    int bucketID = (Hash(key) + i) % tablesize;
    if (bucketID < 0) bucketID += tablesize;
    return bucketID;
}

int LinearProbingHashTable::Insert(EmployeeData emp)
{
  if (IsFull()) return 1;
  if (emp.id <= 0 && emp.id != -1 && emp.id != -2) return -3;
  int i, bucketID;
  for(i = 0; i < tablesize; i++)
  {
    bucketID = Probe(emp.id, i);
    if(table[bucketID].id == -1 || table[bucketID].id == -2) {
      table[bucketID] = emp;
      size++;
      return 0;
    }
    if(table[bucketID].id == emp.id) return -2;
  }
  return -1;
}

int LinearProbingHashTable::Delete(int k)
{
  if (IsEmpty()) return 1;
  int i, bucketID;
  for(i = 0; i < tablesize; i++)
  {
    bucketID = Probe(k, i);
    if(table[bucketID].id == k) {
      table[bucketID].id = -2;
      table[bucketID].name = "[DEL]";
      table[bucketID].phone = 0;
      size--;
      return 0;
    }
    if(table[bucketID].id == -1) return -1;
  }
  return -1;
}

int LinearProbingHashTable::Search(int k)
{
  if (IsEmpty()) return 1;
  int i, bucketID;
  for(i = 0; i < tablesize; i++)
  {
    bucketID = Probe(k, i);
    if(table[bucketID].id == k) {
      table[bucketID].displaydata();
      return 0;
    }
    if(table[bucketID].id == -1) return -1;
  }
  return -1;
}
