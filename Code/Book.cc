#include <iostream>
#include <iomanip>
using namespace std;
#include <string>
#include "Book.h"

int Book::nextId = 1001;

Book::Book(string t, string a)    //ctor
{
  id     = nextId;
  ++nextId;
  title  = t;
  author = a;
  checkedIn = true;

  //cout<<"-- default ctor:  "<< id <<endl;
}

Book::Book(Book& orig)    //cpy ctor
{
  //cout<<"-- copy ctor:  "<< orig.id <<endl;

  id     = orig.id;
  title  = orig.title;
  author = orig.author;
  checkedIn = orig.checkedIn;
}

Book::~Book()     //dtor
{
  //cout<<"-- dtor:  "<< id <<endl;
}

int Book::getNextId() { return nextId; }    // static book id

void Book::print() const    // print a book
{
  if (isCheckedIn()==1){
    cout << setw(10) << left << id << setw(40) << left << title << setw(25) << author << left << setw(20)<<"Checked In"<< endl;
  }else{
    cout << setw(10) << left << id << setw(40) << left << title << setw(25) << author << left << setw(20)<<"Checked Out"<< endl;
  }
}


int Book::getId() const{      // return book id
  return id;
}

string Book::getAuthor() const{   // return book author
  return author;
}

bool Book::isCheckedIn() const{     // return check-in status
  return checkedIn;
}

void Book::checkIn(){     // check a book in
  checkedIn = true;
}
void Book::checkOut(){    // check a book out
  checkedIn = false;
}