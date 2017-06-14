/*
Problem Statement -
There are two sorted arrays. First one is of size m+n containing only m elements. 
Another one is of size n and contains n elements. Merge these two arrays into the first array of size m+n such that the output is sorted.

Solution Approach-
Let first array be mPlusN[] and other array be N[]
1) Move m elements of mPlusN[] to end.
2) Start from nth element of mPlusN[] and 0th element of N[] and merge them 
    into mPlusN[].
Time Complexity O(m+n)
*/

#include <stdio.h>
 
/* Assuming -1 is filled for the places where element
   is not available */
#define NA -1
 
/* Function to move m elements at the end of array mPlusN[] */
void moveToEnd(int mPlusN[], int size)
{
  int i = 0, j = size - 1;
  for (i = size-1; i >= 0; i--)
    if (mPlusN[i] != NA)
    {
      mPlusN[j] = mPlusN[i];
      j--;
    }
}
 
/* Merges array N[] of size n into array mPlusN[]
   of size m+n*/
int merge(int mPlusN[], int N[], int m, int n)
{
  int i = n;  /* Current index of i/p part of mPlusN[]*/
  int j = 0; /* Current index of N[]*/
  int k = 0; /* Current index of of output mPlusN[]*/
  while (k < (m+n))
  {
    /* Take an element from mPlusN[] if
       a) value of the picked element is smaller and we have
          not reached end of it
       b) We have reached end of N[] */
    if ((i < (m+n) && mPlusN[i] <= N[j]) || (j == n))
    {
      mPlusN[k] = mPlusN[i];
      k++;
      i++;
    }
    else  // Otherwise take element from N[]
    {
      mPlusN[k] = N[j];
      k++;
      j++;
    }
  }
}

