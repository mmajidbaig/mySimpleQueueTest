CC = gcc
CFLAGS = -Wall -Iunity -Isrc

all: ctest_queue

ctest_queue: src/cqueue.c test/ctest_queue.c unity/src/unity.c
	$(CC) $(CFLAGS) -o ctest_queue src/cqueue.c test/ctest_queue.c unity/src/unity.c
	

clean:
	rm -f ctest_queue