/*************************************************************************
 > File Name: list_queue.h
 > Author:  jinshaohui
 > Mail:    jinshaohui789@163.com
 > Time:    18-10-13
 > Desc:    
 ************************************************************************/

#ifndef LINK_LIST_QUEUE_H
#define LINK_LIST_QUEUE_H
#include "rtthread.h"

#define L_QUEUE_MALLOC(size) rt_malloc(size)
#define L_QUEUE_FREE(size) rt_free(size);
#define L_QUEUE_PRINT(info) rt_kprintf(info);


typedef struct _list_queue_node
{
	int data;
	struct _list_queue_node *next;
}queue_node;

typedef struct _list_queue
{
	int num;
	queue_node *head;
	queue_node *tail;
}list_queue;

#define list_queue_is_empty(queue) ((queue->num) == 0)

extern list_queue *list_queue_create(void);
extern void list_queue_destroy(list_queue*queue);
extern int list_queue_enqueue(list_queue *queue,int data);
extern int list_queue_dequeue(list_queue *queue,int *data);
extern void list_queue_dump(list_queue*queue);

#endif
