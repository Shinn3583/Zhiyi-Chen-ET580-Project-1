# executable file to create and its dependancies
# Gabriel Sencion 10/13/25 adding Files
# Default build now uses Phase 2 G.G
prog: driver_phase2.o Container.o File.o
	g++ -o prog driver_phase2.o Container.o File.o

# Optional: compile Phase 1 if professor wants to recheck it
prog_phase1: driver_phase1.o Container.o File.o
	g++ -o prog_phase1 driver_phase1.o Container.o File.o

driver_phase1.o: driver_phase1.cpp Container.h File.h
	g++ -c driver_phase1.cpp

driver_phase2.o: driver_phase2.cpp Container.h File.h
	g++ -c driver_phase2.cpp

Container.o: Container.cpp Container.h
	g++ -c Container.cpp

File.o: File.cpp File.h
	g++ -c File.cpp

prog_phase3: driver_phase3.o Container.o File.o Algorithms.o
	g++ -o prog_phase3 driver_phase3.o Container.o File.o Algorithms.o

driver_phase3.o: driver_phase3.cpp Container.h File.h Algorithms.h
	g++ -c driver_phase3.cpp

Algorithms.o: Algorithms.cpp Algorithms.h
	g++ -c Algorithms.cpp

clean:
	rm -f *.o prog prog_phase1 prog_phase3
# Gabriel Sencion 10/15/25 rewrote make file
# Giankarlo Gomez 10/21/25 updated make file for Phase 2
# Ruoming Ye 10/28/25 updated make file for Phase 3