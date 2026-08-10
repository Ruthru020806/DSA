#include "head.h"

int main()
{
    CFManufacturerPriorityQueue heap;
    int choice;

    cout << "\n====== Flight Manufacturer Priority Queue (Binary Min-Heap) ======\n";
    cout << "1. Add Manufacturer\n";
    cout << "2. Delete Manufacturer with Minimum Priority\n";
    cout << "3. Display All Flight Manufacturers\n";
    cout << "4. Show Manufacturer with Minimum Priority\n";
    cout << "5. Increase Priority by Index\n";
    cout << "6. Increase Priority to New Value\n";
    cout << "7. Decrease Priority by Index\n";
    cout << "8. Decrease Priority to New Value\n";
    cout << "9. Build Heap\n";
    cout << "10. Check if Heap is Full or Empty\n";
    cout << "11. Exit\n";

    do
    {
        cout << "===================================================\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            string name, country;
            float yoe;
            int priority;

            cout << "Enter Name: ";
            cin >> name;

            cout << "Enter Country: ";
            cin >> country;

            cout << "Enter YOE: ";
            cin >> yoe;

            cout << "Enter Priority (integer): ";
            cin >> priority;

            CFManufacturer m(name, country, yoe, priority);
            if (heap.insert(m) != -1)
                cout << "Inserted successfully.\n";
            else
                cout << "Heap is full.\n";

            break;
        }

        case 2:
        {
            cout << "\nManufacturer with Minimum Priority (to be deleted):\n";
            cout << "Name\t\tCountry\t\tYear Of Establishment\t\tPriority\n";
            cout << "--------------------------------------------------------------\n";
            heap.returnMin().display();
            cout << "--------------------------------------------------------------\n";

            if (heap.deleteMin() != -1)
                cout << "Manufacturer deleted successfully.\n";
            else
                cout << "Heap is empty.\n";
            break;
        }

        case 3:
        {
            cout << "\n--- Current Manufacturer Heap ---\n";
            cout << "Name\t\tCountry\t\tYear Of Establishment\t\tPriority\n";
            cout << "--------------------------------------------------------------\n";
            heap.displayFManufacturer();
            cout << "--------------------------------------------------------------\n";
            break;
        }

        case 4:
        {
            if (heap.isEmpty())
                cout << "Heap is empty.\n";
            else
            {
                cout << "\n--- Manufacturer with Minimum Priority ---\n";
                cout << "Name\t\tCountry\t\tYear Of Establishment\t\tPriority\n";
                cout << "--------------------------------------------------------------\n";
                heap.returnMin().display();
                cout << "--------------------------------------------------------------\n";
            }
            break;
        }

        case 5:
        {
            int index, amount;
            cout << "Enter index to increase priority: ";
            cin >> index;
            cout << "Enter value to be increased by priority: ";
            cin >> amount;

            if (heap.increaseKeyBy(index, amount) == 1)
                cout << "Priority increased successfully.\n";
            else
                cout << "Invalid index or Value.\n";
            break;
        }

        case 6:
        {
            int index, newPriority;
            cout << "Enter index to increase priority: ";
            cin >> index;
            cout << "Enter new priority value: ";
            cin >> newPriority;

            if (heap.increaseKeyWith(index, newPriority) == 1)
                cout << "Priority updated successfully.\n";
            else
                cout << "Invalid operation.\n";
            break;
        }

        case 7:
        {
            int index, amount;
            cout << "Enter index to decrease priority: ";
            cin >> index;
            cout << "Enter value to be decreased by priority: ";
            cin >> amount;

            if (heap.decreaseKeyBy(index, amount) == 1)
                cout << "Priority decreased successfully.\n";
            else
                cout << "Invalid index or value.\n";
            break;
        }

        case 8:
        {
            int index, newPriority;
            cout << "Enter index to decrease priority: ";
            cin >> index;
            cout << "Enter new priority value: ";
            cin >> newPriority;

            if (heap.decreaseKeyWith(index, newPriority) == 1)
                cout << "Priority updated successfully.\n";
            else
                cout << "Invalid operation.\n";
            break;
        }

        case 9:
        {
            int n;
            cout << "Enter number of manufacturer: ";
            cin >> n;

            CFManufacturer *arr = new CFManufacturer[n];
            for (int i = 0; i < n; i++)
            {
                string name, country;
                float yoe;
                int pri;

                cout << "\nManufacturer " << i + 1 << ":\n";
                cout << "Name: ";
                cin >> name;
                cout << "Country: ";
                cin >> country;
                cout << "YOE: ";
                cin >> yoe;
                cout << "Priority: ";
                cin >> pri;

                arr[i] = CFManufacturer(name, country, yoe, pri);
            }

            if (heap.buildHeap(arr, n) == 1)
                cout << "Heap built successfully.\n";
            else
                cout << "Heap build failed.\n";

            delete[] arr;
            break;
        }

        case 10:
        {
            if (heap.isEmpty())
                cout << "Heap is empty.\n";
            else
                cout << "Heap is not empty.\n";

            if (heap.isFull())
                cout << "Heap is full.\n";
            else
                cout << "Heap is not full.\n";
            break;
        }

        case 11:
        {
            cout << "Exiting program...\n";
            break;
        }

        default:
        {
            cout << "Invalid choice! Please try again.\n";
            break;
        }
        }

    } while (choice != 11);

    return 0;
}
