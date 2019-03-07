#ifndef __ARRAY_QUEUE_H__
#define __ARRAY_QUEUE_H__

//interface 
#include "stdio.h"
#include "stdlib.h"

#define QUEUE_MALLOC(size) malloc(size)
#define QUEUE_FREE(size)  free(size)
#define QUEUE_PRINT(info) printf(info)

// private 
typedef struct _array_queue
{
	int size;/*队列的大小*/
	int num; /*当前存储数据的大小*/
	int head;/*队列的头*/
	int tail;/*队列的尾*/
	int *array;/*数据存储区*/
}array_queue;

//APIS
extern array_queue * array_queue_create(int size);
extern void array_queue_destory(array_queue *queue);
extern int array_queue_enqueue(array_queue *queue,int data);
extern int array_queue_dequeue(array_queue * queue,int *data);
extern void array_queue_dump(array_queue *queue);

#define array_queue_is_empty(array_queue) (array_queue->num == 0)
#define array_queue_is_full(array_queue)  ((array_queue->num) == (array_queue->size))

#endif
