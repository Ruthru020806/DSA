#include "header.h"

int main()
{
    CBST b;
    bool ret;
    int n;
    cout<<"1.Isempty\n2. Insertion\n3. InOrder\n4.Findmin\n5.Findmax\n6.Search\n7.Preorder\n8.Postorder\n9.Delete\n10.Getroot\n0.Exit \n11.MakeTreeEmpty\n";
    do
    {
        cout<<"Enter your choice: ";
        cin>>n;
        switch(n)
        {
            case 1:
            {
               ret=b.Isempty();
               if(ret)
                   cout<<"Empty Tree !"<<endl;
               else
                   cout<<"Not empty tree !"<<endl;
               break;
            }
            case 2:
            {
                Manufacturer d;
                d.GetManufacturer();
                CNode* newnode = new CNode(d);
                CNode* root=b.Getroot();
                ret = b.Insert(root,newnode);
                if(ret)
                    cout<<"Manufacturer details inserted into BST\n";
                else
                    cout<<"Insertion failed. Duplicate ManufacturerID.\n";
                break;
            }
            case 3:
            {
                CNode* root=b.Getroot();
                if(root==NULL)
                {
                    cout<<"THE TREE IS EMPTY "<<endl;
                    break;
                }
                cout<<"InOrder Traversal\n";
                cout<<"ManufacturerName\t\tManufacturerId\t\tAircraftCount\n";
                cout<<"====================================================\n";
                b.Inorder(root);
                cout<<"\n";
                break;
            }
            case 4:
            {
                CNode* root=b.Getroot();
                if(root==NULL)
                {
                    cout<<"THE TREE IS EMPTY "<<endl;
                    break;
                }
                CNode* min=b.Findmin(root);
                cout<<"\n|-----MINIMUM IN THE TREE-----|"<<endl;
                cout<<"ManufacturerName\t\tManufacturerId\t\tAircraftCount\n";
                min->Displaydata();
                break;
            }
            case 5:
            {
                CNode* root=b.Getroot();
                if(root==NULL)
                {
                    cout<<"THE TREE IS EMPTY"<<endl;
                    break;
                }
                CNode* max=b.Findmax(root);
                cout<<"\n|-----MAXIMUM IN THE TREE-----|"<<endl;
                cout<<"ManufacturerName\t\tManufacturerId\t\tAircraftCount\n";
                max->Displaydata();
                break;
            }
            case 6:
            {
                int x;
                CNode* root=b.Getroot();
                if(root==NULL)
                {
                    cout<<"THE TREE IS EMPTY "<<endl;
                    break;
                }
                cout<<"Enter the Manufacturer ID to search:"<<endl;
                cin>>x;
                CNode* find=b.Search(root,x);
                if(find==NULL)
                    cout<<"The ManufacturerId not found !"<<endl;
                else
                {
                    cout<<"\n|-----Manufacturer FOUND-----|"<<endl;
                    cout<<"ManufacturerName\t\tManufacturerId\t\tAircraftCount\n";
                    find->Displaydata();
                }
                break;
            }
            case 7:
            {
                CNode* root=b.Getroot();
                if(root==NULL)
                {
                    cout<<"THE TREE IS EMPTY "<<endl;
                    break;
                }
                cout<<"PreOrder Traversal\n";
                cout<<"ManufacturerName\t\tManufacturerId\t\tAircraftCount\n";
                cout<<"====================================================\n";
                b.Preorder(root);
                cout<<"\n";
                break;
            }
            case 8:
            {
                CNode* root=b.Getroot();
                if(root==NULL)
                {
                    cout<<"THE TREE EMPTY!"<<endl;
                    break;
                }
                cout<<"PostOrder Traversal\n";
                cout<<"ManufacturerName\t\tManufacturerId\t\tAircraftCount\n";
                cout<<"====================================================\n";
                b.Postorder(root);
                cout<<"\n";
                break;
            }
            case 9:
            {
                int x;
                cout<<"Enter the Manufacturer ID to delete:"<<endl;
                cin>>x;
                CNode* root = b.Getroot();
                if(root == NULL)
                {
                    cout<<"THE TREE ALREADY EMPTY "<<endl;
                    break;
                }
                bool status = false;
                root = b.Deleteelt(root, x, status);
                b.Setroot(root);
                if(status)
                    cout<<"Manufacturer with ManufacturerId "<<x<<" deleted successfully!\n";
                else
                    cout<<"The ManufacturerID "<<x<<" not found. Deletion failed!\n";
                break;
            }
            case 10:
            {
                CNode* root=b.Getroot();
                if(root!=NULL)
                {
                    cout<<"|-----ROOT OF THE TREE-----|"<<endl;
                    cout<<"ManufacturerName\t\tManufacturerID\t\tAircraftCount\n";
                    cout<<"====================================================\n";
                    root->Displaydata();
                }
                else
                    cout<<"EMPTY TREE !"<<endl;
                break;
            }
            case 0:
            {
                cout<<"EXITING...."<<endl;
                break;
            }
            case 11:
            {
               if(b.Isempty())
                  cout<<"Tree already Empty\n";
               else
               {
                  b.makeTreeEmpty(b.Getroot());
                  b.Setroot(NULL);
                  cout << "Stack is Emptied\n";
               }
            }
            break;
            default:
            cout<<"INVALID CHOICE !"<<endl;
            break;
        }
    }while(n!=0);
}
