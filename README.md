# my Simple Queue Project  in C
This project implements a simple queue module in C using Unity Framework for testing(TDD)in the Git repository

## Features
- Initialize a queue with a specified capacity.
- Enqueue and dequeue elements.
- Check if the queue is empty or full.

## The project includes  
- Note: for Testing Purpose QUEUESIZE is defined as 5 only.
-  test for: 
		-is_queue_empty: check if queue is empty.
		-queue_initialization : Initializing the queue
  	-test_fill_queue: Putting values in the queue
  	-de_queue: Removing the values from the queue
  	-is_queue_full: Checking if queue is full
- Code of failing test.
-Code to pass the test.
- Refactoring 

## Testing Framework
The project uses the Unity testing framework for unit testing. Run the tests using the provided Makefile.

## Main code 
Include `cqueue.h` and link the `cqueue.c` source file in the project.

## Testing code  
Include `ctest_queue.c' source file in the project.
