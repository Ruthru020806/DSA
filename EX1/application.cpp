#include "head.h"
int main()
{
    int choice, ele, pos, eleb, elea, capacity, size=0;
    cout << "Array List Menu!\n";
    cout << "Enter the capacity of the list: ";
    cin >> capacity;
    int *arr = new int[capacity];
    while (true)
    {
        cout << "Enter the initial size of the list: ";
        cin >> size;
        if ((size <= capacity) && (size !=0))
        {
            cout << "Enter " << size << " elements:\n";
            for (int i = 0; i < size; i++)
                cin >> arr[i];
            break;
        }
        if (size == 0)
            break;
        cout << "Invalid size. Please enter a size between 1 and " << capacity << ".\n";
    }
    CAList list(arr, capacity, size);
    delete[] arr;
    cout << "\nArray List Menu \n";
    cout << "1. Check if the list is Full\n";
    cout << "2. Check if the list is Empty\n";
    cout << "3. Display List of elements in the array\n";
    cout << "4. Search Element in the array\n";
    cout << "5. Insert at First\n";
    cout << "6. Insert at Last\n";
    cout << "7. Insert by Position\n";
    cout << "8. Insert Before Element\n";
    cout << "9. Insert After Element\n";
    cout << "10. Delete at First\n";
    cout << "11. Delete at Last\n";
    cout << "12. Delete by Position\n";
    cout << "13. Delete Before Element\n";
    cout << "14. Delete After Element\n";
    cout << "15. Update Element\n";
    cout << "16. Insert at Middle\n";
    cout << "17. Delete at Middle\n";
    cout << "18.Reverse the List\n";
    cout << "19. Make List Empty\n";
    cout << "20. Exit\n";
    while (true)
    {
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
            case 1:
                if (list.isFull())
                    cout << "List is full!!\n";
                else
                    cout << "List is not full\n";
                break;
            case 2:
                if (list.isEmpty())
                    cout << "List is empty!!!\n";
                else
                    cout << "List is not empty" << endl;
                break;
            case 3:
                cout<<"Displaying the array elements:\n";
                list.display();
                break;
            case 4:

                cout << "Enter the element to be searched: ";
                cin >> ele;
                if (list.searchElement(ele) == 0)
                {
                   cout << "List is empty!!!";

                }
                else if  (list.searchElement(ele) != -1 )

                    cout << "Element found at index " << list.searchElement(ele) << endl;

                else

                   cout << "Element not found\n";
                break;
            case 5:

                if (!list.isFull())
                {
                    cout << "Enter element to be inserted at first: ";
                    cin >> ele;
                    list.insertAtFirst(ele);
                    cout << "Element inserted at first successfully.\n";
                    list.display();
                }
                else
                    cout << "List is full(Insertion not possible).\n";
                break;

            case 6:
                if (!list.isFull())
                {
                    cout << "Enter element to be inserted at last: ";
                    cin >> ele;
                    list.insertAtlast(ele);
                    cout << "Element inserted at last successfully.\n";
                    list.display();
                }
                else
                    cout << "List is full. Cannot(Insertion is not possible)\n";
                break;
            case 7:
                if (!list.isFull())
                {
                    cout << "Enter element and position: ";
                    cin >> ele >> pos;
                    int res = list.insertByPosition(pos, ele);
                    if(res==0 || res<0 )
                        cout << "Invalid position insertion not possible" << pos << ".\n";
                    else
                    {
                        cout << "Element inserted at position " << pos << " successfully.\n";
                        list.display();
                    }
                }
                else
                    cout << "List is full (Insertion not possible).\n";
                break;
            case 8:
                if(list.isEmpty())
                   cout<<"List is empty\n";
                else if (!list.isFull())
                {
                    cout << "Enter the element to inserted and the element before which insertion want to be done : ";
                    cin >> ele >> eleb;
                    if(list.insertBeforeElement(ele, eleb)==0)
                        cout << "Element not found(Insertion not possible).\n";
                    else
                    {
                        cout << "Element inserted before " << eleb << " successfully.\n";
                        list.display();
                    }
                }
                else
                    cout << "List is full (Insertion not possible).\n";
                break;
            case 9:
                if(list.isEmpty())
                   cout<<"List is Empty\n";
                else if (!list.isFull())
                {
                    cout << "Enter the element to inserted and the element after which insertion want to be done : ";
                    cin >> ele >> elea;
                    if(list.insertAfterElement(ele, elea)==0)
                        cout << "Element not found (Insertion not possible)\n";
                    else
                    {
                        cout << "Element inserted after " << elea << " successfully.\n";
                        list.display();
                    }
                }
                else
                    cout << "List is full (Insertion not possible).\n";
                break;
            case 10:
                if(list.deleteAtFirst()==0)
                    cout << "List is empty(Deletion is not possible)\n";
                else
                {
                    cout << "First Element deleted successfully.\n";
                    list.display();
                }
                break;
            case 11:
                if(list.deleteAtLast()==0)
                    cout << "List is empty (Deletion is not possible).\n";
                else
                {
                    cout << "Last Element deleted successfully.\n";
                    list.display();
                }
                break;
            case 12:
                cout << "Enter position to delete: ";
                cin >> pos;
                if(list.deleteByPosition(pos)<=0)
                    cout << "List is either empty or position is invalid(Deletion is not possible at" << pos << ").\n";
                else
                {
                    cout << "Element at position " << pos << " deleted successfully.\n";
                    list.display();
                }
                break;
            case 13:
                cout << "Enter the before element of element to be deleted : ";
                cin >> ele;
                if(list.deleteBeforeElement(ele)==0)
                    cout << "List is empty or element not found (Deletion is not possible)\n";
                else
                {
                    cout << "Element deleted before " << ele << " successfully.\n";
                    list.display();
                }
                break;
            case 14:
                cout << "Enter the next element of element to be deleted : ";
                cin >> ele;
                if(list.deleteAfterElement(ele)==0 ||(list.deleteAfterElement(ele)<0))
                    cout << "List is empty or element not found (Deletion is not possible)\n";
                else
                {
                    cout << "Element deleted after " << ele << " successfully.\n";
                    list.display();
                }
                break;
            case 15:
                if(list.isEmpty())
                   cout << "List Empty! No element to update(replace)";
                else
                {
                   int ele1;
                   cout << "Enter an element to be replaced: ";
                   cin >> ele1;
                   int index = list.searchElement(ele1);
                   if(index==-2)
                      cout << "Element to be replaced not found in the list!\n";
                   else
                   {
                      cout << "Enter the value to be updated: ";
                      cin >> ele;
                      list.updateEle(ele1,ele);
                      cout << "Element replaced\n";
                      list.display();
                   }
                }
                break;
            case 16:
                if(!list.isFull())
                {
                   cout << "Enter an element to be inserted at the middle: ";
                   cin >> ele;
                   list.insertAtMiddle(ele);
                   cout << "Element inserted successfully\n";
                   list.display();
                }
                else
                   cout << "List is Full(Insertion is failed)";
                break;
            case 17:
                if(list.deleteAtMiddle())
                {
                   cout << "Element deleted at middle successfully.\n";
                   list.display();
                }
                break;
            case 18:
                if (list.isEmpty())
                {
                   cout<<"List is Empty(Cannot be Reversed)\n";
                }
                else
                {
                   list.reverseElement();
                }
                break;
            case 19:
                if(!list.isEmpty())
                {
                   list.makeListEmpty();
                   cout << "List is made empty now!!!";
                   list.display();
                }
                else
                   cout << "List is already Empty\n";
                break;
            case 20:
                cout << "Exiting program...\n";
                return 0;
            default:
                cout << "Invalid choice. Try again.\n";
        }
  }
}
