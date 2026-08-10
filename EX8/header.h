#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Vertex
{
    friend class Node;
    friend class GraphAdjMatrix;
    friend class GraphAdjList;

private:
    string mname,country;
    int mid;

public:
    Vertex();
    Vertex(string, string, int);
    ~Vertex();

    void getVertex();
    void displayVertex();
};

class Node
{
    friend class Vertex;
    friend class GraphAdjList;

private:
    Vertex vertex;
    Node* next;
public:
    Node();
    Node(Vertex, Node*);
    ~Node();

    void displayNode();
};

class GraphAdjMatrix
{
private:
    Vertex* vertices;
    int no_of_vertices;
    int** adjMatrix;
    void DFSRecursive(int, bool*);

public:
    GraphAdjMatrix();
    GraphAdjMatrix(int);
    ~GraphAdjMatrix();

    void getMatrix();
    void getVertices();

    void DFS(int);
    void BFS(int);
};

class GraphAdjList
{
private:
    Node** adjList;
    int no_of_vertices;
    int getIndex(string);
    void DFSRecursive(int, bool*);

public:
    GraphAdjList();
    GraphAdjList(int);
    ~GraphAdjList();

    void getList();
    void getVertices();

    void DFS(int);
    void BFS(int);
};

class Queue
{
private:
    int* queuearr;
    int capacity;
    int front;
    int rear;

public:
    Queue(int);
    ~Queue();
    int enqueue(int);
    int dequeue();
    int isFull();
    int isEmpty();
};
