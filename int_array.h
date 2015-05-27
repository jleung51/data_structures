/*
 *
 * Author: Jeffrey Leung
 * Last edited: 2015-05-27
 *
 * This C program contains implementations of a self-expanding array
 * of integers, created/accessed/mutated through functions.
 *
 */

#ifndef INT_ARRAY_H
#define INT_ARRAY_H

// STRUCTURES:

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

#endif
