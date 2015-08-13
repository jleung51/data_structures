/*
 *
 * Author: Jeffrey Leung
 * Last edited: 2015-08-12
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

// This function detects if a given index is out of bounds.
// HeapArray* ha:
//   Assumed to be non-NULL; if it receives a NULL pointer as an argument,
//   an error message will be displayed.
// Non-zero (true) is returned if:
//   The index is out of bounds.
// 0 (false) is returned if:
//   The index is valid.
static int OutOfBounds( HeapArray* ha, unsigned long index );

// This function returns the index of the parent of a given element in the heap.
static unsigned long HeapArrayParent( unsigned long index );

// This function returns the index of the left child of a given element
// in the heap.
static unsigned long HeapArrayLeft( unsigned long index );

// This function returns the index of the right child of a given element
// in the heap.
static unsigned long HeapArrayRight( unsigned long index );

// This function returns whether or not the given node is a leaf node.
// Non-zero (true) is returned if the given
static int HeapArrayNodeIsLeaf( HeapArray* ha, unsigned long index );

// This function reasserts the properties of a max heap by bubbling up from a
// given node after an insert.
// HeapArray* ha:
//   Assumed to be non-NULL; if it receives a NULL pointer as an argument,
//   an error message will be displayed.
// unsigned long index:
//   If out of bounds, an error message will be displayed.
static void BubbleUp( HeapArray* ha, unsigned long index );

// This function reasserts the properties of a max heap by bubbling down from
// the root after an insert.
// HeapArray* ha:
//   Assumed to be non-NULL; if it receives a NULL pointer as an argument,
//   an error message will be displayed.
static void BubbleDown( HeapArray* ha );

// STATIC FUNCTIONS:

//TODO
