#include <bits/stdc++.h>
using namespace std;

template <class T>
class node {
 public:
   T data;
   node * nxt;
   node * prv;
};

template <class T>
class DoublyLinkedList {
 public:
   node<T> * head;
   int sz;

   DoublyLinkedList() {
      head = NULL;
      sz=0;
   }

   node<T> *CreateNewNode( T val ) {
      node<T> *newNode = new node<T>;
      newNode->data = val;
      newNode->nxt = NULL;
      newNode->prv = NULL;
      return newNode;
   }

   void InsertAtHead( T val ) {
      sz++;
      node<T> *nd = CreateNewNode( val );
      if( head == NULL ) {
         head = nd;
         return;
      }
      node<T> *a = head;
      nd->nxt = a;
      a->prv = nd;
      head = nd;
   }

   void DeleteFromHead() {
      if ( head == NULL ) {
         cout<<"No node available\n";
         return;
      }
      node<T> *a = head;
      node<T> *b = head->nxt;
      delete a;
      if( b!=NULL ) {
         b->prv = NULL;
      }
      head = b;
      sz--;
   }

   int getSize() {
      return sz;
   }

   void Traverse() {
      node<T> *a = head;
      while( a!=NULL ) {
         cout<<a->data<<" ";
         a = a->nxt;
      }
      cout<<"\n";
   }
};

template <class T>
class Stack {
 public:
   DoublyLinkedList<T> dl;

   Stack() {


   }

   T top () {
      if( dl.getSize() == 0 ) {
         cout<<"Stack is empty\n";
         T a;
         return a;
      }
      return dl.head->data;
   }

   void pushToStack( T val ) {
      dl.InsertAtHead( val );
   }

   void popFromStack() {
      cout<<"Size = "<<dl.getSize()<<"\n";
      if( dl.getSize() == 0 ) {
         cout<<"Stack is empty\n";
         return;
      }
      dl.DeleteFromHead();
   }
};


int main() {
   Stack <double> st;
   st.pushToStack( 3.5 );
   cout<<st.top()<<"\n";
   st.pushToStack( 4.7 );
   cout<<st.top()<<"\n";
   st.pushToStack( 5.4 );
   cout<<st.top()<<"\n";

   st.popFromStack();
   cout<<st.top()<<"\n";
   st.popFromStack();
   cout<<st.top()<<"\n";
   st.popFromStack();
   cout<<st.top()<<"\n";
   st.popFromStack();
   cout<<st.top()<<"\n";

   Stack <char> st2;
   st2.pushToStack( 'a' );
   cout<<st2.top()<<"\n";
   st2.pushToStack( 'b' );
   cout<<st2.top()<<"\n";
   st2.pushToStack( 'c' );
   cout<<st2.top()<<"\n";

   st2.popFromStack();
   cout<<st2.top()<<"\n";
   st2.popFromStack();
   cout<<st2.top()<<"\n";
   st2.popFromStack();
   cout<<st2.top()<<"\n";
   st2.popFromStack();
   cout<<st2.top()<<"\n";
/*
*/
   //cout<<"Size -> "<<dl.getSize()<<"\n";
   return 0;
}
