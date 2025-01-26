

#include <stdint.h>
#include <stdbool.h>

#define QUEUESIZE 5 // 20

typedef uint8_t byte;

struct QUEUE
{
 byte head;
 byte tail;
 byte buf[QUEUESIZE];
};


void init_q(struct QUEUE *pq);
int put_q(byte c, struct QUEUE *pq);
bool is_q_empty(struct QUEUE *pq);
bool is_q_full(struct QUEUE *pq);
int check_q(struct QUEUE *pq);
//int get_q(struct QUEUE *pq);
int get_q(struct QUEUE *pq, byte *data);

