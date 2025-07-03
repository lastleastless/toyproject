cc = gcc
OBJS = badThread.o Routine.o
TARGET = mutex.out

$(TARGET) : $(OBJS)
	$(CC) -o $@ $(OBJS)

badThread.o : badThread.c
	$(CC) -c -o $@  badThread.c
Routine.o : Routine.c
	$(CC) -c -o $@  Routine.c

clean:
	rm $(TARGET) $(OBJS)
