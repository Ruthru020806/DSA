#include "header.h"
FM_data::FM_data()
{
   fmname="";
   fmid=0;
   country="";
   aircraftcount=0;
}
FM_data::FM_data(string b,int m,string p,int r)
{
   fmname= b;
   fmid = m;
   country = p;
   aircraftcount = r;
}

void FM_data::displaydat()
{
   cout<< fmname<<"\t"<<fmid<<"\t"<<country<<"\t"<<aircraftcount<<endl;
}

// Circular Queue definitions


CircularQueue::CircularQueue(int size)
{
   capacity = size;
   front = rear = -1;
   arr = new FM_data[capacity];
}

CircularQueue::~CircularQueue()
{
   delete []arr;
   front = rear = -1;
   capacity = 0;
}

int CircularQueue::isEmpty()
{
   if(front == -1 && rear ==-1)
   {
      return 1;
   }
   else
   {
      return 0;
   }
}

int CircularQueue::isFull()
{
   if((rear+1)%capacity==front)
   {
      return 1;
   }
   else
   {
      return 0;
   }
}

int CircularQueue::enqueue(FM_data e)
{
   if(isFull())
   {
      return -1;
   }
   else if(isEmpty())
   {
      front = rear = 0;
      arr[rear] = e;
      return 0;
   }
   else
   {
      rear = (rear+1)%capacity;
      arr[rear]=e;
      return 1;
   }
}

int CircularQueue::dequeue()
{
   if(isEmpty())
   {
      return -1;
   }
   else if(front == rear)
   {
      arr[front] = FM_data();
      front = rear = -1;
      return 1;
   }
   else
   {
      cout << "Dequeued Element : \n";
      arr[front].displaydat();
      front=(front+1)%capacity;
      return 2;
   }
}

int CircularQueue::peekFront()
{
   if(isEmpty())
   {
      return -1;
   }
   arr[front].displaydat();
   return 1;
}

int CircularQueue::peekRear()
{
   if(isEmpty())
   {
      return -1;
   }
   arr[rear].displaydat();
   return 1;
}

int CircularQueue::makeQueueEmpty()
{
   if(isEmpty())
   {
      return -1;
   }
   else
   {
      front = rear= -1;
      return 1;
   }
}

int CircularQueue::display()
{
   if(isEmpty())
   {
      return -1;
   }
   else
   {
      int i = front;
      int s = Size();
      cout << "===========Queue contents(Front to Rear)===========\n";
      cout <<"Name  |  ID  |  Country  |  Aircraft Count \n";
      for(int k=0;k<s;k++)
      {
         arr[i].displaydat();
         i=(i+1)%capacity;
      }
      cout<<"\n====================================================\n";
      return 1;
   }
}
int CircularQueue::Size()
{
   return (front+1)%capacity;
}
