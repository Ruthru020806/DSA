#include "head.h"

CAList::CAList(int *a,int c,int s)
{//calling paramaterised constructor
    capacity = c;
    size = s;
    arr=new int[capacity];
    for (int i=0;i<s;i++)
    {
       arr[i]=a[i];
    }
    for (int i=s;i<c;i++)
    {
       arr[i]=-1;
    }
}

CAList::~CAList()
{//calling destructor
    delete[] arr;
    arr=NULL;
    size=0;
}

int CAList::isFull()
{
    if(size == capacity)
       return 1;
    else
       return 0;
}

int CAList::isEmpty()
{
    if (size == 0)
       return 1;
    else
       return 0;
}

void CAList::display()
{
    if (isEmpty())
        cout << "List is empty." << endl;
    else {
        cout << "Elements in List: ";
        for (int i = 0; i < size; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
}

int CAList::searchElement(int ele)
{
   if(isEmpty())
      return -1;
   else
   {
      for (int i = 0; i < size; i++)
         if (arr[i] == ele)
            return i;
      return -2;
   }
}

int CAList::insertAtFirst(int ele)
{
   if (isFull())
   {
      return -1;
   }
   for (int i = size - 1; i >= 0; i--)
      arr[i + 1] = arr[i];
   arr[0] = ele;
   size++;
   return 1;
}

int CAList::insertAtlast(int ele)
{
   if(isFull())
   {
      return 0;
   }
   arr[size++] = ele;
   return 1;
}

int CAList::insertByPosition(int pos, int ele)
{
    if (pos <= 0 || pos > size + 1||isFull())
       return 0;
    else
    {
       for (int i = size; i >= pos; i--)
          arr[i] = arr[i-1];
       arr[pos - 1] = ele;
       size++;
       return 1;
    }
}

int CAList::insertBeforeElement(int a, int ele)
{
    int index = searchElement(ele);
    if (index == -1)
    {
       return -1;//List is Empty
    }
    else if (index != -2)
    {
        for (int i = size - 1; i >= index; i--)
            arr[i + 1] = arr[i];
        arr[index] = a;
        size++;
        return 1;
    }
    return 0;
}

int CAList::updateEle(int e1, int e)
{
   int index = searchElement(e1);
   if (index == -1)
   {
      return -1;//List is Empty
   }
   else if (index==-2)
   {
      return -2;//Element not found
   }
   else
   {
      arr[index] = e;
   }
}

int CAList::insertAfterElement(int a, int ele)
{
    int index = searchElement(ele);
    if (index != -1) {
        for (int i = size - 1; i > index; i--)
            arr[i + 1] = arr[i];
        arr[index + 1] = a;
        size++;
        return 1;
    }
    return 0;
}

int CAList::deleteAtFirst()
{
    if (isEmpty()) return 0;
    for (int i = 0; i < size - 1; i++)
        arr[i] = arr[i + 1];
    size--;
    return 1;
}

int CAList::deleteAtLast()
{
    if (isEmpty()) return 0;
    size--;
    return 1;
}

int CAList::deleteByPosition(int pos)
{
    if (isEmpty() || pos <= 0 || pos > size)
    {
       return 0;
    }
    else
    {
       for (int i = pos - 1; i <= size - 1; i++)
       {
          arr[i] = arr[i + 1];
          size--;
          return 1;
       }
    }
}

int CAList::deleteBeforeElement(int ele)
{
    int index = searchElement(ele);
    if (index <= 0) return 0;
    for (int i = index - 1; i < size - 1; i++)
        arr[i] = arr[i + 1];
    size--;
    return 1;
}

int CAList::deleteAfterElement(int ele)
{
    int index = searchElement(ele);
    if (index == -1 || index >= size - 1) return 0;
    for (int i = index + 1; i < size - 1; i++)
        arr[i] = arr[i + 1];
    size--;
    return 1;
}

void CAList::insertAtMiddle(int ele)
{
   int index;
   if(size%2==0)
      index=((size/2)+1)-1;
   else
      index=((size+1)/2)-1;
   for (int i = size - 1; i >= index; i--)
      arr[i + 1] = arr[i];
   arr[index] = ele;
   size++;
}

int CAList::deleteAtMiddle()
{
   int index;
   if(size==1)
   {
      return deleteAtFirst();
   }
   else
   {
      if(size%2==0)
         index=((size/2)+1)-1;
      else
         index=((size+1)/2)-1;
      if (size<=1) return 0;
      for (int i =index ; i < size - 1; i++)
         arr[i] = arr[i + 1];
      size--;
      return 1;
   }
}

void CAList::makeListEmpty()
{
   while(!isEmpty())
      deleteAtFirst();
}

int CAList::reverseElement()
{
   for(int i = size-1; i>=0;i--)
   {
      cout << arr[i] << " ";
   }
   cout << endl;
}
