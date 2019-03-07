#ifndef __ARRAY_STACK_H__
#define __ARRAY_STACk_H__

//interface 
#include "stdlib.h"
#include "stdio.h"

#define STACK_MALLOC(size) malloc(size)
#define STACK_FREE(size) free(sizeof)
#define STACK_MEMCPY(a,b,c) memcpy(a,b,c)
#define STACK_PRINT(info) printf(info)

typedef struct _array_stack
{
	int size;/*栈的大小*/
	int pos;/*当前存储元素的个数，即栈顶元素下表*/
	int *array;/*数据存储区*/
}ArrayStack;

#define arrayStack_size(arrayStack) (arrayStack->size)
#define arrayStack_is_empty(arrayStack) (arrayStack->pos == -1)
#define arrayStack_is_full(arrayStack)  (arrayStack->pos == (arrayStack->size-1))

extern ArrayStack * arrayStack_create(int size);
extern void arrayStack_destory(ArrayStack * parrStack);
extern int arrayStack_pop(ArrayStack *parrStack);
extern int arrayStack_push(ArrayStack *parrStack,int data);
extern int arrayStack_push_new(ArrayStack*parrStack,int data);
extern void arrayStack_dump(stArrayStack *parrStack);


#endif