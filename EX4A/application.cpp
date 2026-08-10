#include<iostream>
#include "header.h"
using namespace std;
int main()
{
    int capacity;
    cout << "Enter queue capacity: ";
    cin >> capacity;

    string fmname,country;
    int fmid,aircraftcount;

    CircularQueue q(capacity);
    FM_data e;

    int choice;
    cout << "\n=====Circular Queue Menu=====\n";
    cout << "1.Enqueue\n";
    cout << "2.Dequeue\n";
    cout << "3.Peek_Front\n";
    cout << "4.Peek_Rear\n";
    cout << "5.Display Queue\n";
    cout << "6.Make Queue Empty\n";
    cout << "0.EXIT\n";
    do
    {
        cout << "Enter your choice: ";
        cin >> choice;
        switch(choice)
        {
            case 1:
            {
                cout << "Enter Manufacturer Name: ";
                cin >> fmname;
                cout << "Enter Manufacturer ID: ";
                cin >> fmid;
                cout << "Enter Country: ";
                cin >> country;
                cout << "Enter Aircraft Count: ";
                cin >> aircraftcount;
                e = FM_data(fmname,fmid,country,aircraftcount);
                int res = q.enqueue(e);
                if(res == -1)
                {
                    cout << "Queue is full\n";
                }
                else if(res == 0)
                {
                    cout << "Queue was empty, so added at first position.\n";
                }
                else
                {
                    cout << "Enqueued successfully.\n";
                }
                break;
            }

            case 2:
            {
                int res = q.dequeue();
                if(res == -1)
                {
                    cout << "Queue is under flow.\n";
                }
                else if(res == 1)
                {
                    cout << "Only one element present, so first element deleted.\n";
                }
                else
                {
                    cout << "Element dequeued successfully.\n";
                }
                break;
            }

            case 3:
            {
                int res = q.peekFront();
                if(res == -1)
                {
                    cout << "No elements";
                }
                else
                {
                    cout << "Front element: ",e.displaydat();
                }
                break;
            }

            case 4:
            {
                int res = q.peekRear();
                if(res == -1)
                {
                    cout << "No elements\n";
                }
                else
                {
                    cout << "Rear element: ",e.displaydat();
                }
                break;
            }

            case 5:
            {
                if(q.display()==-1)
                {
                    cout << "Queue is empty.\n";
                }
                else
                {
                    cout << "Elements: ";
                }
                break;
            }

            case 6:
            {
                int res = q.makeQueueEmpty();
                if(res == -1)
                {
                    cout << "Already Empty\n";
                }
                else
                {
                    cout << "Queue emptied successfully.\n";
                }
                break;
            }

            case 0:
            {
                cout << "Existing......\n";
                break;
            }

            default:
            {
                cout << "Invalid choice\n";
            }
        }
    }while(choice!=0);
}
