cc=gcc
TARGET=philosopher.out

$(TARGET) : philosopher.o
	$(CC) -o $@ philosopher.o
philosopher.o : philosopher.c
	$(CC) -c -o $@ philosopher.c

clean:
	rm $(TARGET) philosopher.o

