A3:	main.o Book.o Library.o Logger.o List.o View.o Control.o CheckInLogger.o CheckOutLogger.o
	g++ -o A3 main.o Book.o Library.o Logger.o List.o View.o Control.o CheckInLogger.o CheckOutLogger.o

main.o:	main.cc 
	g++ -c main.cc 

Book.o:	Book.cc Book.h 
	g++ -c Book.cc

Library.o:	Library.cc Library.h
	g++ -c Library.cc

Logger.o:	Logger.cc Logger.h
	g++ -c Logger.cc

CheckInLogger.o: CheckInLogger.cc Logger.h
	g++ -c CheckInLogger.cc

CheckOutLogger.o: CheckOutLogger.cc Logger.h
	g++ -c CheckOutLogger.cc

List.o:	List.cc List.h Book.h
	g++ -c List.cc

Control.o: Control.cc Control.h
	g++ -c Control.cc

View.o: View.cc View.h
	g++ -c View.cc

clean:
	rm -f *.o A3
