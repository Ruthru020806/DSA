#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class CFlightManufacturer
{
private:
    int mid;
    string mname;
    string country;
    double yoe;

public:

    CFlightManufacturer();


    CFlightManufacturer(int i, string n, string d, double s);


    CFlightManufacturer(const CFlightManufacturer &other);


    void display() const;


    int getID() const;
};


class CNode
{
public:
    CFlightManufacturer data;
    CNode *left;
    CNode *right;
    int height;


    CNode();

    CNode(const CFlightManufacturer &m);

    void displayNode() const;
};

class CAVL
{
private:
    CNode *root;

public:

    CAVL();


    CNode* getRoot();
    void setRoot(CNode* node);


    int getHeight(CNode* node);
    int getBalanceFactor(CNode* node);
    CNode* rightRotate(CNode* y);
    CNode* leftRotate(CNode* x);
    CNode* insertNode(CNode* node, CNode* newNode);
    CNode* deleteNode(CNode* node, int key);


    void inOrder(CNode* node);
    void preOrder(CNode* node);
    void postOrder(CNode* node);
    CNode* search(CNode* node, int key);


    CNode* findMin(CNode* node);
    CNode* findMax(CNode* node);
};
