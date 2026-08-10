#include "header.h"
#include <iostream>
using namespace std;

int main()
{
    int  choice;
    string name, type;
    int aircraftcount;

    CAQueue queue(1000);
    CFlightManufacturer temp;



        cout << "\n--- Queue Menu ---\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Display Front\n";
        cout << "4. Display Rear\n";
        cout << "5. Display Queue\n";
        cout << "6. Make Queue Empty\n";
        cout << "7. Exit\n";
        while(true)
        {
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            cout << "Enter FlightManufacturer Name : ";
            cin >> name;
            cout << "Enter Aircraft Type : ";
            cin >> type;
            cout << "Enter  Aircraft count : ";
            cin >> aircraftcount;

            CFlightManufacturer ds(name, type, aircraftcount);
            if (queue.enqueue(ds) == -1)
                cout << "Error: Queue is Full!\n";
            else
                cout << "Enqueued successfully.\n";
            break;
        }

        case 2:
        {
            if (queue.dequeue() == -1)
                cout << "Error: Queue is Empty!\n";
            else
                cout << "Dequeued successfully.\n";
            break;
        }

        case 3:
        {
            if (queue.displayFront() == -1)
                cout << "Error: Queue is Empty!\n";
            break;
        }

        case 4:
        {
            if (queue.displayRear() == -1)
                cout << "Error: Queue is Empty!\n";
            break;
        }

        case 5:
        {
            if (queue.displayQueue() == -1)
                cout << "Error: Queue is Empty!\n";
            break;
        }

        case 6:
        {
            if (queue.makeQueueEmpty() == -1)
                cout << "Queue is already empty.\n";
            else
                cout << "Queue cleared.\n";
            break;
        }

        case 7:
            cout << "Exiting...\n";
            return 0;

        default:
            cout << "Invalid choice! Try again.\n";
        }
    }

    return 0;
}
