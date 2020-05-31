CC = g++ 
CFLAGS  = -Wall 

TARGET = P0 
OBJFILES = main.o tree.o

$(TARGET): $(OBJFILES)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJFILES)

main.o: main.cpp 
	g++ -c main.cpp

tree.o: tree.cpp tree.h
	g++ -c tree.cpp

clean:
	rm -f $(OBJFILES) $(TARGET)

