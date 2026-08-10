#include "header.h"
#include <iostream>
using namespace std;

int main()
{
    Stack s;
    int choice, engineCount, seatingCapacity, result;
    float cost;
    string manufacturer, model;
    Aircraft_data a;
    cout << "\n===== Aircraft Stack Menu =====\n";
    cout << "1. PUSH AIRCRAFT\n";
    cout << "2. POP AIRCRAFT\n";
    cout << "3. PEEK TOP AIRCRAFT\n";
    cout << "4. DISPLAY STACK\n";
    cout << "5. MAKE STACK EMPTY\n";
    cout << "6. IF EMPTY\n";
    cout << "7. STACK SIZE\n";
    cout << "0. EXIT\n";
    do
    {
        cout << "ENTER CHOICE: ";
        cin >> choice;
        cin.ignore();
        switch(choice)
        {
            case 1:
                cout << "Enter Manufacturer: ";
                getline(cin, manufacturer);
                cout << "Enter Model: ";
                getline(cin, model);
                cout << "Enter Engine Count: ";
                cin >> engineCount;
                cout << "Enter Seating Capacity: ";
                cin >> seatingCapacity;
                cout << "Enter Cost: ";
                cin >> cost;
                cin.ignore();

                result = s.push(Aircraft_data(manufacturer, model, engineCount, seatingCapacity, cost));
                if(result == -1)
                {
                   cout << "Memory allocation failed.\n";
                }
                else if(result == 1)
                {
                   cout << "Inserted first aircraft successfully.\n";
                }
                else
                {
                   cout << "Aircraft pushed successfully.\n";
                }
                break;

            case 2:
                result = s.pop();
                if(result == 1)
                {
                   cout << "Stack is empty.\n";
                }
                else
                {
                   cout << "Top aircraft popped successfully.\n";
                }
                break;

            case 3:
                result = s.peek(a);
                if(result == 1)
                {
                   cout << "Stack is empty.\n";
                }
                else
                {
                    cout << "  Top Aircraft -> Manufacturer: " << a.getManufacturer()
                         << ", Model: " << a.getModel()
                         << ", Engines: " << a.getEngineCount()
                         << ", Seating: " << a.getSeatingCapacity()
                         << ", Cost: ₹" << a.getCost() << endl;
                }
                break;

            case 4:
                result = s.display_stack();
                if(result == 1)
                {
                   cout << "Stack is empty.\n";
                }
                break;

            case 5:
                if(s.isEmpty())
                {
                   cout << "Stack already empty.\n";
                }
                else
                {
                   s.makeStackEmpty();
                   cout << "Stack cleared successfully.\n";
                }
                break;

            case 6:
                result = s.isEmpty();
                if(result == 1)
                {
                   cout << "Stack is empty.\n";
                }
                else
                {
                   cout << "Stack is not empty.\n";
                }
                break;

            case 7:
                cout << "Current Stack Size: " << s.size() << endl;
                break;

            case 0:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice.\n";
        }

    } while(choice != 0);

    return 0;
}
