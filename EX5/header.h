#include<iostream>
using namespace std;

class CNode;
class CBST;

class Manufacturer
{
    friend class CBST;
private:
    string mname;
    int mid;
    int aircraft_count;
public:
    Manufacturer();
    Manufacturer(string,int,int);
    Manufacturer(const Manufacturer &);
    ~Manufacturer();
    void GetManufacturer();
    void DisplayManufacturer();
    int GetManufacturerId();
};

class CNode
{
    friend class CBST;
private:
    Manufacturer data;
    CNode *left;
    CNode *right;
public:
    CNode();
    CNode(Manufacturer);
    ~CNode();
    void Getdata();
    void Displaydata();
};

class CBST
{
private:
    CNode *root;
    void FreeTree(CNode* node);
public:
    CBST();
    ~CBST();
    CNode* Getroot();
    void Setroot(CNode *r);
    bool Isempty();
    bool Insert(CNode *,CNode *);
    void Inorder(CNode*);
    CNode* Findmin(CNode*);
    CNode* Findmax(CNode*);
    CNode* Search(CNode*,int);
    void Preorder(CNode*);
    void Postorder(CNode*);
    CNode* Deleteelt(CNode*,int,bool&);
    void makeTreeEmpty(CNode* );
};
