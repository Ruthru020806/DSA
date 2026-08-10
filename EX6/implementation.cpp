#include "header.h"

CFlightManufacturer::CFlightManufacturer() : mid(0), mname(""), country(""), yoe(0.0) {}

CFlightManufacturer::CFlightManufacturer(int i, string n, string d, double s) : mid(i), mname(n), country(d), yoe(s) {}

CFlightManufacturer::CFlightManufacturer(const CFlightManufacturer &other)
{
    mid = other.mid;
    mname = other.mname;
    country = other.country;
    yoe = other.yoe;
}

void CFlightManufacturer::display() const
{
    cout << mid << "\t\t" << mname << "\t\t" << country<< "\t\t" << yoe << endl;
}

int CFlightManufacturer::getID() const
{
    return mid;
}

CNode::CNode() : left(NULL), right(NULL), height(0) {}

CNode::CNode(const CFlightManufacturer &m) : data(m), left(NULL), right(NULL), height(1) {}

void CNode::displayNode() const
{
    data.display();
}


CAVL::CAVL() : root(NULL) {}

CNode* CAVL::getRoot() { return root; }
void CAVL::setRoot(CNode* node) { root = node; }

int CAVL::getHeight(CNode* node)
{
    if (node == NULL)
        return 0;
    return node->height;
}

int CAVL::getBalanceFactor(CNode* node)
{
    if (node == NULL)
        return 0;
    return getHeight(node->left) - getHeight(node->right);
}

CNode* CAVL::rightRotate(CNode* y)
{
    CNode* x = y->left;
    CNode* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    return x;
}

CNode* CAVL::leftRotate(CNode* x)
{
    CNode* y = x->right;
    CNode* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    return y;
}

CNode* CAVL::insertNode(CNode* node, CNode* newNode)
{

    if (node == NULL)
        return newNode;

    if (newNode->data.getID() < node->data.getID())
        node->left = insertNode(node->left, newNode);
    else if (newNode->data.getID() > node->data.getID())
        node->right = insertNode(node->right, newNode);
    else
        return node;

    node->height = 1 + max(getHeight(node->left), getHeight(node->right));

    int balance = getBalanceFactor(node);

    if (balance > 1 && newNode->data.getID() < node->left->data.getID())
    {
        cout << "--> Performed Right Rotation (LL Case) on node " << node->data.getID() << endl;
        return rightRotate(node);
    }

    if (balance < -1 && newNode->data.getID() > node->right->data.getID())
    {
        cout << "--> Performed Left Rotation (RR Case) on node " << node->data.getID() << endl;
        return leftRotate(node);
    }

    if (balance > 1 && newNode->data.getID() > node->left->data.getID())
    {
        cout << "--> Performed Left-Right Rotation (LR Case) on node " << node->data.getID() << endl;
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && newNode->data.getID() < node->right->data.getID())
    {
        cout << "--> Performed Right-Left Rotation (RL Case) on node " << node->data.getID() << endl;
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }


    return node;
}

CNode* CAVL::findMin(CNode* node)
{
    if (node == NULL) return NULL;
    while (node->left != NULL)
        node = node->left;
    return node;
}

CNode* CAVL::findMax(CNode* node)
{
    if (node == NULL) return NULL;
    while (node->right != NULL)
        node = node->right;
    return node;
}

CNode* CAVL::deleteNode(CNode* node, int key)
{
    if (node == NULL)
        return node;

    if (key < node->data.getID())
        node->left = deleteNode(node->left, key);
    else if (key > node->data.getID())
        node->right = deleteNode(node->right, key);
    else
    {

        if ((node->left == NULL) || (node->right == NULL))
        {
            CNode* temp = node->left ? node->left : node->right;

            if (temp == NULL)
            {
                temp = node;
                node = NULL;
            }
            else
                *node = *temp;
            delete temp;
        }
        else
        {

            CNode* temp = findMin(node->right);

            node->data = temp->data;

            node->right = deleteNode(node->right, temp->data.getID());
        }
    }

    if (node == NULL)
        return node;

    node->height = 1 + max(getHeight(node->left), getHeight(node->right));
    int balance = getBalanceFactor(node);


    if (balance > 1 && getBalanceFactor(node->left) >= 0)
        return rightRotate(node);

    if (balance > 1 && getBalanceFactor(node->left) < 0)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && getBalanceFactor(node->right) <= 0)
        return leftRotate(node);

    if (balance < -1 && getBalanceFactor(node->right) > 0)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

void CAVL::inOrder(CNode* node)
{
    if (node != NULL)
    {
        inOrder(node->left);
        node->displayNode();
        inOrder(node->right);
    }
}

void CAVL::preOrder(CNode* node)
{
    if (node != NULL)
    {
        node->displayNode();
        preOrder(node->left);
        preOrder(node->right);
    }
}

void CAVL::postOrder(CNode* node)
{
    if (node != NULL)
    {
        postOrder(node->left);
        postOrder(node->right);
        node->displayNode();
    }
}

CNode* CAVL::search(CNode* node, int key)
{
    if (node == NULL || node->data.getID() == key)
        return node;

    if (node->data.getID() < key)
        return search(node->right, key);

    return search(node->left, key);
}
