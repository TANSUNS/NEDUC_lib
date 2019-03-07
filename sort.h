/**
 * @file sort.h
 * @author Richard Tang 
 * @brief  array sorting 
 * @version 0.1
 * @date 2019-02-12
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef __SORT_H__
#define __SORT_H__

////////////////////////////////  QUICKSORT ///////////////////////////////

#define SWAP(x,y) {int t; t = x; x = y; y = t;}
/**
 * @brief 
 * 
 * @param array 
 * @param low 
 * @param high 
 * @return int 
 */
static int partition(int *number, int left, int right);

/**
 * @brief sort a array section 
 * 
 * @param array  a array that needs to sort
 * @param low    begin of data section min:1  max:n ,and the first elem is  intermediate variable!!!!
 * @param high   end of data section
 */
extern  void quicksort(int *number, int left, int right);

////////////////////////////////////////////////////////////////////////////

/*
eg:

int TEST[] = {0,45,12,56,45};
QuickSort(TEST,1,4);

*/

#endif