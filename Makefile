
# executable file to create and its dependancies
#Gabriel Sencion 10/13/25 adding Files 
prog: driver_phase1.o Container.o File.o
	g++ -o prog driver_phase1.o Container.o File.o

driver_phase1.o: driver_phase1.cpp Container.h File.h
	g++ -c driver_phase1.cpp

Container.o: Container.cpp Container.h
	g++ -c Container.cpp

File.o: File.cpp File.h
	g++ -c File.cpp

clean:
	rm -f *.o prog
	
#Gabriel Sencion 10/15/25 rewrote make file