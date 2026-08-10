#include "header.h"
#include <iostream>
using namespace std;

int main()
{
    FList list;
    int choice, modelNumber, capacity, pos, result;
    string manufacturer, aircraftType, engine;

        cout << "\n===== FLIGHT MANUFACTURER MANAGEMENT SYSTEM =====\n";
        cout << "1. INSERT AIRCRAFT AT FIRST\n";
        cout << "2. INSERT AIRCRAFT AT LAST\n";
        cout << "3. INSERT AIRCRAFT AT POSITION\n";
        cout << "4. DELETE AT FIRST\n";
        cout << "5. DELETE AT LAST\n";
        cout << "6. DELETE BY MANUFACTURER\n";
        cout << "7. DELETE BY POSITION\n";
        cout << "8. UPDATE CAPACITY\n";
        cout << "9. REVERSE\n";
        cout << "10. DISPLAY LIST\n";
        cout << "11. MAKE LIST EMPTY\n";
        cout << "0. EXIT\n";
    do
    {
        cout << "ENTER CHOICE: ";
        cin >> choice;

        switch (choice)
        {
           case 1:
              cout << "Enter Manufacturer: ";
              cin >> manufacturer;
              cout << "Enter Model Number: ";
              cin >> modelNumber;
              cout << "Enter Aircraft Type: ";
              cin >> aircraftType;
              cout << "Enter Capacity: ";
              cin >> capacity;
              cout << "Enter Engine Type: ";
              cin >> engine;
              result = list.insertAtFirst(FlightManufacturer(manufacturer, modelNumber, aircraftType, capacity, engine));
              if(result == 1)
                 cout << "As list was empty, Aircraft was inserted in the first position successfully.\n";
              else if(result == 2)
                 cout  << "New Node is empty.\n";
              else
                 cout << "New Node inserted at the first position successfully.\n";
              break;

           case 2:
              cout << "Enter Manufacturer: ";
              cin >> manufacturer;
              cout << "Enter Model Number: ";
              cin >> modelNumber;
              cout << "Enter Aircraft Type: ";
              cin >> aircraftType;
              cout << "Enter Capacity: ";
              cin >> capacity;
              cout << "Enter Engine Type: ";
              cin >> engine;
              result = list.insertAtLast(FlightManufacturer(manufacturer, modelNumber, aircraftType, capacity, engine));
              if(result == 1)
                 cout << "As list was empty, Aircraft was inserted in the first position successfully.\n";
              else if(result == 2)
                 cout  << "New Node is empty.\n";
              else
                 cout << "New Node inserted at the last position successfully.\n";
              break;

           case 3:
              cout << "Enter Position to Insert: ";
              cin >> pos;
              cout << "Enter Manufacturer: ";
              cin >> manufacturer;
              cout << "Enter Model Number: ";
              cin >> modelNumber;
              cout << "Enter Aircraft Type: ";
              cin >> aircraftType;
              cout << "Enter Capacity: ";
              cin >> capacity;
              cout << "Enter Engine Type: ";
              cin >> engine;
              result = list.insertAtPosition(pos, FlightManufacturer(manufacturer, modelNumber, aircraftType, capacity, engine));

              if (result == 1)
                 cout << "As the list was empty and position is 1, it is inserted at position 1.\n";
              else if (result == 2)
                 cout << "New Node inserted at the first position successfully.\n";
              else if (result == -1 || result == -2)
                 cout << "Invalid position.\n";
              else if (result == 5)
                 cout << "New Node inserted at the desired position successfully.\n";
              else
                 cout << "Invalid, try again.\n";
              break;

           case 4:
              result = list.deleteAtFirst();
              if(result == 1)
                 cout << "List is empty.\n";
              else
                 cout << "Aircraft data deleted at first position.\n";
              break;

           case 5:
              result = list.deleteAtLast();
              if(result == 1)
                 cout << "List is empty.\n";
              else if(result == 2)
                 cout << "Aircraft in first position deleted.\n";
              else
                 cout << "Aircraft data deleted at the last position.\n";
              break;

           case 6:
              cout << "Enter Manufacturer to Delete: ";
              cin >> manufacturer;
              result = list.deleteByManufacturer(manufacturer);
              if(result == 1)
                 cout << "List is empty.\n";
              else if(result == 2)
                 cout << "Aircraft in first position deleted.\n";
              else if(result == 3)
                 cout << "No such aircraft found in the list.\n";
              else
                 cout << "Aircraft deleted successfully.\n";
              break;

           case 7:
              cout << "Enter Position to Delete: ";
              cin >> pos;
              result = list.deleteByPosition(pos);
              if(result == 1)
                 cout << "List is empty.\n";
              else if(result == 2)
                 cout << "Invalid position.\n";
              else if(result == 3)
                 cout << "Aircraft at first position deleted successfully.\n";
              else if(result == 4)
                 cout << "No such position found.\n";
              else
                 cout << "Aircraft data deleted successfully at the desired position.\n";
              break;

           case 8:
              cout << "Enter Manufacturer: ";
              cin >> manufacturer;
              cout << "Enter New Capacity: ";
              cin >> capacity;
              result = list.updateCapacity(manufacturer, capacity);
              if(result == 1)
                 cout << "List is empty.\n";
              else if(result == 2)
                 cout << "New capacity updated successfully.\n";
              else
                 cout << "Invalid details, please enter correct details.\n";
              break;

           case 9:
              result = list.reverse();
              if(result == 1)
                 cout << "List is empty.\n";
              else if(result == 2)
                 cout << "Only one element found.\n";
              else
                 cout << "List reversed successfully.\n";
              break;

           case 10:
              list.display();
              break;

           case 11:
              result = list.makeListEmpty();
              if(result == 1)
                 cout << "List is already empty.\n";
              else
                 cout << "List emptied.\n";
              break;

           case 0:
              cout << "---EXITING PROGRAM---\n";
              break;

           default:
              cout << "Invalid choice.\n";
        }
    }
    while (choice != 0);
    return 0;
}
