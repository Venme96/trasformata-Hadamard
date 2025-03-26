CC = g++
CFLAGS = -Wall -O2
TARGET = hadamard
SRC = trasformata.cpp
# Regola principale: compila il programma
all:
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

# Comando per pulire i file compilati
clean:
	rm -f $(TARGET)
