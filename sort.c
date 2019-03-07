/**
 * @file sort.c
 * @author Richard tang
 * @brief array sorting
 * @version 0.1
 * @date 2019-02-12
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include <sort.h>

int partition(int *number, int left, int right)
{
    int i, j, s;
    s = number[right];
    i = left - 1;
    for (j = left; j < right; j++)
    {
        if (number[j] <= s)
        {
            i++;
            SWAP(number[i], number[j]);
        }
    }
    SWAP(number[i + 1], number[right]);
    return i + 1;
}

/*
 * 快速排序递归实现
 */
void quicksort(int *number, int left, int right)
{
    int q;
    if (left < right)
    {
        q = partition(number, left, right);
        quicksort(number, left, q - 1);
        quicksort(number, q + 1, right);
    }
}