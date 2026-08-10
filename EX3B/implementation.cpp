#include "header.h"

Stack::Stack()
{
    top = NULL;
    count = 0;
}

int Stack::push(Aircraft_data a)
{
    Node* newNode = new Node(a);
    if (!newNode)
    {
       return -1;
    }
    if (isEmpty() == 1)
    {
        top = newNode;
        count++;
        return 1;
    }
    else
    {
        newNode->next = top;
        top = newNode;
        count++;
        return 2;
    }
}

int Stack::pop()
{
    if (isEmpty() == 1)
    {
       return 1;
    }
    Node* temp = top;
    cout << "\n\t\t-----Popped STACK DETAILS-----\n";
    cout << "Manufacturer\t|\tModel\t|\tEngines\t|\tSeating\t|\tCost\n";
    cout << "--------------------------------------------------------------------------\n";
    cout << temp->data.manufacturer << "\t|\t"
         << temp->data.model << "\t|\t"
         << temp->data.engineCount << "\t|\t"
         << temp->data.seatingCapacity << "\t|\t"
         << temp->data.cost << endl;
    top = top->next;
    delete temp;
    count--;
    return 2;
}

int Stack::peek(Aircraft_data &a)
{
    if (isEmpty() == 1)
       return 1;
    a = top->data;
    return 2;
}

int Stack::makeStackEmpty()
{
    while(!isEmpty())
    {
       pop();
    }
}
int Stack::display_stack()
{
    if (isEmpty() == 1)
    {
        cout << "Stack is empty.\n";
        return 1;
    }

    Node* temp = top;
    cout << "\n\t\t-----AIRCRAFT STACK DETAILS-----\n";
    cout << "Manufacturer\t|\tModel\t|\tEngines\t|\tSeating\t|\tCost\n";
    cout << "--------------------------------------------------------------------------\n";

    while (temp != NULL)
    {
        cout << temp->data.manufacturer << "\t|\t"
             << temp->data.model << "\t|\t"
             << temp->data.engineCount << "\t|\t"
             << temp->data.seatingCapacity << "\t|\t"
             << temp->data.cost << endl;
        temp = temp->next;
    }

    return 2;
}

int Stack::isEmpty()
{
    return (top == NULL) ? 1 : 2;
}

int Stack::size()
{
    return count;
}
