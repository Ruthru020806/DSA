#include "header.h"
#include <iostream>
using namespace std;

int main()
{
    int capacity,result;
    cout << "Enter stack capacity: ";
    cin >> capacity;

    Stack st(capacity);
    cout << "\n===== Flight Manufacturer Application =====\n";
    cout << "1. Push (Add a Manufacturer)\n";
    cout << "2. Pop (Remove top Manufacturer)\n";
    cout << "3. Peek (View top Manufacturer)\n";
   /* cout << "4. Update Aircraft Count\n";
    cout << "5. Search by ManufacturerName\n";*/
    cout << "4. Display Stack\n";
    cout << "5. Make stack empty\n";
    cout << "0. Exit\n";
    int choice;
    do
    {
       cout << "Enter choice: ";
       cin >> choice;
       if (choice == 1)
       {
          string maufacturerName, country, aircraftType;
          int manufacturerId,aircraftCount;

          cout << "Enter Manufacturer name: ";
          cin >> maufacturerName;

          cout << "Enter Manufacturer Id: ";
          cin >> manufacturerId;

          cout << "Enter country: ";
          cin >> country;

          cout << "Enter aircraftcount: ";
          cin >> aircraftCount;

          cout << "Enter aircraftType: ";
          cin >> aircraftType;

          FlightManufacturerData b(maufacturerName, manufacturerId, country, aircraftCount, aircraftType);
          if (st.push(b) == 0)
             cout << "Manufacturer pushed successfully!\n";
          else
             cout << "Stack is full!\n";
       }
       else if (choice == 2)
       {
          result = st.pop();
          if (result == -1) cout << "Stack Underflow! Nothing to delete.\n";
          else if (result == 1) cout << "Last element deleted. Stack is now empty.\n";
          else if (result == 2) cout << "Element deleted successfully.\n";
          st.display();
       }
       else if (choice == 3)
       {
          FlightManufacturerData b = st.peek();
          cout << "Top Manufacturer:\n";
          b.displaydat();
       }
       /*else if (choice == 4)
       {
          string manufacturerName;
          int newAircraftCount;
          cout << "Enter manufacturer name to update aircarftCount: ";
          cin >> manufacturerName;
          cout << "Enter Aircraft Count: ";
          cin >> newAircraftCount;

          int res = st.updateAircraftCount(manufacturerName, newAircraftCount);
          if (res == 0)
             cout << "AircraftCount updated!\n";
          else if (res == 1)
             cout << "Stack is empty!\n";
          else
             cout << "Manufacturer not found!\n";
       }
       else if (choice == 5)
       {
          string manufacturerName;
          cout << "Enter manufacturer name: ";
          cin >> manufacturerName;
          int res = st.searchByManufacturerName(manufacturerName);
          if (res == 1)
             cout << "Stack is empty!\n";
          else if (res == 2)
             cout << "No book found by this author.\n";
       }*/
       else if (choice == 5)
       {
          st.display();
       }
       else if (choice == 6)
       {
          if(st.isEmpty())
             cout<<"Stack already empty\n";
          else
          {
             st.makeEmpty();
             cout << "Stack cleared!\n";
          }
       }
       else if (choice == 0)
       {
          cout << "Exiting...\n";
       }
       else
       {
          cout << "Invalid choice. Try again.\n";
       }
    } while (choice != 0);
    return 0;
}
