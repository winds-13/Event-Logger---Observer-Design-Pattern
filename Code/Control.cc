#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "Control.h"

Control::Control(){
  CheckInLogger* ci1 = new CheckInLogger("ci1");  //create and subscribe loggers
  library.subscribe(ci1);
  CheckOutLogger* co1 = new CheckOutLogger("co1");
  library.subscribe(co1);
}

Control::~Control(){};

void Control::launch()
{
  int bookId;
  int choice;

  initBooks();

  while (1) {
    view.showMenu(choice);

    if (choice == 0) 
      break;

    view.printStr("Book id: ");
    view.readInt(bookId);
    

    if (choice == 1){
      if(library.find(bookId) == NULL){
        cout<<endl;
        cout<<"Invalid Book id"<<endl;
        continue;
      }
      library.checkOut(library.find(bookId));

    }else if (choice == 2){
      if(library.find(bookId) == NULL){
        cout<<endl;
        cout<<"invalid book id"<<endl;
        continue;
      }
      library.checkIn(library.find(bookId));
    }

  }

  cout<<endl<<"in Library:"<<endl;
  library.print();
  cout<<endl<<endl;


}

void Control::initBooks()   // add books
{
  Book* b;

  b = new Book("Ender's Game", "Card, Orson Scott");
  library.add(b);
  //library.add(b);         //you can check duplicates if you want to


  b = new Book("Dune", "Herbert, Frank");
  library.add(b);
  b = new Book("Foundation", "Asimov, Isaac");
  library.add(b);
  b = new Book("Hitch Hiker's Guide to the Galaxy", "Adams, Douglas");
  library.add(b);
  b = new Book("1984", "Orwell, George");
  library.add(b);
  b = new Book("Stranger in a Strange Land", "Heinlein, Robert A.");
  library.add(b);
  b = new Book("Farenheit 451", "Bradbury, Ray");
  library.add(b);
  b = new Book("2001:  A Space Odyssey", "Clarke, Arthur C.");
  library.add(b);
  b = new Book("I, Robot", "Asimov, Isaac");
  library.add(b);
  b = new Book("Starship Troopers", "Heinlein, Robert A.");
  library.add(b);
  b = new Book("Do Androids Dream of Electric Sheep?", "Dick, Philip K.");
  library.add(b);
  b = new Book("Neuromancer", "Gibson, William");
  library.add(b);
  b = new Book("Ringworld", "Niven, Larry");
  library.add(b);
  b = new Book("Rendezvous with Rama", "Clarke, Arthur C.");
  library.add(b);
  b = new Book("Hyperion", "Simmons, Dan");
  library.add(b);
  
}

