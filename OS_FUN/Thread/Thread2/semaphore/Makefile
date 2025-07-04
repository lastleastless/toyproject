cc=gcc
OBJS=B.o R.o
TARGET=mutexlock.out

$(TARGET):$(OBJS)
	$(CC) -o $@ $(OBJS)

B.o : badThread.c
	$(CC) -c -o $@ badThread.c

R.o : Routine.c
	$(CC) -c -o $@ Routine.c

clean:
	rm $(TARGET) $(OBJS)
