#include "../src/cqueue.h"

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

typedef uint8_t byte;

//#define QUEUESIZE 5 // Reduced size for easier testing


// Display the queue's contents
void display_q(struct QUEUE *pq) {
    if (is_q_empty(pq)) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue contents: ");
    uint16_t i = pq->head;
    while (i != pq->tail) {
        printf("%d ", pq->buf[i]);
        i = (i + 1) % QUEUESIZE;
    }
    printf("\n");
}

// Main function to test the queue
int main() {
    struct QUEUE q;
    init_q(&q);//initializing the queue

    // Test adding elements to the queue
    printf("Adding elements to the queue:\n");
    for (byte i = 1; i <= 5; i++) {
        if (put_q(i, &q) == 0) {
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
}
