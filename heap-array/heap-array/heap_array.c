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

// This function detects if a given index is out of bounds.
// HeapArray* ha:
//   Assumed to be non-NULL; if it receives a NULL pointer as an argument,
//   an error message will be displayed.
// Non-zero (true) is returned if:
//   The index is out of bounds.
// 0 (false) is returned if:
//   The index is valid.
static int OutOfBounds( HeapArray* ha, unsigned long index );

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
