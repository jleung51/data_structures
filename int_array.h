/*
 *
 * Author: Jeffrey Leung
 * Last edited: 2015-05-24
 *
 * This C program contains implementations of a self-expanding array
 * of integers, created/accessed/mutated through functions.
 *
 */

#ifndef INT_ARRAY_H
#define INT_ARRAY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>



// PROTOTYPES:

typedef struct IntArray IntArray;

// CONSTRUCTOR/DESTRUCTOR:

// This function creates an IntArray allocated in the heap.
// User is responsible for deleting the IntArray.
IntArray* IntArrayCreate();

// This function frees the memory allocated for IntArray arr.
void IntArrayDelete( IntArray* arr );

// ACCESSORS:

// This function returns the value of the element at the given index in
// an IntArray.
int IntArrayGet( IntArray* arr, unsigned long index );

// This function prints the contents of an IntArray.
void IntArrayPrint( IntArray* arr );

// MUTATORS:

// This function adds an element to the end of the IntArray.
void IntArrayAppend( IntArray* arr, int value );

// This function removes the element at a given index in an IntArray.
void IntArrayRemove( IntArray* arr, unsigned long index );

// This function removes the element at the end of the IntArray.
void IntArrayRemoveLast( IntArray* arr );



// STRUCTURES:

typedef struct IntArray
{
  int* array_;
  unsigned long len_;
  unsigned long allocated_;
} IntArray;

// STATIC FUNCTIONS:

// This function prints an error message and exits the program if a pointer
// is NULL (i.e. malloc has failed).
static void CheckNull( char* func_name, void* ptr );

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
static void CheckIntArray( char* func_name, IntArray* arr );

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
static void CheckBounds( char* func_name,
                         long index,
                         unsigned long len );

// This function prints an error message and exits the program if a given index
// is out of bounds.
static void CheckBounds( char* func_name,
                         long index,
                         unsigned long len )
{
  if( index <= -1 || len <= index )
  {
    printf( "Error: %s was given an invalid index ( %ld ) as the length of "\
            "the array is %lu .\n", func_name, index, len );
    exit( 1 );
  }
  return;
}

// CONSTRUCTOR/DESTRUCTOR:

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

// This function frees the memory allocated for IntArray arr.
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



// MUTATORS:

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
  CheckIntArray( "IntArrayRemove()", arr );

  if( arr->len_ == 0 )
  {
    printf( "Error: IntArrayRemove() cannot remove anything from an "\
            "empty array.\n" );
    exit( 1 );
  }

  arr->len_--;
  return;
}

/*
// This method reassigns the value of an element at a given index.
template <class T>
void ExpandableArray<T>::Set( unsigned long index, T value )
{
  CheckBounds( index, len_, "Set" );
  array_[index] = value;
  return;
}

// This method returns the length of the array.
template <class T>
unsigned long ExpandableArray<T>::Length()
{
  return len_;
}

// This method prints the contents of the array,
template <class T>
void ExpandableArray<T>::Print()
{
  std::cout << "[ " ;
  for( int i = 0; i < len_; i++ )
  {
    std::cout << array_[i] << " " ;
  }
  std::cout << "]" ;

  return;
}


  void Append( T value );
  void Remove();  // Removes end element.
  void Remove( unsigned long index );

    T Retrieve( unsigned long index );
    void Set( unsigned long index, T value );
    unsigned long Length();

    void Print();  // The following methods have not been implemented:
    void Find( T value );
    void Sort();
    ExpandableArray* Copy();
      ExpandableArray* Copy( unsigned long start, unsigned long end );
        // Copies all elements from start to end-1 inclusive.

// Copy constructor


 Methods to implement:
    void Find( T value );
    void Sort();
    ExpandableArray* Copy();
      ExpandableArray* Copy( unsigned int start, unsigned int end );
        // Copies all elements from start to end-1 inclusive.
*/

#endif
