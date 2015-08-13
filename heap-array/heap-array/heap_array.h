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
// NULL is returned if:
//   Memory allocation fails.
//   The given pointer is invalid.
HeapArray* HeapArrayCopy( const HeapArray* ha );

// Destructor
// This function deallocates the memory allocated for a heap array, and for
// the array as well, if necessary.
// Non-zero (true) is returned if:
//   The operation is successful.
// 0 (false) is returned if:
//   The given pointer is invalid.
int HeapArrayDelete( HeapArray* ha );

// BASIC FUNCTIONS:

// This function inserts a given value in the heap, and reasserts the
// properties of the max/min heap by bubbling up.
// Non-zero (true) is returned if:
//   The operation is successful.
// 0 (false) is returned if:
//   The given pointer is invalid.
int HeapArrayInsert( HeapArray* ha, int value );

// This function removes the largest (max heap) or smallest (min heap) value
// in the heap, assigns it to the given pointer, and reasserts the properties of
// the max/min heap by bubbling down.
// Non-zero (true) is returned if:
//   The operation is successful.
// 0 (false) is returned and the value at the pointer is unchanged if:
//   The given pointer is invalid.
//   The heap is empty.
int HeapArrayRemove( HeapArray* ha, int* return_value );

// PROPERTIES:

// This function assigns the current size of the heap to the given pointer.
// Non-zero (true) is returned if:
//   The operation is successful.
// 0 (false) is returned and the value at the pointer is unchanged if:
//   The given pointer is invalid.
int HeapArraySize( HeapArray* ha, int* return_size );

#endif
