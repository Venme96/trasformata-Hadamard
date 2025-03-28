CC = g++
CFLAGS = -Wall -O2
TARGET = hadamard
SRC = trasformata2.cpp

all:
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

//run: all
//	ulimit -s unlimited && ./$(TARGET)

clean:
	rm -f $(TARGET)
