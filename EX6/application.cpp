#include "header.h"
#include <limits>

int main()
{
    CAVL tree;
    int choice;

        cout << "\n====== Flight Manufacturer Management (AVL Tree) Menu ======\n";
        cout << "1. Add  Manufacturer\n";
        cout << "2. Delete  Manufacturer by ID\n";
        cout << "3. Search  Manufacturer by ID\n";
        cout << "4. Display InOrder\n";
        cout << "5. Display PreOrder\n";
        cout << "6. Display PostOrder\n";
        cout << "7. Find  Manufacturer with Minimum ID\n";
        cout << "8. Find  Manufacturer with Maximum ID\n";
        cout << "9. Exit\n";
        do
        {

        cout << "Enter your choice: ";

        if (!(cin >> choice))
        {
            cout << "Invalid input. Please enter a number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        switch(choice)
        {
            case 1:
            {
                string mname, country;
                int mid;
                double yoe;

                cout << "Enter  Manufacturer ID (integer): ";
                cin >> mid;
                cout << "Enter  Manufacturer  Name: ";
                cin >> mname;
                cout << "Enter Country: ";
                cin >> country;
                cout << "Enter Year of Establishment: ";
                cin >> yoe;


                CFlightManufacturer m(mid, mname, country, yoe);
                CNode* newNode = new CNode(m);


                tree.setRoot(tree.insertNode(tree.getRoot(), newNode));

                cout << " Manufacturer added successfully.\n";
                break;
            }

            case 2:
            {
                if (tree.getRoot() == NULL) {
                    cout << "Tree is empty. Nothing to delete.\n";
                    break;
                }
                int mid;
                cout << "Enter Manufacturer ID to delete: ";
                cin >> mid;


                tree.setRoot(tree.deleteNode(tree.getRoot(), mid));

                cout << "Attempted deletion for ID " << mid << ".\n";
                if (tree.getRoot() == NULL)
                {
                    cout << "NOTE: After Deletion, the Book AVL Tree is Empty.\n";
                }
                break;
            }

            case 3:
            {
                if (tree.getRoot() == NULL) {
                    cout << "Tree is empty. Cannot search.\n";
                    break;
                }
                int mid;
                cout << "Enter Manufacturer ID to search: ";
                cin >> mid;

                CNode* result = tree.search(tree.getRoot(), mid);
                if (result != NULL) {
                    cout << "Book found:\n";
                    cout << "ID\t\tName\t\tCountry\t\tYear of Establishment\n";
                    cout << "--------------------------------------------------------------\n";
                    result->displayNode();
                } else {
                    cout << "Error: Manufacturer with ID " << mid << " not found!\n";
                }
                break;
            }

            case 4:
            {
                cout << "\nInOrder Traversal (Sorted by ID):\n";
                cout << "ID\t\tName\t\tCountry\t\tYear of Establishment\n";
                cout << "--------------------------------------------------------------\n";
                tree.inOrder(tree.getRoot());
                break;
            }

            case 5:
            {
                cout << "\nPreOrder Traversal:\n";
                cout << "ID\t\tName\t\tCountry\t\tYear of Establishment\n";
                cout << "--------------------------------------------------------------\n";
                tree.preOrder(tree.getRoot());
                break;
            }

            case 6:
            {
                cout << "\nPostOrder Traversal:\n";
                cout << "ID\t\tName\t\tCountry\t\tYear of Establishment\n";
                cout << "--------------------------------------------------------------\n";
                tree.postOrder(tree.getRoot());
                break;
            }

            case 7:
            {
                CNode* result = tree.findMin(tree.getRoot());
                if(result == NULL)
                    cout << "Error: The tree is empty.\n";
                else
                {
                    cout << "\nManufacturer with Minimum ID:\n";
                    cout << "ID\t\tName\t\tCountry\t\tYear Of Establishment\n";
                    cout << "--------------------------------------------------------------\n";
                    result->displayNode();
                }
                break;
            }

            case 8:
            {
                CNode* result = tree.findMax(tree.getRoot());
                if(result == NULL)
                    cout << "Error: The tree is empty.\n";
                else
                {
                    cout << "\nManufacturer with Maximum ID:\n";
                    cout << "ID\t\tName\t\tCountry\t\tYear of Establishment\n";
                    cout << "--------------------------------------------------------------\n";
                    result->displayNode();
                }
                break;
            }

            case 9:
            {
                cout << "Exiting....\n";
                return 0;
            }

            default:
                cout << "Invalid choice! Please try again." << endl;
        }

    } while(choice != 9);

    return 0;
}
