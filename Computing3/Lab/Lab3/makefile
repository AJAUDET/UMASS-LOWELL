CC = g++
CFLAGS = -Wall -g
OBJECTS = lab3.o 

program: $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o lab.exe

lab3.o:lab3.cpp 
	$(CC) $(CFLAGS) -c lab3.cpp 


clean:
	rm -f $(OBJECTS) lab3.exe