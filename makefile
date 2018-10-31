airline : main.o planes.o plane.o flights.o flight.o crew.o member.o pilot.o cabin.o copilot.o
	g++ main.o planes.o plane.o flights.o flight.o crew.o member.o pilot.o cabin.o copilot.o -o airline

main.o : main.h flights.h flight.h crew.h planes.h header.h member.h plane.h
	g++ -c $*.cpp

planes.o : planes.h plane.h
	g++ -c $*.cpp

plane.o : plane.h
	g++ -c $*.cpp

flights.o : flights.h header.h crew.h planes.h member.h plane.h
	g++ -c $*.cpp

flight.o : flight.h header.h
	g++ -c $*.cpp

crew.o : crew.h header.h member.h
	g++ -c $*.cpp

pilot.o : pilot.h member.h
	g++ -c $*.cpp

cabin.o : cabin.h member.h
	g++ -c $*.cpp

copilot.o : copilot.h member.h
	g++ -c $*.cpp

member.o : member.h
	g++ -c $*.cpp

run : airline
	./airline

clean : 
	rm *.o airline