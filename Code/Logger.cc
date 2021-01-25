#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
using namespace std;

#include "Logger.h"
#include "Book.h"

Logger::Logger(string n) //ctor
{
    name = n;
   // cout<<"-- Logger ctor:  "<< name <<endl;
}

Logger::~Logger(){}     //dtor

/* void Logger::update(Book* b){
    if(b->isCheckedIn() == true){
        b->checkOut();
    }else{
        b->checkIn();
    }
   
} */

void Logger::printLogs(){       //print what's in this logger
    cout<<"In "<<name<<":"<<endl;
    bookList.print();
    cout<<endl;
}



