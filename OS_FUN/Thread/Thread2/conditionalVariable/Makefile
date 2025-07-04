cc=gcc


bounded_buffer.out : bounded_buffer.o
	$(CC)  -o $@ bounded_buffer.o

bounded_buffer.o : boundedBuffer.c
	$(CC)  -c -o $@ boundedBuffer.c

clean:
	rm bounded_buffer.out bounded_buffer.o
