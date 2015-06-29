/*
 *
 * Author: Jeffrey Leung
 * Last edited: 2015-06-29
 *
 * This C program contains implementations of an IntArray, a self-expanding
 * array of integers, created/accessed/mutated through functions.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "int_array.h"

// STRUCTURES:

typedef struct IntArray
{
  int* array_;
  unsigned long len_;
  unsigned long allocated_;
} IntArray;

// STATIC FUNCTION PROTOTYPES:

// This function prints an error message and exits the program if a pointer
// is NULL (i.e. malloc has failed).
static void CheckNull( char* func_name, void* ptr );

// This function prints an error message and exits the program if an invalid
// IntArray is given.
static void CheckIntArray( char* func_name, IntArray* arr );

// This function prints an error message and exits the program if a given index
// is out of bounds.
static void CheckBounds( char* func_name, long index, unsigned long len );

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
// IntArray is given.
static void CheckIntArray( char* func_name, IntArray* arr )
{
  if( arr == NULL )
  {
    printf( "Error: %s was given an invalid IntArray.\n", func_name );
    exit( 1 );
  }
  else if( arr->array_ == NULL )
  {
    printf( "Error: %s was given an IntArray with an invalid (null) "\
            "array.\n", func_name );
    exit( 1 );
  }
  return;
}

// This function prints an error message and exits the program if a given index
// is out of bounds.
static void CheckBounds( char* func_name, long index, unsigned long len )
{
  if( index <= -1 || len <= index )
  {
    printf( "Error: %s was given an invalid index ( %ld ) as the length of "\
            "the array is %lu .\n", func_name, index, len );
    exit( 1 );
  }
  return;
}

// CONSTRUCTORS/DESTRUCTOR:

// This function creates an IntArray allocated in the heap.
// User is responsible for deleting the IntArray.
IntArray* IntArrayCreate()
{
  IntArray* arr = malloc( sizeof(IntArray) );
  CheckNull( "IntArrayCreate()", arr );

  arr->len_ = 0;
  arr->allocated_ = 16;

  arr->array_ = malloc( arr->allocated_ * sizeof(int) );
  CheckNull( "IntArrayCreate()", arr->array_ );

  return arr;
}

// Copy constructor
// This function returns a deep copy of an IntArray, allocated in the heap.
// User is responsible for deleting the IntArray.
IntArray* IntArrayCopy( IntArray* arr )
{
  CheckIntArray( "IntArrayCopy()", arr );

  IntArray* arr_new = malloc( sizeof(IntArray) );
  CheckNull( "IntArrayCopy()", arr_new );

  unsigned long length = arr->len_;
  arr_new->len_ = length;
  arr_new->allocated_ = length*2;

  arr_new->array_ = malloc( arr_new->allocated_ * sizeof(int) );
  CheckNull( "IntArrayCopy()", arr_new );

  memcpy( arr_new->array_, arr->array_, length * sizeof(int) );

  return arr_new;
}

// This function frees the memory allocated for an IntArray.
void IntArrayDelete( IntArray* arr )
{
  CheckIntArray( "IntArrayDelete()", arr );
  free( arr->array_ );
  free( arr );
  return;
}

// ACCESSORS:

// This function returns the value of the element at the given index in
// an IntArray.
int IntArrayGet( IntArray* arr, unsigned long index )
{
  CheckIntArray( "IntArrayGet()", arr );
  CheckBounds( "IntArrayGet()", index, arr->len_ );
  return arr->array_[index];
}

// This function returns the current length of the IntArray.
unsigned long IntArrayLen( IntArray* arr )
{
  CheckIntArray( "IntArrayLen()", arr );
  return arr->len_;
}

// This function prints the contents of an IntArray.
void IntArrayPrint( IntArray* arr )
{
  CheckIntArray( "IntArrayPrint()", arr );

  printf( "[ " );
  for( long i = 0; i < arr->len_; i++)
  {
    printf( "%d ", arr->array_[i] );
  }
  printf( "]" );
  return;
}

// This function returns the contents of the IntArray in a new array, allocated
// in heap memory.
// Program will exit if IntArrayToArray() is given an empty array.
// User is responsible for freeing the allocated memory.
int* IntArrayToArray( IntArray* arr )
{
  CheckIntArray( "IntArrayToArray()", arr );

  unsigned long length = arr->len_;

  int* arr_copy = malloc( length * sizeof(int) );
  int i;
  for( i = 0; i < length; ++i )
  {
    arr_copy[i] = arr->array_[i];
  }

  return arr_copy;
}

// MUTATORS:

// This function sets an element in the IntArray to a given value.
void IntArraySet( IntArray* arr, unsigned long index, int value )
{
  CheckIntArray( "IntArraySet()", arr );
  CheckBounds( "IntArraySet()", index, arr->len_ );

  arr->array_[index] = value;
  return;
}

// This function adds an element to the end of an IntArray, expanding its
// size if necessary.
void IntArrayAppend( IntArray* arr, int value )
{
  CheckIntArray( "IntArrayAppend()", arr );

  // Expands array to double the size
  if( arr->len_ >= arr->allocated_ )
  {
    arr->allocated_ *= 2;

    int* new_array = malloc( arr->allocated_ * sizeof(int) );
    CheckNull( "IntArrayAppend()", new_array );
    memcpy( new_array, arr->array_, arr->len_ * sizeof(int) );

    free( arr->array_ );
    arr->array_ = new_array;
  }

  arr->array_[arr->len_] = value;
  arr->len_++;

  return;
}

// This function removes the element at a given index in an IntArray.
void IntArrayRemove( IntArray* arr, unsigned long index )
{
  CheckIntArray( "IntArrayRemove()", arr );
  CheckBounds( "IntArrayRemove()", index, arr->len_ );

  arr->array_[index] = arr->array_[arr->len_-1];
  arr->len_--;
  return;
}

// This function removes the element at the end of the IntArray.
void IntArrayRemoveLast( IntArray* arr )
{
  CheckIntArray( "IntArrayRemoveLast()", arr );

  if( arr->len_ == 0 )
  {
    printf( "Error: IntArrayRemoveLast() cannot remove anything from an "\
            "empty array.\n" );
    exit( 1 );
  }

  arr->len_--;
  return;
}
