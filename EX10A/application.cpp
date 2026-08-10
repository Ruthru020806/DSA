#include "head.h"
int main()
{
    int size, ch;
    cout << "\nEnter the size of the Hash Table:";
    cin >> size;
    Hashtable ht(size);
    do
    {
        cout << "------------------MENU---------------------\n";
        cout << "-------------------------------------------------------------\n";
        cout << "1.Insert a Manufacturer\t2.Delete a Manufacturer\n3.Search a MAnufacturer\t4.Display Table\t0.EXIT\n";

        cout << "\nEnter the choice:";
        cin >> ch;
        switch (ch)
        {
        case 1:
        {
            CFManufacturer c;
            c.getManufacturer();
            int mid = c.getID();
            int bucketNo = ht.hashFunc(mid);
            CNode *newNode = new CNode(c, NULL);
            ht.insertFirst(newNode, bucketNo);
            cout << "\nTHE Manufacturer INSERTED SUCCESSFULLY !\n\n";
            break;
        }
        case 2:
        {
            int mid;
            cout << "\nEnter the Manufacturer ID  to delete the Manufacturer:";
            cin >> mid;
            int bucketNo = ht.hashFunc(mid);
            int check = ht.deleteBymid(mid, bucketNo);
            if (check == -1)
            {
                cout << "NO MORE ENTRIES IN THE BUCKET !\n\n";
            }
            else if (check == -2)
            {
                cout << "\nDATA NOT FOUND !\n\n";
            }
            else
            {
                cout << "\nMAnufacturer DELETED SUCCESSFULLY FROM THE BUCKET:" << bucketNo << "\n\n";
            }
            break;
        }
        case 3:
        {
            int mid;
            cout << "\nENTER THE Manufacturer ID OF THE Manufacturer TO SEARCH:";
            cin >> mid;
            int bucketNo = ht.hashFunc(mid);
            CFManufacturer c = ht.search(mid, bucketNo);

            if (c.getID() == 0)
            {
                cout << "\nTHE ELEMENT NOT FOUND !\n\n";
            }
            else
            {
                cout << "\n-----MANUFACTURER FOUND-----" << endl;
                cout << "----------------------------------------------------\n";
                cout << "Manufacturer Name\t\tManufacturer ID\t\tYear Of Establishment" << endl;
                c.displayManufacturer();
            }
            break;
        }
        case 4:
        {
            ht.displayTable();
            break;
        }
        case 0:
        {
            cout << "\nEXITING>>>>>>\n\n";
            break;
        }
        default:
        {
            cout << "\nINVALID CHOICE !\n\n";
        }
        }
    } while (ch != 0);
}
