
# executable file to create and its dependancies
prog : driver_phase1.o Container.o
	g++ -std=c++11 -o prog driver_phase1.o

# file dependencies
driver.o : Container.h
	g++ -std=c++11 -c driver_phase1.cpp
Container.o : Container.h
	g++ -std=c++11 -c Container.cpp


# remove all object and executable files
clean:
	rm -f *.o
	rm prog
