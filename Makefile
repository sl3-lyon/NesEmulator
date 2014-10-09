CC=g++
CXXFLAGS=-std=c++1y -Wall -pedantic
EXEC=emulator

emulator: clean
	$(CC) $(CXXFLAGS) *.cc -o $(EXEC)

clean:
	rm -rf *.o *.h.gch a.out $(EXEC)
