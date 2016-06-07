// ReverseDoubleLinkedList.cpp : Defines the entry point for the console application.
//

#include <cstdlib>
#include <iostream>
#include <string>

class Node
{
public:
   Node(int val) { value = val; next = NULL; prev = NULL; }
   ~Node() {}
   int value;
   Node *prev;
   Node *next;
};


class DoubleLinkedList
{
public:
   DoubleLinkedList() { head = NULL; tail = NULL; }
   void addNode(int value);
   void displayList();
   void reverseList();
private:
   Node *head;
   Node *tail;
};


void DoubleLinkedList::addNode(int value)
{
   Node *temp;
   if (head == NULL)
   {
      // Initialize the head and tail
      head = new Node(value);
      tail = head;
   }
   else
   {
      // Create a new node after the tail, set the new tail node, and set the tails previous node
      tail->next = new Node(value);
      temp = tail;
      tail = tail->next;
      tail->prev = temp;
   }
}


void DoubleLinkedList::displayList()
{
   Node *temp = head;
   std::cout << "List: ";
   // Loop through the list printing each value until the end is reached
   while (temp != NULL)
   {
      std::cout << temp->value << " ";
      temp = temp->next;
   }
   std::cout << std::endl;
}


void DoubleLinkedList::reverseList()
{
   // NULL<-[0]<->[1]<->[2]<->[3]->NULL
   //  [1]<-[0]->NULL
   //        [2]<-[1]<->[0]->NULL
   //  [3]<-[2]<->[1]<->[0]->NULL
   // NULL<-[3]<->[2]<->[1]<->[0]->NULL
   Node *iter = head;
   Node *temp = NULL;
   // Loop through the entire linked list starting at the head
   while (iter != NULL)
   {
      // Swap the prev/next pointers on each node
      temp = iter->prev;
      iter->prev = iter->next;
      iter->next = temp;
      // Increment the iter, use prev since the pointers have been reversed
      iter = iter->prev;
   }
   // After swapping all the links, need to reverse the head and tail
   temp = head;
   head = tail;
   tail = temp;
}


int main()
{
   DoubleLinkedList list;
   for (int i = 0; i < 7; ++i)
   {
      list.addNode(i);
   }
   list.displayList();
   list.reverseList();
   list.displayList();
   list.addNode(10);
   list.displayList();
   list.reverseList();
   list.displayList();
   system("PAUSE");
    return 0;
}

