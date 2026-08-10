#include<iostream>
#include<math.h>
#include<climits>
using namespace std;
class CStudent
{
   friend class CMST;
   friend class CPQMinHeap;
   friend class CGraph;
   private:
      int rollno;
      string name;
      int priority;
   public:
      CStudent(){}
      CStudent(int r, string n,int p):rollno(r),name(n),priority(p){}
      ~CStudent(){}
      void display();
};
class CGraph
{
   friend class CMST;
   friend class CPQMinHeap;
   private:
      int noOfVertex;
      CStudent *vertices;
      int **adjMatrix;
   public:
      CGraph(int);
      ~CGraph();
      void createGraph();
      void displayGraph();
};
class CPQMinHeap
{
   friend class CMST;
   private:
      CStudent *heap;
      int capacity;
      int heapsize;
   public:
      CPQMinHeap(int);
      ~CPQMinHeap();
      int isFull();
      int isEmpty();
      int insert(CStudent);
      int deleteMin();
      CStudent returnMin();
      void percolateUp(int);
      void percolateDown(int);
      void decreaseKeyWith(int,int);
      void displayHeap();
};
class CMST
{
   private:
      int noOfVertex;
      CStudent *vertex;
      bool *known;
      int *dv;
      int *pv;
      CGraph *graph;
   public:
      CMST(CGraph *g);
      ~CMST();
      void prims(int);
};
