CC = g++
CFLAGS = -Wall -O2
TARGET = hadamard
SRC = trasformata.cpp

all:
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

run: all
	ulimit -s unlimited && ./$(TARGET)

clean:
	rm -f $(TARGET)
