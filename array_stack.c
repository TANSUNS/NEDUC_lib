#include "array_stack.h"

ArrayStack * arrayStack_create(int size)
{
	ArrayStack *parrStack = NULL;

	parrStack = (ArrayStack *)STACK_MALLOC(sizeof(ArrayStack));
	if (parrStack == NULL)
	{
		return NULL;
	}
	
	parrStack->size = size;
	parrStack->pos = -1;
	parrStack->array = (int *)STACK_MALLOC(sizeof(int)*size);
	if(parrStack->array == NULL)
	{
		STACKFREE(parrStack);
		return NULL;
	}

	return parrStack;
}
/*销毁顺序栈*/
void arrayStack_destory(ArrayStack * parrStack)
{
	if(parrStack == NULL)
	{
		return;
	}

	if (parrStack->array != NULL)
	{
		STACK_FREE(parrStack->array);
	}

	STACK_FREE(parrStack);
	return;
}
/*出栈*/
int arrayStack_pop(ArrayStack *parrStack)
{
	int data = 0;

	if(arrayStack_is_empty(parrStack))
	{
		return -1;
	}
    data = parrStack->array[parrStack->pos];
	parrStack->pos--;

	return data;
}
/*入栈*/
int arrayStack_push(ArrayStack *parrStack,int data)
{
	if(arrayStack_is_full(parrStack))
	{
		return -1;
	}

    parrStack->pos++;
	parrStack->array[parrStack->pos] = data;

	return 0;
}

int arrayStack_push_new(ArrayStack*parrStack,int data)
{
	int *ptmp = NULL;

	/*如果栈不满，直接插入*/
	if(!arrayStack_is_full(parrStack))
	{
		return arrayStack_push(parrStack,data);
	}

	/*如果栈已经满，申请内存*/
    ptmp = (int *)STACK_MALLOC(2*parrStack->size*sizeof(int));
	if (ptmp == NULL)
	{
		return -1;
	}

	STACK_MEMCPY(ptmp,parrStack->array,parrStack->size*sizeof(int));

	STACK_FREE(parrStack->array);

    parrStack->array = ptmp;
	parrStack->size = 2*parrStack->size;
	parrStack->pos++;
    parrStack->array[parrStack->pos] = data;

	return ;
}

void arrayStack_dump(stArrayStack *parrStack)
{
	int i = 0;

	if (arrayStack_is_empty(parrStack))
	{
		STACK_PRINT("\r\n arrayStack is empty.");
		return;
	}
	STACK_PRINT("\r\narrayStack size = %d,pos= %d,",
			parrStack->size,parrStack->pos);
	for(i = 0; i <= parrStack->pos; i++)
	{
		STACK_PRINT("\r\narry[%d] = %d",i,parrStack->array[i]);
	}
}

/*example 

int main()
{
	int i = 0;
	int ret = 0;
	ArrayStack * parrStack = NULL;

	STACKPRINT("\r\n create size = 4 arrayStack.");

	parrStack = arrayStack_create(4);
	if (parrStack == NULL)
	{
	    STACKPRINT("\r\n create size = 4 arrayStack faided.");
		return 0;
	}

	for (i = 0; i < 5; i++)
	{
		ret = arrayStack_push(parrStack,i);
		if(ret != 0)
		{
	        STACKPRINT("\r\n push size = %d arrayStack faided.",i);

		}
	}
	arrayStack_dump(parrStack);
		
	ret = arrayStack_push_new(parrStack,4);
	if(ret != 0)
	{
	        STACKPRINT("\r\n push size = %d arrayStack faided.",4);
    }
	arrayStack_dump(parrStack);

	arrayStack_destory(parrStack);
    
	return;
}
*/