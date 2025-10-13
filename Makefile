
# executable file to create and its dependancies
#Gabriel Sencion 10/13/25 adding Files 
prog : driver_phase1.o Container.o Files.o        
	g++ -std=c++11 -o prog driver_phase1.o Files.o Container.o

# file dependencies
driver.o : Container.h Files.h driver_phase1.cpp
	g++ -std=c++11 -c driver_phase1.cpp

Container.o : Container.h Container.cpp
	g++ -std=c++11 -c Container.cpp

Files.o: Files.cpp Files.h
	g++ -c Files.cpp


# remove all object and executable files
clean:
	rm -f *.o
	rm prog
