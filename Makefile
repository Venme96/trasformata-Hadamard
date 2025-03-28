CC = g++
CFLAGS = -Wall -O2 -Wno-unused-but-set-variable
TARGET = hadamard
SRC = trasformata2.cpp

all:
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

run: all
	bash -c "ulimit -s unlimited && ./$(TARGET)"

clean:
	rm -f $(TARGET)
