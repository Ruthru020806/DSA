#include "header.h"

Manufacturer::Manufacturer()
{
    mname=" ";
    mid=0;
    aircraft_count=0;
}
Manufacturer::Manufacturer(string b,int r,int p)
{
    mname=b;
    mid=r;
    aircraft_count=p;
}
Manufacturer::Manufacturer(const Manufacturer &c)
{
    mname=c.mname;
    mid=c.mid;
    aircraft_count=c.aircraft_count;
}
Manufacturer::~Manufacturer()
{
}
void Manufacturer::GetManufacturer()
{
    cout<<"Enter the Name of the Manufacturer:"<<endl;
    cin>>mname;
    cout<<"Enter the ID of the Manufacturer:"<<endl;
    cin>>mid;
    cout<<"Enter the Aircraft count:"<<endl;
    cin>>aircraft_count;
}
void Manufacturer::DisplayManufacturer()
{
    cout<<mname<<"\t\t"<<mid<<"\t\t"<<aircraft_count<<"\n"<<endl;
}
int Manufacturer:: GetManufacturerId()
{
    return mid;
}
CNode::CNode()
{
    right=left=NULL;
}
CNode::CNode(Manufacturer d)
{
    data=d;
    right=left=NULL;
}
CNode::~CNode()
{
    right=left=NULL;
}
void CNode::Getdata()
{
    data.GetManufacturer();
}
void CNode::Displaydata()
{
    data.DisplayManufacturer();
}

CBST::CBST()
{
   root=NULL;
}
void CBST::FreeTree(CNode* node)
{
    if(node)
    {
        FreeTree(node->left);
        FreeTree(node->right);
        delete node;
    }
}
CBST::~CBST()
{
   FreeTree(root);
   root=NULL;
}
CNode* CBST::Getroot()
{
   return root;
}
void CBST::Setroot(CNode* r)
{
   root=r;
}
bool CBST::Isempty()
{
    return (root == NULL);
}
bool CBST::Insert(CNode *temp, CNode *newNode)
{
    if(Isempty())
    {
        root = newNode;
        return true;
    }
    else
    {
        if(temp->data.mid > newNode->data.mid)
        {
            if(temp->left == NULL)
            {
                temp->left = newNode;
                return true;
            }
            else
                return Insert(temp->left, newNode);
        }
        else if(temp->data.mid < newNode->data.mid)
        {
            if(temp->right == NULL)
            {
                temp->right = newNode;
                return true;
            }
            else
                return Insert(temp->right, newNode);
        }
        else
            return false;
    }
}
void CBST::Inorder(CNode *temp)
{
    if(temp != NULL)
    {
        Inorder(temp->left);
        temp->data.DisplayManufacturer();
        Inorder(temp->right);
    }
}
CNode* CBST::Findmin(CNode* root)
{
    CNode* temp=root;
    while(temp->left !=NULL)
    {
        temp=temp->left;
    }
    return temp;
}
CNode* CBST::Findmax(CNode* root)
{
    CNode* temp=root;
    while(temp->right!=NULL)
    {
        temp=temp->right;
    }
    return temp;
}
CNode* CBST::Search(CNode* temp, int elt)
{
    if(temp==NULL || temp->data.mid == elt)
    {
        return temp;
    }
    else if(temp->data.mid < elt)
    {
        return Search(temp->right, elt);
    }
    else if(temp->data.mid > elt)
    {
        return Search(temp->left, elt);
    }
    else
    {
        return NULL;
    }
}
void CBST::Preorder(CNode* temp)
{
    if(temp != NULL)
    {
        temp->data.DisplayManufacturer();
        Preorder(temp->left);
        Preorder(temp->right);
    }
}
void CBST::Postorder(CNode* temp)
{
    if(temp != NULL)
    {
        Postorder(temp->left);
        Postorder(temp->right);
        temp->data.DisplayManufacturer();
    }
}
CNode* CBST::Deleteelt(CNode* temp, int elt, bool &status)
{
    if (temp == NULL)
    {
        status = false;
        return NULL;
    }
    else if (elt < temp->data.mid)
    {
        temp->left  = Deleteelt(temp->left,  elt, status);
    }
    else if (elt > temp->data.mid)
    {
        temp->right = Deleteelt(temp->right, elt, status);
    }
    else
    {
        if (temp->left == NULL && temp->right == NULL)
        {
            delete temp;
            temp = NULL;
            status = true;
        }
        else if (temp->left == NULL)
        {
            CNode* child = temp->right;
            delete temp;
            temp = child;
            status = true;
        }
        else if (temp->right == NULL)
        {
            CNode* child = temp->left;
            delete temp;
            temp = child;
            status = true;
        }
        else
        {
            CNode* min = Findmin(temp->right);
            temp->data = min->data;
            temp->right = Deleteelt(temp->right, min->data.mid, status);
        }
    }
    return temp;
}
void CBST::makeTreeEmpty(CNode* root)
{
   if (root!=NULL)
   {
      makeTreeEmpty(root->left);
      makeTreeEmpty(root->right);
      delete root;
   }

}
