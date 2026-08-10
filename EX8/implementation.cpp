#include "header.h"

Vertex::Vertex()
{
    mname = " ";
    country= " ";
    mid = -1;
}

Vertex::Vertex(string t, string a, int p)
{
    mname = t;
    country= a;
    mid = p;
}

Vertex::~Vertex() {}

void Vertex::getVertex()
{
    cout << "Enter Manufaturer NAME : ";
    cin >> mname;
    cout << "Enter COUNTRY : ";
    cin >> country;
    cout << "Enter Manufacturer ID: ";
    cin >> mid;
}

void Vertex::displayVertex()
{
    cout <<"\n"<< mname << "\t\t" << country<<"\t\t" << mid <<"\n";
}

Node::Node()
{
    Vertex vertex;
    next = NULL;
}

Node::Node(Vertex v, Node* n)
{
    vertex = v;
    next = n;
}

Node::~Node() {}

void Node::displayNode()
{
    vertex.displayVertex();
}

Queue::Queue(int c)
{
    capacity = c;
    front = -1;
    rear = -1;
    queuearr = new int[capacity];
}

Queue::~Queue()
{
    delete[] queuearr;
}

int Queue::isEmpty()
{
    return (front == -1 && rear == -1) || (front > rear);
}

int Queue::isFull()
{
    return (rear == (capacity - 1));
}

int Queue::enqueue(int element)
{
    if (!isFull())
    {
        if (front == -1 && rear == -1)
        {
            front = 0;
            rear = 0;
            queuearr[rear] = element;
        }
        else
        {
            queuearr[++rear] = element;
        }
        return 1;
    }
    else
    {
        return -1;
    }
}

int Queue::dequeue()
{
    if (!isEmpty())
    {
        int dltelt = queuearr[front];
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front++;
        }
        return dltelt;
    }
    else
    {
        return -1;
    }
}

/*GraphAdjMatrix::GraphAdjMatrix()
{
    no_of_vertices = 10;
    vertices = new Vertex[no_of_vertices];
    adjMatrix = new int* [no_of_vertices];
    for (int i = 0; i < no_of_vertices; i++)
    {
        adjMatrix[i] = new int[no_of_vertices];
        for (int j = 0; j < no_of_vertices; j++)
        {
            adjMatrix[i][j] = 0;
        }
    }
}

/*GraphAdjMatrix::GraphAdjMatrix(int nov)
{
    no_of_vertices = nov;
    vertices = new Vertex[no_of_vertices];
    adjMatrix = new int* [no_of_vertices];
    for (int i = 0; i < no_of_vertices; i++)
    {
        adjMatrix[i] = new int[no_of_vertices];
        for (int j = 0; j < no_of_vertices; j++)
        {
            adjMatrix[i][j] = 0;
        }
    }
}

GraphAdjMatrix::~GraphAdjMatrix()
{
    delete[] vertices;
    for (int i = 0; i < no_of_vertices; i++)
    {
        delete[] adjMatrix[i];
    }
    delete[] adjMatrix;
}

void GraphAdjMatrix::getVertices()
{
    cout << "\n--- Enter Vertex Details ---" << endl;
    for (int i = 0; i < no_of_vertices; i++)
    {
        cout << "\nVertex " << i << ":" << endl;
        vertices[i].getVertex();
    }
}

void GraphAdjMatrix::getMatrix()
{
    int source, destination;
    char choice;

    cout << "\n--- Enter Edges ---" << endl;
    do
    {
        cout << "Enter Source Vertex Index (0-" << no_of_vertices - 1 << "): ";
        cin >> source;
        cout << "Enter Destination Vertex Index (0-" << no_of_vertices - 1 << "): ";
        cin >> destination;

        if (source >= 0 && source < no_of_vertices && destination >= 0 && destination < no_of_vertices && source!=destination)
        {
            if (adjMatrix[source][destination] != 1)
            {
                adjMatrix[source][destination] = 1;
                adjMatrix[destination][source] = 1;
                cout << "Edge added between " << vertices[source].title << " and " << vertices[destination].title << "." << endl;
            }
            else if (adjMatrix[source][destination] == 1)
            {
                cout << "Edge already exists between " << vertices[source].title << " and " << vertices[destination].title << "." << endl;
            }
            else
            {
                cout << "Edge already exists between " << vertices[destination].title << " and " << vertices[source].title << "." << endl;
            }
        }
        else if(source== destination)
        {
           cout<<"no vertex can have edge to itself.\n";
        }
        else
        {
            cout << "Invalid vertex index. Please try again." << endl;
        }

        cout << "Add another edge? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');
}

void GraphAdjMatrix::BFS(int startID)
{
    if (startID < 0 || startID >= no_of_vertices)
    {
        cout << "Invalid start vertex." << endl;
        return;
    }

    bool* visited = new bool[no_of_vertices];
    fill(visited, visited + no_of_vertices, false);

    Queue q(no_of_vertices);
    q.enqueue(startID);
    visited[startID] = true;

    cout << "\nBFS Traversal: \n";
    cout << "Title\t\tAuthor\t\tGenre\t\tprice\n";
    while (!q.isEmpty())
    {
        int currIdx = q.dequeue();
        if (currIdx != -1)
        {
            vertices[currIdx].displayVertex();
            cout << endl;
            for (int j = 0; j < no_of_vertices; j++)
            {
                if (adjMatrix[currIdx][j] == 1 && !visited[j])
                {
                    q.enqueue(j);
                    visited[j] = true;
                }
            }
        }
    }
    cout << endl;
    delete[] visited;
}

void GraphAdjMatrix::DFS(int startID)
{
    if (startID < 0 || startID >= no_of_vertices)
    {
        cout << "Invalid start vertex." << endl;
        return;
    }
    bool* visited = new bool[no_of_vertices];
    std::fill(visited, visited + no_of_vertices, false);

    cout << "\nDFS Traversal: \n";
    cout << "Title\t\tAuthor\t\tGenre\t\tPrice\n";
    DFSRecursive(startID, visited);

    cout << endl;
    delete[] visited;
}

void GraphAdjMatrix::DFSRecursive(int node, bool visited[])
{
    visited[node] = true;
    vertices[node].displayVertex();
    cout << endl;

    for (int i = 0; i < no_of_vertices; i++)
    {
        if (adjMatrix[node][i] == 1 && !visited[i])
        {
            DFSRecursive(i, visited);
        }
    }
}*/

GraphAdjList::GraphAdjList()
{
    adjList = NULL;
    no_of_vertices = 0;
}

GraphAdjList::GraphAdjList(int nov)
{
    no_of_vertices = nov;
    adjList = new Node * [no_of_vertices];

    for (int i = 0; i < no_of_vertices; i++)
    {
        adjList[i] = NULL;
    }
}

GraphAdjList::~GraphAdjList()
{
    for(int i = 0; i < no_of_vertices; i++)
    {
        Node* curr = adjList[i];
        while(curr != NULL)
        {
            Node* temp = curr;
            curr = curr->next;
            delete temp;
        }
    }
    delete[] adjList;
}


void GraphAdjList::getVertices()
{
    cout << "\nEnter vertex details:\n";
    for (int i = 0; i < no_of_vertices; i++)
    {
        cout << "\nVertex " << i << ":" << endl;
        Vertex v;
        v.getVertex();
        adjList[i] = new Node(v, NULL);
    }
}

void GraphAdjList::getList()
{
    int source, destination;
    char choice;

    cout << "\n--- Enter Edges ---" << endl;
    do
    {
        cout << "Enter Source Vertex Index (0-" << no_of_vertices - 1 << "): ";
        cin >> source;
        cout << "Enter Destination Vertex Index (0-" << no_of_vertices - 1 << "): ";
        cin >> destination;

        if (source >= 0 && source < no_of_vertices && destination >= 0 && destination < no_of_vertices && source!=destination)
        {
            Node* newNode1 = new Node(adjList[destination]->vertex, adjList[source]->next);
            adjList[source]->next = newNode1;

            Node* newNode2 = new Node(adjList[source]->vertex, adjList[destination]->next);
            adjList[destination]->next = newNode2;

            cout << "Edge added between " << adjList[source]->vertex.mname << " and " << adjList[destination]->vertex.mname << "." << endl;
        }
        else if(source==destination)
        {
           cout<<"no same vertex have edge itself.\n`:";
        }
        else
        {
            cout << "Invalid vertices!\n";
        }
        cout << "Add another edge? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');
}

int GraphAdjList::getIndex(string vertexName)
{
    for(int i = 0; i < no_of_vertices; i++)
    {
        if(adjList[i]->vertex.mname == vertexName)
        {
            return i;
        }
    }
    return -1;
}


void GraphAdjList::BFS(int startID)
{
    if (startID < 0 || startID >= no_of_vertices)
    {
        cout << "Invalid start vertex." << endl;
        return;
    }

    bool* visited = new bool[no_of_vertices];
    std::fill(visited, visited + no_of_vertices, false);
    int k;
    while(1)
    {
       Queue q(no_of_vertices);
        q.enqueue(startID);
        visited[startID] = true;

        cout << "\nBFS Traversal: ";
        cout <<"\n MAnufacturer Name\tCOUNTRY\tManufacturer ID";
        while(!q.isEmpty())
        {
                int currIdx = q.dequeue();
                if(currIdx != -1)
                {
                        adjList[currIdx]->vertex.displayVertex();
                        Node* temp = adjList[currIdx]->next;
                        while(temp != NULL)
                        {
                                int neighborIndex = getIndex(temp->vertex.mname);
                                if(neighborIndex != -1 && !visited[neighborIndex])
                                {
                                        q.enqueue(neighborIndex);
                                        visited[neighborIndex] = true;
                                }
                                temp = temp->next;
                        }
                }
        }

        for (k = 0; k < no_of_vertices; k++)
        {
           if (visited[k] == false)
           {
              startID = k;
              break;
           }
        }
        if (k == no_of_vertices)
        {
           break;
        }
    }


    cout << endl;
    delete[] visited;
}

void GraphAdjList::DFS(int startID)
{
    if (startID < 0 || startID >= no_of_vertices)
    {
        cout << "Invalid start vertex." << endl;
        return;
    }
    int j;
    bool* visited = new bool[no_of_vertices];
    std::fill(visited, visited + no_of_vertices, false);
    while(1)
    {
       cout << "\nDFS Traversal: ";
       cout << "\nMAnufacturer Name\tCOUNTRY\tManufacturer ID";
       DFSRecursive(startID, visited);
       for(j=0;j<no_of_vertices;j++)
       {
          if(visited[j] == false)
          {
             startID=j;
             break;
          }
       }
       if( j == no_of_vertices)
       {
          break;
       }
       cout << endl;
    }
    delete[] visited;
}

void GraphAdjList::DFSRecursive(int node, bool visited[])
{
    visited[node] = true;
    adjList[node]->vertex.displayVertex();

    Node* temp = adjList[node]->next;
    while(temp != NULL)
    {
        int neighborIndex = getIndex(temp->vertex.mname);
        if(neighborIndex != -1 && !visited[neighborIndex])
        {
            DFSRecursive(neighborIndex, visited);
        }
        temp = temp->next;
    }
}
