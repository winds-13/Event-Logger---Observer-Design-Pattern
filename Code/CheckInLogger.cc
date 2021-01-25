#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
using namespace std;

#include "Logger.h"
#include "Book.h"

CheckInLogger::CheckInLogger(string n):Logger("Checked-in"){};//ctor

CheckInLogger::~CheckInLogger(){};//dtor

void CheckInLogger::update(Book* b){        // update book check-in status in list
    if(b->isCheckedIn()==1){
        bookList.add(b);
        //cout<<"---in checkinlogger, book checked in, add to list---"<<endl;
    }else{
        bookList.del(b->getId());
        //cout<<"---in checkinlogger, book checked out, del from list---"<<endl;
    }
}
