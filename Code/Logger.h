#ifndef LOGGER_H
#define LOGGER_H

#include <string>
#include <vector>
using namespace std;
#include "Book.h"
#include "List.h"
class Logger
{
  public:
    Logger(string="");
    virtual ~Logger();
    virtual void update(Book* b) = 0;
    void printLogs();

  protected:
    List bookList;

  private:
    string name;

};

class CheckInLogger : public Logger{
  public:
    CheckInLogger(string="");
    virtual ~CheckInLogger();
    virtual void update(Book* b);
};

class CheckOutLogger : public Logger{
  public:
    CheckOutLogger(string="");
    virtual ~CheckOutLogger();
    virtual void update(Book* b);
};

#endif