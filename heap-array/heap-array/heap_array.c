/*
 *
 * Author: Jeffrey Leung
 * Last edited: 2015-08-09
 *
 * This C program contains implementations of a heap, implemented using an
 * array of integers.
 * Currently, only a max heap is supported.
 *
 */

#include <stdio.h>
#include <stdlib.h>

#include "heap_array.h"

// STRUCTURES:

typedef struct HeapArray
{
  int* array_;
  unsigned long len_;
  int allocated_;
} HeapArray;

// STATIC FUNCTION PROTOTYPES:

// This function prints an error message and exits the program if a pointer
// is NULL (i.e. malloc has failed).
static void CheckNull( char* func_name, void* ptr );

// This function prints an error message and exits the program if an invalid
// HeapArray is given.
static void CheckHeapArray( char* func_name, HeapArray* arr );

// This function prints an error message and exits the program if a given index
// is out of bounds.
static void CheckBounds( char* func_name, HeapArray* arr, long index );

// STATIC FUNCTIONS:

// This function prints an error message and exits the program if a pointer
// is NULL (i.e. malloc has failed).
static void CheckNull( char* func_name, void* ptr )
{
  if( ptr == NULL )
  {
    printf( "Error: %s failed to allocate memory on the heap.\n", \
            func_name );
    exit( 2 );
  }
  return;
}

// This function prints an error message and exits the program if an invalid
// HeapArray is given.
static void CheckHeapArray( char* func_name, HeapArray* arr )
{
  if( arr == NULL )
  {
    printf( "Error: %s was given an invalid HeapArray.\n", func_name );
    exit( 1 );
  }
  else if( arr->array_ == NULL )
  {
    printf( "Error: %s was given a HeapArray with an invalid (null) "\
            "array.\n", func_name );
    exit( 1 );
  }
  return;
}

// This function prints an error message and exits the program if a given index
// is out of bounds.
static void CheckBounds( char* func_name, HeapArray* arr, long index )
{
  if( index <= -1 || arr->len_ <= index )
  {
    printf( "Error: %s was given an invalid index ( %ld ) as the length of "\
            "the array is %lu .\n", func_name, index, arr->len_ );
    exit( 1 );
  }
  return;
}

// CONSTRUCTORS/DESTRUCTOR:
