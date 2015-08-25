/*
 *
 * Author: Jeffrey Leung
 * Last edited: 2015-08-25
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
  int* arr_;
  unsigned long size_;
  int is_allocated_;
} HeapArray;

// STATIC FUNCTION PROTOTYPES:

// This function detects if a given index is out of bounds.
// HeapArray* ha (and its array):
//   Assumed to be non-NULL; if it receives a NULL pointer as an argument,
//   an error message will be displayed.
// Non-zero (true) is returned if:
//   The index is out of bounds.
// 0 (false) is returned if:
//   The index is valid.
static int HeapArrayOutOfBounds( HeapArray* ha, unsigned long index );

// This function swaps the values of two given integer pointers.
// int* val1 and val2:
//   Assumed to be non-NULL; if they receive a NULL pointer as an argument,
//   an error message will be displayed.
static void HeapArraySwap( int* val1, int* val2 );

// This function returns the index of the parent of a given node in the heap.
static unsigned long HeapArrayParent( unsigned long index );

// This function returns the index of the left child of a given node
// in the heap.
static unsigned long HeapArrayLeft( unsigned long index );

// This function returns the index of the right child of a given node
// in the heap.
static unsigned long HeapArrayRight( unsigned long index );

// This function returns the number of children of a given node.
// HeapArray* ha (and its array):
//   Assumed to be non-NULL; if it receives a NULL pointer as an argument,
//   an error message will be displayed.
// unsigned long index:
//   Assumed to be valid; if it receives an invalid index, an error message
//   will be displayed.
static unsigned int HeapArrayNumOfChildren( HeapArray* ha,
                                            unsigned long index );

// This function reasserts the properties of a max heap by bubbling up from a
// given node after an insert.
// HeapArray* ha (and its array):
//   Assumed to be non-NULL; if it receives a NULL pointer as an argument,
//   an error message will be displayed.
// unsigned long index:
//   If out of bounds, an error message will be displayed.
static void HeapArrayBubbleUp( HeapArray* ha, unsigned long index );

// This function reasserts the properties of a max heap by bubbling down from
// the root after an insert.
// HeapArray* ha (and its array):
//   Assumed to be non-NULL; if it receives a NULL pointer as an argument,
//   an error message will be displayed.
static void HeapArrayBubbleDown( HeapArray* ha );

// STATIC FUNCTIONS:

// This function detects if a given index is out of bounds.
// HeapArray* ha (and its array):
//   Assumed to be non-NULL; if it receives a NULL pointer as an argument,
//   an error message will be displayed.
// Non-zero (true) is returned if:
//   The index is out of bounds.
// 0 (false) is returned if:
//   The index is valid.
static int HeapArrayOutOfBounds( HeapArray* ha, unsigned long index )
{
  if( ha == NULL )
  {
    printf( "Error: HeapArrayOutOfBounds() was given an invalid pointer.\n" );
    exit( 1 );
  }
  else if( ha->arr_ == NULL )
  {
    printf( "Error: HeapArrayOutOfBounds() was given a HeapArray with an "\
            "invalid array pointer.\n" );
    exit( 1 );
  }
  
  if( index >= ha->size_ )
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

// This function swaps the values of two given integer pointers.
// int* val1 and val2:
//   Assumed to be non-NULL; if they receive a NULL pointer as an argument,
//   an error message will be displayed.
static void HeapArraySwap( int* val1, int* val2 )
{
  if( val1 == NULL )
  {
    printf( "Error: HeapArraySwap() was given an invalid pointer for the "\
            "first value.\n" );
    exit( 1 );
  }
  else if( val2 == NULL )
  {
    printf( "Error: HeapArraySwap() was given an invalid pointer for the "\
            "second value.\n" );
    exit( 1 );
  }

  int temp = *val1;
  *val1 = *val2;
  *val2 = temp;
  return;
}

// This function returns the index of the parent of a given node in the heap.
static unsigned long HeapArrayParent( unsigned long index )
{
  return (index-1) / 2;  // Floor division
}

// This function returns the index of the left child of a given node
// in the heap.
static unsigned long HeapArrayLeft( unsigned long index )
{
  return index * 2 + 1;
}

// This function returns the index of the right child of a given node
// in the heap.
static unsigned long HeapArrayRight( unsigned long index )
{
  return index * 2 + 2;
}

// This function returns the number of children of a given node.
// HeapArray* ha (and its array):
//   Assumed to be non-NULL; if it receives a NULL pointer as an argument,
//   an error message will be displayed.
// unsigned long index:
//   Assumed to be valid; if it receives an invalid index, an error message
//   will be displayed.
static unsigned int HeapArrayNumOfChildren( HeapArray* ha,
                                            unsigned long index )
{
  if( ha == NULL )
  {
    printf( "Error: HeapArrayNumOfChildren() was given an invalid pointer.\n" );
    exit( 1 );
  }
  else if( ha->arr_ == NULL )
  {
    printf( "Error: HeapArrayNumOfChildren() was given a HeapArray with an "\
            "invalid array pointer.\n" );
    exit( 1 );
  }
  else if( index >= ha->size_ )
  {
    printf( "Error: HeapArrayNumOfChildren() was given an invalid index "\
            "(%lu).\n", index );
    exit( 1 );
  }

  unsigned long left_index = HeapArrayLeft(index);
  unsigned long size = ha->size_;

  if( left_index < size )
  {
    if( left_index+1 < size )  // Index of right child
    {
      return 2;
    }
    else
    {
      return 1;
    }
  }
  else
  {
    return 0;
  }
}

// This function reasserts the properties of a max heap by bubbling up from a
// given node after an insert.
// HeapArray* ha (and its array):
//   Assumed to be non-NULL; if it receives a NULL pointer as an argument,
//   an error message will be displayed.
// unsigned long index:
//   If out of bounds, an error message will be displayed.
static void HeapArrayBubbleUp( HeapArray* ha, unsigned long index )
{
  if( ha == NULL )
  {
    printf( "Error: HeapArrayBubbleUp() was given an invalid pointer.\n" );
    exit( 1 );
  }
  else if( ha->arr_ == NULL )
  {
    printf( "Error: HeapArrayBubbleUp() was given a HeapArray with an "\
            "invalid array pointer.\n" );
    exit( 1 );
  }
  else if( index >= ha->size_ )
  {
    printf( "Error: HeapArrayBubbleUp() was given an invalid index "\
            "(%lu).\n", index );
    exit( 1 );
  }

  unsigned long parent_index = HeapArrayParent( index );
  while( index > 0 &&
         ha->arr_[parent_index] > ha->arr_[index] )  // Swaps index and parent
                                                     // if parent is larger
  {
    HeapArraySwap( &(ha->arr_[parent_index]), &(ha->arr_[index]) );
    index = parent_index;
    parent_index = HeapArrayParent( index );
  }
  return;
}

// This function reasserts the properties of a max heap by bubbling down from
// the root after an insert.
// HeapArray* ha (and its array):
//   Assumed to be non-NULL; if it receives a NULL pointer as an argument,
//   an error message will be displayed.
static void HeapArrayBubbleDown( HeapArray* ha )
{
  if( ha == NULL )
  {
    printf( "Error: HeapArrayBubbleDown() was given an invalid pointer.\n" );
    exit( 1 );
  }
  else if( ha->arr_ == NULL )
  {
    printf( "Error: HeapArrayBubbleDown() was given a HeapArray with an "\
            "invalid array pointer.\n" );
    exit( 1 );
  }
  
  unsigned long index = 0;
  unsigned long index_left;
  unsigned long index_right;
  unsigned int num_of_children = HeapArrayNumOfChildren( ha, index );
  int swapped = 1;
  
  while( swapped && num_of_children > 0 )
  {
    swapped = 0;
    index_left = HeapArrayLeft( index );
    
    if( num_of_children == 1 )  // Left child exists; right child does not
    {
      if( ha->arr_[index_left] >  ha->arr_[index] )
      {
        HeapArraySwap( &(ha->arr_[index_left]), &(ha->arr_[index]) );
        index = index_left;
        swapped = 1;
      }
    }
    
    else  // Both left and right children exist
    {
      index_right = HeapArrayRight( index );
      if( ha->arr_[index_left] >  ha->arr_[index] &&
          ha->arr_[index_left] >= ha->arr_[index_right] )
      {
        HeapArraySwap( &(ha->arr_[index_left]), &(ha->arr_[index]) );
        index = index_left;
        swapped = 1;
      }
      else if( ha->arr_[index_right] >  ha->arr_[index] &&
               ha->arr_[index_right] >= ha->arr_[index_left] )
      {
        HeapArraySwap( &(ha->arr_[index_right]), &(ha->arr_[index]) );
        index = index_right;
        swapped = 1;
      }
    }
    
    num_of_children = HeapArrayNumOfChildren( ha, index );
  }
  return;
}
