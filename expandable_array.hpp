/*
 *
 * Author: Jeffrey Leung
 * Last edited: 2015-05-05
 *
 * This program contains implementations of a templated, self-expanding array.
 *
 */

#pragma once

#include <cstring>
#include <iostream>
#include <string>

template <typename T>
class ExpandableArray
{
  public:
    ExpandableArray();
    ~ExpandableArray();

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

  private:
    T* array_;
    unsigned long len_;
    unsigned long allocated_;
};

// This function prints an error message and exits the program if a given index is out of bounds.
static void CheckBounds( unsigned long index, unsigned long len, std::string func_name );

template <class T>
ExpandableArray<T>::ExpandableArray()
{
  len_ = 0;
  allocated_ = 16;
  array_ = new T[allocated_];
}

template <class T>
ExpandableArray<T>::~ExpandableArray()
{
  delete [] array_;
}

// This function prints an error message and exits the program if a given index is out of bounds.
static void CheckBounds( unsigned long index, unsigned long len, std::string func_name )
{
  if( index >= len )
  {
    std::cout << "Error: " << func_name << "() was given an invalid index (" << index << \
                 ") as the length of the array is " << len << ".\n" ;
    exit( 1 );
  }

  return;
}

// This method adds an element to the end of an array, expanding if necessary.
template <class T>
void ExpandableArray<T>::Append( T value )
{
  // Expands array to double the size
  if( len_ >= allocated_ )
  {
    T* new_array = new T[allocated_ * 2];
    if( new_array == NULL )
    {
      std::cout << "Error: Append() attempted to allocate additional memory but was unable to.\n" ;
      exit( 3 );
    }
    std::memcpy( new_array, array_, len_ * sizeof(T) );
    allocated_ *= 2;

    delete [] array_;
    array_ = new_array;
  }

  array_[len_] = value;
  len_++;

  return;
}

// This method removes the element at the end of the array.
template <class T>
void ExpandableArray<T>::Remove()
{
  if( len_ == 0 )
  {
    std::cout << "Error: Remove() cannot remove anything from an empty array.\n" ;
    exit( 1 );
  }

  len_--;
  return;
}

// This method removes the element at a given index.
template <class T>
void ExpandableArray<T>::Remove( unsigned long index )
{
  CheckBounds( index, len_, "Remove" );

  array_[index] = array_[len_-1];
  len_--;
  return;
}

// This method returns the value of the element at the given index.
template <class T>
T ExpandableArray<T>::Retrieve( unsigned long index )
{
  CheckBounds( index, len_, "Retrieve" );
  return array_[index];
}

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

/* Methods to implement:
    void Find( T value );
    void Sort();
    ExpandableArray* Copy();
      ExpandableArray* Copy( unsigned int start, unsigned int end );
        // Copies all elements from start to end-1 inclusive.
*/

#endif
