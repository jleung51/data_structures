/*
 *
 * Author: Jeffrey Leung
 * Last edited: 2015-08-25
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

// Parameterized constructor
// This function utilizes an already-created array, and creates an IntArray
// allocated in the heap.
IntArray* IntArrayImport( int* arr, unsigned long len );

// Copy constructor
// This function returns a deep copy of IntArray arr, allocated in the heap.
// User is responsible for deleting the IntArray.
IntArray* IntArrayCopy( IntArray* arr );

// Destructor
// This function frees the memory allocated for IntArray arr.
// Should still be used even if the array is imported.
void IntArrayDelete( IntArray* arr );

// ACCESSORS:

// This function returns the value of the element at the given index in
// an IntArray.
int IntArrayGet( IntArray* arr, unsigned long index );

// This function returns the current length of the IntArray.
unsigned long IntArrayLen( IntArray* arr );

// This function prints the contents of an IntArray.
void IntArrayPrint( IntArray* arr );

// This function returns the contents of the IntArray in a new array, allocated
// in heap memory.
// Program will exit if IntArrayToArray() is given an empty array.
// User is responsible for freeing the allocated memory.
int* IntArrayToArray( IntArray* arr );

// MUTATORS:

// This function sets an element in the IntArray to a given value.
void IntArraySet( IntArray* arr, unsigned long index, int value );

// This function adds an element to the end of the IntArray.
void IntArrayAppend( IntArray* arr, int value );

// This function removes the element at a given index in an IntArray.
void IntArrayRemove( IntArray* arr, unsigned long index );

// This function removes the element at the end of the IntArray.
void IntArrayRemoveLast( IntArray* arr );

#endif
