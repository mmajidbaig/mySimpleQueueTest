#include "../unity/src/unity.h"
#include "../src/cqueue.h"

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>


void setUp() {}
void tearDown() {}


//#define QUEUESIZE 5 // Reduced size for easier testing

void display_q(struct QUEUE *pq)
 {
    printf(" display\n");
    if (is_q_empty(pq)) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue contents: ");
    uint16_t i = pq->head;
    while (i != pq->tail) {
        printf("%d ", pq->buf[i]);
        i = (i + 1)% QUEUESIZE;
    }
    printf("\n");
}

void test_queue_initialization()
	 {
    struct QUEUE q;
    init_q(&q);
    TEST_ASSERT_NOT_NULL(&q);
    TEST_ASSERT_EQUAL_INT(0, q.head);
    TEST_ASSERT_EQUAL_INT(0, q.tail);
    TEST_ASSERT_EQUAL_INT(5, QUEUESIZE);
  }


void test_fill_queue() {
    
    struct QUEUE q;
    init_q(&q);
    //display_q(&q);
    TEST_ASSERT_TRUE(is_q_empty(&q));
    TEST_ASSERT_FALSE(put_q(10,&q));
    TEST_ASSERT_FALSE(put_q(20,&q));
       
       
}



// Display the queue's contents


// Main function to test the queue
int main() {
    struct QUEUE q;
    init_q(&q);//initializing the queue
		printf("My testing code \n");
		display_q(&q);
		
		UNITY_BEGIN();
  	RUN_TEST(test_queue_initialization);
  	RUN_TEST(test_fill_queue);
  	display_q(&q);
    return UNITY_END();
		
    // Test adding elements to the queue
    /*
    printf("Adding elements to the queue:\n");
    for (byte i = 1; i <= 5; i++) {
        if (put_q(i, &q)==0) {
            printf("Added %d\n", i);
            } else {
            printf("Queue is full, could not add %d\n", i);
        }
    }

    display_q(&q);
    

    // Test removing elements from the queue
    printf("\nRemoving elements from the queue:\n");
    byte data;
    for (int i = 0; i < 5; i++) {
        if (get_q(&q, &data) == 0) {
            printf("Removed %d\n", data);
        } else {
            printf("Queue is empty, could not remove element.\n");
        }
    }

    display_q(&q);
  
    return 0;
    */
}
