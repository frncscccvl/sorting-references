/*
 @  Sorting.c
 @
 @  Created by francis esposito caccavale on 8/13/13.
 @  Copyright (c) 2013 francis esposito caccavale. All rights reserved.
 */

#define ARRAYLENGTH 20

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void swapChar(char *array, int j, int i)
{
    char temp = array[j];
    array[j] = array[i];
    array[i] = temp;
}

void swap(int array[], int j, int i)
{
    int temp = array[j];
    array[j] = array[i];
    array[i] = temp;
}

void reverseString(char *string)
{
    int length = (strlen(string)-1), i = 0, mid = length/2;
    
    for (i = 0; i <= mid; i++)
        swapChar(string, i, length - i);
}

void bubbleSort(int *array, int n)
{
    /* O(n^2) runtime (average case). */
    int i, swapped = 1;
    
    while (swapped)
    {
        swapped = 0;
        
        for (i = 0; i < n-1; i++)
            if (array[i] > array[i + 1])
            {
                swap(array, i, i + 1);
                swapped = 1;
            }
    }
}

void mergeSort(int array[], int lo, int hi)
{
    /* O(n log n) runtime (average case). */
    
    /* base case. */
    if (lo >= hi)
        return;
    
    /* avoid possibility of integer overflow */
    int mid = lo + (hi - lo) / 2;
    
    /* recursive calls: mergesort left and right halves of array */
    mergeSort(array, lo, mid);
    mergeSort(array, mid + 1, hi);
    
    /* merge the two halves back together */
    int i = lo, j = mid + 1, k = 0;
    int aux[hi - lo + 1];
    
    while (i <= mid || j <= hi)
    {
        if ((i > mid) || (j <= hi && array[j] < array[i]))
            aux[k++] = array[j++];
        else
            aux[k++] = array[i++];
    }
    
    /* copy merged portion back into original array */
    for (i = lo; i <= hi; i++)
        array[i] = aux[i - lo];
}

void quickSort(int *array, int n)
{
    /* O(n log n) runtime (average case). */
    if (n < 2)
        return;
    
    int pivot = array[n/2];
    int *left = array;
    int *right = array + n - 1;
    
    while (left <= right) {
        if (*left < pivot) {
            left++;
            continue;
        }
        if (*right > pivot) {
            right--;
            continue; // we need to check the condition (l <= r) every time we change the value of l or r
        }
        int t = *left;
        *left++ = *right;
        *right-- = t;
    }
    
    quickSort(array, right - array + 1);
    quickSort(left, array + n - left);
}

void insertionSort(int array[], int n)
{
    /* O(n^2) runtime (average case). */
    int i, j, val, gap;
    
    for (i = 1; i < n; i++)
    {
        val = array[i];
        gap = i;
        for (j = gap-1; j >= 0 && array[j] > val; j--)
        {
            array[j+1] = array[j];
            gap--;
        }
        array[gap] = val;
    }
}

void selectionSort(int array[], int n)
{
    /* O(n^2) runtime (average case). */
    int i, j, minIndex;
    
    for (i = 0; i < n-1; i++)
    {
        minIndex = i;
        for (j = i+1; j < n; j++)
            if (array[j] < array[minIndex])
                minIndex = j;
        
        swap(array, i, minIndex);
    }
}

void radixSort(int array[], int n)
{
    /* O(k*N) runtime (worst case). */
}

int binarySearch(int array[], int lo, int hi, int target)
{
    /* in binary search, the array must be sorted first. */
    
    if (hi >= lo) {
        int mid = lo + (hi - lo)/2;
        
        if (array[mid] == target)
            return mid;
        
        if (array[mid] > target)
            return binarySearch(array, lo, mid-1, target);
        
        if (array[mid] < target)
            return binarySearch(array, mid+1, hi, target);
    }
    
    return -1;
}

int main(void)
{
    int arrayInt[ARRAYLENGTH], i = 0, n = 0;
    char foo[60] = "String reversal.";
    srand(NULL);
    
    for (i = 0; i < ARRAYLENGTH; i++) {
        n = rand() % 100;
        printf("Inserting %d into the array...\n", n);
        arrayInt[i] = n;
    }
    
    bubbleSort(arrayInt, ARRAYLENGTH);
    //mergeSort(arrayInt, 0, ARRAYLENGTH-1);
    //quickSort(arrayInt, ARRAYLENGTH);
    //insertionSort(arrayInt, ARRAYLENGTH);
    //selectionSort(arrayInt, ARRAYLENGTH);
    
    for (i = 0; i < ARRAYLENGTH; i++)
        printf("Sorted array... %d\n", arrayInt[i]);
    
    int binaryfind = binarySearch(arrayInt, 0, ARRAYLENGTH-1, 41);
    
    (binaryfind == -1) ? printf("Element is not in array...\n") : printf("Element is within index %d of array...\n", binaryfind);
    
    //printf("%d\n", binaryfind);
    
    //reverseString(foo);
    //printf("%s\n", foo);
    
    return 0;
}
