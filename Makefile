CC = g++
CFLAGS = -Wall -O0 -g -Wno-unused-but-set-variable
TARGET = hadamard
SRC = trasformata2.cpp

all: esempio_piccolo esempio_tempi esempio_sketch_denso

esempio_sketch_denso: esempio_sketch_denso.cpp
	$(CC) $(CFLAGS) esempio_sketch_denso.cpp -o esempio_sketch_denso -lblas

esempio_piccolo: esempio_piccolo.cpp $(SRC)
	$(CC) $(CFLAGS) esempio_piccolo.cpp $(SRC) -o esempio_piccolo

esempio_tempi: esempio_tempi.cpp $(SRC)
	$(CC) $(CFLAGS) esempio_tempi.cpp $(SRC) -o esempio_tempi

run: all
	./$(TARGET)"

clean:
	rm -f $(TARGET)
