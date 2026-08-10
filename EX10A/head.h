#include <iostream>
using namespace std;

class CFManufacturer
{
    friend class CNode;
private:
    string mname;
    int mid;
    long yoe;

public:
    CFManufacturer();
    ~CFManufacturer();
    void getManufacturer();
    void displayManufacturer();
    int getID();
};

class CNode
{
    friend class Hashtable;
private:
    CFManufacturer data;
    CNode *next;

public:
    CNode();
    ~CNode();
    CNode(CFManufacturer, CNode *);
    void getNode();
    void displayNode();
};

class Hashtable
{
private:
    int size;
    CNode **Harr;

public:
    Hashtable();
    Hashtable(int);
    ~Hashtable();
    int hashFunc(int);
    bool insertFirst(CNode *, int);
    int deleteBymid(int, int);
    CFManufacturer search(int, int);
    void displayRow(int);
    void displayTable();
};
