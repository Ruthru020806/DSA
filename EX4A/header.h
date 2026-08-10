#include<iostream>
#include<string>
using namespace std;

class FM_data
{
   friend class CircularQueue;
   private:
      string fmname;
      int fmid;
      string country;
      int aircraftcount;
   public:
      FM_data();
      FM_data(string b,int m,string p,int r);
      void displaydat();
};

class CircularQueue
{
   private:
      FM_data* arr;
      int capacity;
      int front;
      int rear;
      int count;

   public:
      CircularQueue(int);
      ~CircularQueue();
      int enqueue(FM_data);
      int dequeue();
      int peekFront();
      int peekRear();
      int display();
      int makeQueueEmpty();
      int isFull();
      int isEmpty();
      int Size();
};
