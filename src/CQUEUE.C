#include "cqueue.h"
//#include <stdbool.h>
#include <stdio.h>

// Function to initialize the queue 


void init_q(struct QUEUE *pq)
{
 pq->head = pq->tail = 0;
}



// Function to check if the queue is empty
bool is_q_empty(struct QUEUE *pq) {
    
    return (pq->head == pq->tail);
        
}

// Function to check if the queue is full
bool is_q_full(struct QUEUE *pq) {
     if((pq->tail + 1) % QUEUESIZE== pq->head)
     {
     	 return true; 
     }
     return false;
}


int put_q(byte c, struct QUEUE *pq)
{
	 //byte t;
	if (is_q_full(pq)) {
        return -1; // Queue is full
    }
 	 pq->buf[pq->tail] = c;
   pq->tail = (pq->tail + 1)% QUEUESIZE;
   return 0;//Success
 
}

int check_q(struct QUEUE *pq)
{
 if (pq->head != pq->tail)
	return 1;
 return 0;
}


/*int get_q(struct QUEUE *pq)
{
 int c;

 if (pq->head != pq->tail)
 {
   c = pq->buf[pq->head++];
   if (pq->head == QUEUESIZE)
	pq->head = 0;
   return c;
 }
 return -1;
}
*/

int get_q(struct QUEUE *pq, byte *data) {
    if (is_q_empty(pq)) {
        printf(" get_q: queue empty\n");
        return -1; // Queue is empty
        
    }
    *data = pq->buf[pq->head];
  	pq->head = (pq->head + 1) % QUEUESIZE;
  	printf(" get_q: queue data :%d \n",*data);
    return 0; // Success
}
