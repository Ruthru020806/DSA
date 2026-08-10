#include "header.h"
FlightManufacturerData::FlightManufacturerData()
{
    manufacturerName = "";
    manufacturerId = 0;
    country = "";
    aircraftCount= 0;
    aircraftType= "";
}
FlightManufacturerData::FlightManufacturerData(string n, int i, string c, int s, string o)
{
    manufacturerName = n;
    manufacturerId= i;
    country= c;
    aircraftCount = s;
    aircraftType= o;
}

void  FlightManufacturerData::displaydat()
{
    cout << manufacturerName<<"\t" << manufacturerId<<"\t " << country<<"\t" << aircraftCount<<"\t " << aircraftType << endl;
}

Stack::Stack(int c)
{
    capacity = c;
    top = -1;
    arr = new FlightManufacturerData[capacity]; }

bool Stack::isEmpty()
{
    return (top == -1);
}

bool Stack::isFull()
{
    return (top == capacity - 1);
}

int Stack::push(FlightManufacturerData m)
{
    if (isFull()) return 1;
    arr[++top] = m;
    return 0;
}

int Stack::pop()
{
    if (isEmpty())
    {
        return -1;
    }
    else
    {

        cout << "Popped element is:\n";
    cout << "====================== Flight Manufacturer Stack ======================\n";
    cout << "NAME   |  ID  |  COUNTRY | AIRCRAFTCOUNT  | AIRCRAFTTYPE\n";
        arr[top].displaydat();
        top--;
        return 2;
    }
}

/*int Stack::updateAircraftCount(string n, int s)
{
    if (isEmpty()) return 1;
    for (int i = 0; i <= top; i++)
    {
        if (arr[i].getManufacturerName() == n)
        {
            arr[i] = FlightManufacturerData(arr[i].getManufacturerName(), arr[i].getManufacturerId(),
                               arr[i].getCountry(), s, arr[i].getAircraftType());
            return 0;
        }
    }
    return 2;
}*\

/*int Stack::searchByManufacturerName(string c)
{
    if (isEmpty()) return 1;
    int found = 0;
    for (int i = 0; i <= top; i++)
    {
        if (arr[i].getManufacturerName() == c)
        {
    cout << "======================Flight Manufacturer Stack ======================\n";
    cout << "NAME   |  ID  |  COUNTRY | AIRCRAFTCOUNT  | AIRCRAFTTYPE\n";
            arr[i].displaydat();
            found = 1;
        }
    }
    return (found ? 0 : 2);
}*/

void Stack::display()
{
    if (isEmpty())
    {
        cout << "Stack is empty.\n";
        return;
    }
    cout << "====================== Flight Manufacturer Stack ======================\n";
    cout << "NAME   |  ID  |  COUNTRY | AIRCRAFTCOUNT  | AIRCRAFTTYPE\n";
    for (int i = top; i >= 0; i--)
    {
        arr[i].displaydat();
    }
    cout << "======================================================== \n";
}

void Stack::makeEmpty()
{
    while(!isEmpty())
       pop();
}

FlightManufacturerData Stack::peek()
{
    if (isEmpty())
        return FlightManufacturerData();
    else
        return arr[top];
}
