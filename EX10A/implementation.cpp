#include "head.h"
CFManufacturer::CFManufacturer()
{
    mname = "";
    mid = 0;
    yoe = 0;
}

CFManufacturer::~CFManufacturer()
{
    mname = "";
    mid = 0;
    yoe = 0;
}

void CFManufacturer::getManufacturer()
{
    cout << "Enter the Manufacturer Name:" << endl;
    cin >> mname;
    cout << "Enter the MAnufacturer ID:" << endl;
    cin >> mid;
    cout << "Enter the Year of Establishment:" << endl;
    cin >> yoe;
}

void CFManufacturer::displayManufacturer()
{
    cout << "Manufacturer Name:" << mname << "\t"
         << "Manufacturer ID:" << mid << "\t"
         << "Year of Establishment:" << yoe << "\n"
         << endl;
}

int CFManufacturer::getID()
{
    return mid;
}

CNode::CNode()
{
    next = NULL;
}

CNode::~CNode()
{
    next = NULL;
}

CNode::CNode(CFManufacturer d, CNode *n)
{
    data = d;
    next = n;
}

void CNode::getNode()
{
    data.getManufacturer();
}

void CNode::displayNode()
{
    data.displayManufacturer();
}

Hashtable::Hashtable()
{
    size = 0;
    Harr = new CNode *[size];
}

Hashtable::~Hashtable()
{
    size = 0;
    delete[] Harr;
    Harr = NULL;
}

Hashtable::Hashtable(int n)
{
    size = n;
    Harr = new CNode *[size];
    for (int i = 0; i < size; i++)
    {
        Harr[i] = NULL;
    }
}

int Hashtable::hashFunc(int num)
{
    return (num % size);
}

bool Hashtable::insertFirst(CNode *newNode, int bucketNo)
{
    CNode *temp = Harr[bucketNo];
    if (temp == NULL)
    {
        Harr[bucketNo] = newNode;
        return true;
    }
    else
    {
        CNode *headNode = Harr[bucketNo];
        newNode->next = headNode;
        Harr[bucketNo] = newNode;
        return true;
    }
}

int Hashtable::deleteBymid(int mid, int bucketNo)
{
    CNode *temp = Harr[bucketNo];
    if (temp == NULL)
    {
        return -1; // Empty bucket
    }
    else
    {
        CNode *prev = NULL;
        while (temp != NULL && temp->data.getID() != mid)
        {
            prev = temp;
            temp = temp->next;
        }
        if (temp == NULL)
        {
            return -2; // Not found
        }
        if (prev == NULL)
        {
            Harr[bucketNo] = temp->next;
            return 1;
        }
        prev->next = temp->next;
        delete temp;
        temp = NULL;
        return 1;
    }
}
CFManufacturer Hashtable::search(int mid, int bucketNo)
{
    CNode *temp = Harr[bucketNo];
    if (temp == NULL)
    {
        return CFManufacturer();
    }
    else
    {
        while (temp != NULL && temp->data.getID() != mid)
        {
            temp = temp->next;
        }
        if (temp == NULL)
        {
            return CFManufacturer();
        }
        return temp->data;
    }
}

void Hashtable::displayRow(int bucketNo)
{
    CNode *temp = Harr[bucketNo];
    if (temp == NULL)
    {
        cout << "\nTHE BUCKET " << bucketNo << " IS EMPTY !\n\n";
    }
    else
    {
        cout << "\n-----Manufacturer DETAILS IN THE ROW:" << bucketNo << "-----" << endl;
        cout << "----------------------------------------------------\n";
        while (temp != NULL)
        {
            temp->displayNode();
            temp = temp->next;
        }
    }
}


void Hashtable::displayTable()
{
    for (int i = 0; i < size; i++)
    {
        if (Harr[i] == NULL)
        {
            cout << "BUCKET:::" << "|" << i << "|" << ":::" << "EMPTY" << "\n\n";
        }
        else
        {
            displayRow(i);
        }
    }
}
