/*
 *
 * Name: Jeffrey Leung
 * Date: 2015-04-07
 *
 * This program contains the implementation of a recursive mergesort algorithm.
 *
 */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "merge_sort.h"

// Only for use by merge_sort().
// This function merges two sorted arrays to create a single array (in the memory spaces of the
// original arrays) with elements from least to greatest.
// array1 and array2 must be in consecutive memory spaces - i.e. two sections of the same array.
static void merge_arrays( int* array1, int len1, int* array2, int len2 );



// Only for use by merge_sort().
// This function merges two sorted arrays to create a single array (in the memory spaces of the
// original arrays) with elements from least to greatest.
// array1 and array2 must be in consecutive memory spaces - i.e. two sections of the same array.
static void merge_arrays( int* array1, int len1, int* array2, int len2 )
{
  int* array_final = array1;

  int len_final = len1 + len2;
  int array_copy[len_final];

  int* array1temp = array1;
  int* array2temp = array2;
  unsigned int i = 0;

  while( len1 > 0 && len2 > 0 )
  {
    if( array1temp[0] < array2temp[0] )  // Insert element from array1 into array_copy
    {
      array_copy[i] = array1temp[0];
      array1temp += 1;
      len1--;
    }
    else  // Insert element from array2 into array_copy
    {
      array_copy[i] = array2temp[0];
      array2temp += 1;
      len2--;
    }

    i++;
  }

  if( len1 > 0 )
  {
    memcpy( array_copy + i, array1temp, len1 * sizeof(int) );
  }
  else if( len2 > 0 )
  {
    memcpy( array_copy + i, array2temp, len2 * sizeof(int) );
  }

  memcpy( array_final, array_copy, len_final * sizeof(int) );

  return;
}

// This function recursively sorts an array from least to greatest using the mergesort algorithm.
void merge_sort( int* array, int len )
{
  if( array == NULL )
  {
    printf( "Error: merge_sort was given a null pointer.\n" );
    exit( 1 );
  }

  if( len <= 1 )
  {
    return;
  }

  int mid = len / 2;

  merge_sort( array,     mid );
  merge_sort( array+mid, len-mid );

  merge_arrays( array, mid, array+mid, len-mid );

  return;
}
