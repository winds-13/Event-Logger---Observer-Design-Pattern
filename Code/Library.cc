#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "Library.h"

Library::Library(){};       //ctor

Library::~Library(){           //dtor
    for (int i=0; i<v.size(); i++){
        v[i]->printLogs();
        delete v[i];
    }

    bookList.cleanup();
}

void Library::subscribe(Logger* logger){    // add loggers in vector
    v.push_back(logger);
}

void Library::notify(Book* b){      // update book check-in status
    for (int i=0; i<v.size(); i++){
        v[i]->update(b);
    }
}

void Library::add(Book* b){         // add a book
    bookList.add(b);
    notify(b);
}

void Library::checkOut(Book* b){       // check a book out
    cout<<"in library, checking out"<<endl;
    b->checkOut();
    notify(b);
}
void Library::checkIn(Book* b){     // check a book in
    cout<<"in library, checking in"<<endl;
    b->checkIn();
    notify(b);
}

void Library::print(){  // print all books
    bookList.print();
}

Book* Library::find(int id){        //return a book pointer
    return bookList.find(id);
}