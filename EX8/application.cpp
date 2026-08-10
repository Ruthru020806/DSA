#include "header.h"

//void Matrix();
void List();

int main()
{
    int choice;

    do
    {
        cout << "\n**** Graph Traversal Menu for FLIGHT MANUFACTURER****" << endl;
        cout << "1. Adjacency List" << endl;
        cout << "2. Exit"<<endl;
        //cout << "2. Adjacency Matrix" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            List();
            break;
        case 2:
            cout << "Exiting "<<endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 2);

    return 0;
}

/*void Matrix()
{
    int nov;
    cout << "\n--- Adjacency Matrix Test ---" << endl;
    cout << "Enter number of vertices: ";
    cin >> nov;

    GraphAdjMatrix matrix(nov);
    matrix.getVertices();
    matrix.getMatrix();

    int startID;
    cout << "\nEnter start vertex index for traversal (0-" << nov - 1 << "): ";
    cin >> startID;

    matrix.BFS(startID);
    matrix.DFS(startID);
}
*/
void List()
{
    int nov;
    cout << "\n--- Adjacency List Test ---" << endl;
    cout << "Enter number of vertices: ";
    cin >> nov;

    GraphAdjList list(nov);
    list.getVertices();
    list.getList();

    int startID;
    cout << "\nEnter start vertex index for traversal (0-" << nov - 1 << "): ";
    cin >> startID;

    list.BFS(startID);
    list.DFS(startID);
}
