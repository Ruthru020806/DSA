#include "header.h"
main()
{
   int n,start;
   cout<<"Enter number of vertex in graph: ";
   cin>>n;
   CGraph g(n);
   g.createGraph();
   g.displayGraph();
   CMST mst(&g);
   cout<<"Enter the start vertex: ";
   cin>>start;
   mst.prims(start);
}
