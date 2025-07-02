cc = gcc
OBJS = runner.o runner2.o
TARGET = thread.out

$(TARGET) : $(OBJS)
	$(CC) -o $@ $(OBJS)

runner.o : runner.c
	$(CC) -c -o runner.o runner.c

runner2.o : runner2.c
	$(CC) -c -o runner2.o runner2.c

clean:
	rm $(OBJS) $(TARGET)
