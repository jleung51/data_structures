/*
 *
 * Author: Jeffrey Leung
 * Last edited: 2015-06-17
 *
 * This C program contains implementations of an IntArray, a self-expanding
 * array of integers, created/accessed/mutated through functions.
 *
 */

#ifndef INT_ARRAY_H
#define INT_ARRAY_H

// STRUCTURES:

typedef struct IntArray IntArray;

// CONSTRUCTORS/DESTRUCTOR:

// Default constructor
// This function creates an IntArray allocated in the heap.
// User is responsible for deleting the IntArray.
IntArray* IntArrayCreate();

// Copy constructor
// This function returns a deep copy of IntArray arr, allocated in the heap.
// User is responsible for deleting the IntArray.
IntArray* IntArrayCopy( IntArray* arr );

// Destructor
// This function frees the memory allocated for IntArray arr.
void IntArrayDelete( IntArray* arr );

// ACCESSORS:

// This function returns the value of the element at the given index in
// an IntArray.
int IntArrayGet( IntArray* arr, unsigned long index );

// This function returns the current length of the IntArray.
unsigned long IntArrayLen( IntArray* arr );

// This function prints the contents of an IntArray.
void IntArrayPrint( IntArray* arr );

// MUTATORS:

//TODO Implementation required.
// This function sets an element in the IntArray to a given value.
void IntArraySet( IntArray* arr, unsigned long index, int value );

// This function adds an element to the end of the IntArray.
void IntArrayAppend( IntArray* arr, int value );

// This function removes the element at a given index in an IntArray.
void IntArrayRemove( IntArray* arr, unsigned long index );

// This function removes the element at the end of the IntArray.
void IntArrayRemoveLast( IntArray* arr );

//TODO Implementation required.
// This function removes all elements from the IntArray.
void IntArrayClear( IntArray* arr );

#endif
