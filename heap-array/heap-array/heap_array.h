/*
 *
 * Author: Jeffrey Leung
 * Last edited: 2015-08-09
 *
 * This C program contains implementations of a heap, implemented using an
 * array of integers.
 *
 */

#ifndef HEAP_ARRAY_H
#define HEAP_ARRAY_H

// STRUCTURES:
typedef struct HeapArray HeapArray;

// CONSTRUCTORS/DESTRUCTOR:

// Default constructor
// This function returns a pointer to an empty heap.
// NULL is returned if:
//   Memory allocation fails.
HeapArray* HeapArrayCreate();

// Parameterized constructor
// This function returns a pointer to a heap which directly uses the pointer of
// a given, pre-existing array.
// The original array may be modified by the heap, and cannot be deallocated
// until the heap operations are complete.
// NULL is returned if:
//   Memory allocation fails.
//   The given pointer is invalid.
HeapArray* HeapArrayCreateFromArray( int* arr );

// Copy constructor
// This function returns a pointer to a heap which contains the same contents
// as the given parameter HeapArray.
HeapArray* HeapArrayCopy( const HeapArray* ha );

// Destructor
// This function deallocates the memory allocated for a heap array, and for
// the array as well, if necessary.
// Non-zero (true) is returned if:
//   The deletion is successful.
// 0 (false) is returned if:
//   The given pointer is invalid.
int HeapArrayDelete( HeapArray* ha );

// ACCESSORS:

// MUTATORS:

#endif
