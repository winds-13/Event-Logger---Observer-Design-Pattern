#ifndef BOOK_H
#define BOOK_H

class Book
{
  public:
    Book(string="", string="");
    Book(Book&);
    ~Book();
    void print() const;
    static int getNextId();
    int getId() const;
    string getAuthor() const;
    bool isCheckedIn() const;
    void checkIn();
    void checkOut();

  private:
    static int nextId;
    int id;
    string title;
    string author;
    bool checkedIn;
};

#endif
