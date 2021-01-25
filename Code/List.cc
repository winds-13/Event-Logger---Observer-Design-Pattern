#include <iostream>
using namespace std;

#include "List.h"


List::List() : head(NULL) { }   //constructor

List::~List()       //destructor
{
  Node* currNode;
  Node* nextNode;

  currNode = head;

  while (currNode != NULL) {    
    nextNode = currNode->next;
    delete currNode;        // only the nodes
    currNode = nextNode;
  }
}

void List::add(Book* b)     // add a book
{
  
  Node* tmpNode;
  Node* currNode;
  Node* prevNode;

  tmpNode = new Node;
  tmpNode->data = b;
  tmpNode->next = NULL;

  currNode = head;
  prevNode = NULL;

  while (currNode != NULL) {
    if (b->getAuthor() <= currNode->data->getAuthor()){
      if(currNode->data == b){                // check for duplicates
        cout<<" duplicate book. book id: " <<b->getId()<<endl; 
        delete tmpNode;         
        return;
      }
      break;
    }
     

    prevNode = currNode;
    currNode = currNode->next;
  }

  if (prevNode == NULL)       // if add to head
    head = tmpNode;
  else
    prevNode->next = tmpNode;

  tmpNode->next  = currNode;

}

void List::del(int bId)       // delete a book
{
  Node* currNode;
  Node* prevNode;

  currNode = head;
  prevNode = NULL;

  while (currNode != NULL) {
    if (currNode->data->getId() == bId)
      break;

    prevNode = currNode;
    currNode = currNode->next;
  }

  // when do we get here?  2 cases:  we found the data, or we didn't

  if (currNode == NULL) {
    return;
  }

  if (prevNode == NULL)
    head = currNode->next;
  else
    prevNode->next = currNode->next;

  delete currNode; 

}

void List::print() const    //print a book's information
{
  Node* currNode = head;

  while (currNode != NULL) {
    currNode->data->print();
    currNode = currNode->next;
  }
}

Book* List::find(int id){   // return a book pointer
  Node* cur = head;
  while (cur != NULL) {
    if (cur->data->getId() == id){
      return cur->data;
    }
    cur = cur->next;
  }
  return NULL;
}

void List::cleanup(){     //only delete data, not nodes
  Node* currNode;
  Node* nextNode;

  currNode = head;

  while (currNode != NULL) {      
    nextNode = currNode->next;
    delete currNode->data;
    currNode = nextNode;
  }
}

