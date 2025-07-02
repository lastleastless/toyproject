cc = gcc
OBJS = badthread.o routine.o
TARGET = badex.out

$(TARGET) : $(OBJS)
	$(CC) -o $@ $(OBJS)

badthread.o : badThread.c
	$(CC) -c -o badthread.o badThread.c

routine.o : Routine.c
	$(CC) -c -o routine.o Routine.c


clean:
	rm $(OBJS) $(TARGET)
