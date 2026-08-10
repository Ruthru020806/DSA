#include<iostream>
using namespace std;
class CAList
{
    int *arr;
    int capacity;
    int size;
  public:
    CAList(int *,int ,int);
    ~CAList();
    //list detail operations
    int isFull();
    int isEmpty();
    void display();
    int searchElement(int);
    void makeListEmpty();
    int updateEle(int,int);
    //list insertion operation
    int insertAtFirst(int);
    int insertAtlast(int);
    int insertByPosition(int, int);
    int insertBeforeElement(int, int);
    int insertAfterElement(int, int);
    void insertAtMiddle(int);
    //list deletion operation
    int deleteAtFirst();
    int deleteAtLast();
    int deleteByPosition(int);
    int deleteBeforeElement(int);
    int deleteAfterElement(int);
    int deleteAtMiddle();
    int reverseElement();
};
