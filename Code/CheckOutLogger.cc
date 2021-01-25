#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
using namespace std;

#include "Logger.h"
#include "Book.h"

CheckOutLogger::CheckOutLogger(string n):Logger("Checked-out"){};   //ctor

CheckOutLogger::~CheckOutLogger(){};        //dtor

void CheckOutLogger::update(Book* b){   // update book check-in status in list
    if(b->isCheckedIn()==0){
        bookList.add(b);
        //cout<<"---in checkoutlogger, book checked out, add to list---"<<endl;
    }else{
        bookList.del(b->getId());
        //cout<<"---in checkoutlogger, book checked in, del from list---"<<endl;
    }
}