#include "header.h"
FlightManufacturer::FlightManufacturer()
{
    manufacturer = "";
    modelNumber = 0;
    aircraftType = "";
    capacity = 0;
    engine = "";
}

FlightManufacturer::FlightManufacturer(string m, int num, string type, int cap, string e)
{
    manufacturer = m;
    modelNumber = num;
    aircraftType = type;
    capacity = cap;
    engine = e;
}

void FlightManufacturer::displayData()
{
    cout << manufacturer << "\t|\t" << modelNumber << "\t|\t" << aircraftType << "\t|\t" << capacity << "\t|\t" << engine << endl;
}

FNode::FNode()
{
    next = NULL;
}

FNode::FNode(FlightManufacturer d, FNode* n)
{
    data = d;
    next = n;
}

FList::FList()
{
    first = NULL;
}

int FList::isEmpty()
{
    return (first == NULL) ? 1 : 0;
}

int FList::insertAtFirst(FlightManufacturer f)
{
    FNode* newNode = new FNode(f, NULL);
    if (isEmpty())
    {
        first = newNode;
        return 1;
    }
    else if (newNode == NULL)
    {
        return 2;
    }
    else
    {
        newNode->next = first;
        first = newNode;
        return 3;
    }
}

int FList::insertAtLast(FlightManufacturer f)
{
    FNode* newNode = new FNode(f, NULL);
    if (isEmpty())
    {
        first = newNode;
        return 1;
    }
    else if (newNode == NULL)
    {
        return 2;
    }
    else
    {
        FNode* temp = first;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
        return 0;
    }
}

int FList::insertAtPosition(int pos, FlightManufacturer f)
{
    FNode* newNode = new FNode(f, NULL);

    if (isEmpty() && pos == 1)
    {
        first = newNode;
        return 1;
    }
    else if (pos == 1)
    {
        newNode->next = first;
        first = newNode;
        return 2;
    }
    else if (pos <= 0)
    {
        return -1;
    }
    else
    {
        FNode* temp = first;
        int index = 1;

        while (temp->next != NULL && index < pos - 1)
        {
            temp = temp->next;
            index++;
        }
        if (index == pos - 1)
        {
            newNode->next = temp->next;
            temp->next = newNode;
            return 5;
        }
        return -2;
    }
}

int FList::deleteAtFirst()
{
    if (isEmpty())
    {
        return 1;
    } else {
        FNode* temp = first;
        first = first->next;
        delete temp;
        return 2;
    }
}

int FList::deleteAtLast() {
    if (isEmpty()) {
        return 1;
    } else if (first->next == NULL) {
        delete first;
        first = NULL;
        return 2;
    } else {
        FNode* temp = first;
        while (temp->next->next != NULL)
            temp = temp->next;
        delete temp->next;
        temp->next = NULL;
        return 3;
    }
}

int FList::deleteByManufacturer(string manufacturer) {
    FNode* temp = first;
    FNode* prev = NULL;
    if (isEmpty()) {
        return 1;
    } else if (first->data.getManufacturer() == manufacturer) {
        first = temp->next;
        delete temp;
        return 2;
    }
    while (temp != NULL && temp->data.getManufacturer() != manufacturer) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        return 3;
    } else {
        prev->next = temp->next;
        delete temp;
        return 4;
    }
}

int FList::deleteByPosition(int pos) {
    FNode* temp = first;
    FNode* prev = NULL;
    if (isEmpty()) {
        return 1;
    } else if (pos <= 0) {
        return 2;
    } else if (pos == 1) {
        first = first->next;
        delete temp;
        return 3;
    } else {
        int index = 1;
        while (temp != NULL && index < pos) {
            prev = temp;
            temp = temp->next;
            index++;
        }
        if (temp == NULL) {
            return 4;
        } else {
            prev->next = temp->next;
            delete temp;
            return 5;
        }
    }
}

int FList::updateCapacity(string manufacturer, int capacity)
{
    if (isEmpty())
    {
        return 1;
    }
    else
    {
        FNode* temp = first;
        while (temp != NULL)
        {
            if (temp->data.getManufacturer() == manufacturer)
            {
                temp->data.setCapacity(capacity);
                return 2;
            }
            else
            {
                temp = temp->next;
            }
        }
        return 3;
    }
}

int FList::searchByAircraftType(string aircraftType)
{
    if (isEmpty())
    {
        return 1;
    }
    else
    {
        FNode* temp = first;
        int pos = 1;
        while (temp != NULL)
        {
            if (temp->data.getAircraftType() == aircraftType)
            {
                return pos;
            }
            else
            {
                temp = temp->next;
                pos++;
            }
        }
        return 3;
    }
}

int FList::reverse()
{
    if (isEmpty())
    {
        return 1;
    }
    else if (first->next == NULL)
    {
        return 2;
    }
    else
    {
        FNode* prev = NULL;
        FNode* curr = first;
        FNode* next = NULL;

       while (curr != NULL)
       {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
       }
       first = prev;
       return 3;
    }
}

int FList::makeListEmpty()
{
    if (isEmpty())
    {
        return 1;
    }
    else
    {
        while (!isEmpty())
        {
            deleteAtFirst();
        }
    }
    return 2;
}

void FList::display()
{
    if (isEmpty())
    {
        cout << "List is empty.\n";
        return;
    }
    FNode* temp = first;
    cout << "\t\t-----FLIGHT MANUFACTURER DETAILS-----\n";
    cout << "Manufacturer\t|\tModel\t|\tType\t|\tCapacity\t|\tEngine\n";
    cout << "-------------------------------------------------------------------------------\n";
    while (temp->next != NULL)
    {
        temp->data.displayData();
        temp = temp->next;
    }
    temp->data.displayData();
}
