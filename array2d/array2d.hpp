/*
 *
 * Author: Jeffrey Leung
 * Last edited: 2015-07-19
 *
 * This C++ program contains a templated implementation of a 2-dimensional
 * array.
 *
 */

#pragma once

#include <iostream>
#include <stdexcept>
#include <string>

template <class T>
class Array2d
{
  public:
    // Constructors/Destructor:
    Array2d();  // Creates a 10x10 array.
    Array2d( unsigned int width, unsigned int height );
    Array2d( const Array2d& arr );
    ~Array2d();

    // Mutators:

    // This method sets the element at the given coordinate to a value.
    // An exception is thrown if the coordinates are out of range
    // (out_of_range).
    void Set( unsigned int x, unsigned int y, T value );

    // This method resizes the array to a rectangle with:
    //   the top-left coordinate (start_x, start_y - 1) and
    //   the bottom right coordinate (end_x, end_y - 1), inclusive.
    // An exception is thrown if a coordinate is out of bounds or if the
    // coordinates will not create a valid rectangle (out_of_range).
    void Shrink( unsigned int start_x,
                 unsigned int start_y,
                 unsigned int end_x,
                 unsigned int end_y );

    // This method resizes the array to a larger rectangle with the dimensions
    // of the current width plus x_greater, and the current height
    // plus y_greater.
    // The new elements are uninitialized.
    void Expand( unsigned int x_greater, unsigned int y_greater );

    // Accessors:

    // This method returns the value at a given set of coordinates.
    // An exception is thrown if the coordinates given are out of range
    // (out_of_range).
    T Get( unsigned int x, unsigned int y );

    // This method returns the width of the array.
    unsigned int Width();

    // This method returns the height of the array.
    unsigned int Height();

    // This method returns the total size of the array.
    unsigned int Size();

  private:
    T* array_;
    unsigned int width_;
    unsigned int height_;

    bool OutOfBounds( unsigned int x, unsigned int y );
    unsigned int Index( unsigned int x, unsigned int y );
};



// Private methods:

// This private method returns true if a given set of coordinates is
// out of bounds.
template <typename T>
bool Array2d<T>::OutOfBounds( unsigned int x, unsigned int y )
{
  if( x >= width_ || y >= height_ )
  {
    return true;
  }
  return false;
}

// This private method returns the index in the array of a given set
// of coordinates.
template <typename T>
unsigned int Array2d<T>::Index( unsigned int x, unsigned int y )
{
  return y * width_ + x;
}



// Constructors/destructor:

// Default constructor
// Creates a 10x10 array.
template <typename T>
Array2d<T>::Array2d()
{
  width_  = 10;
  height_ = 10;

  unsigned int size = width_ * height_;
  array_  = new T[size];
}

// Parametrized constructor
template <typename T>
Array2d<T>::Array2d( unsigned int width, unsigned int height )
{
  width_  = width;
  height_ = height;

  unsigned int size = width_ * height_;
  array_  = new T[size];
}

// Copy constructor
template <typename T>
Array2d<T>::Array2d( const Array2d& arr )
{
  width_  = arr.width_;
  height_ = arr.height_;

  unsigned int size = width_ * height_;
  array_  = new T[size];
  for(int i = 0; i < size; i++)
  {
    array_[i] = arr.array_[i];
  }
}

// Deconstructor
template <typename T>
Array2d<T>::~Array2d()
{
  delete [] array_;
}



// Mutators:

// This method sets the element at the given coordinate to a value.
// An exception is thrown if the coordinates are out of range (out_of_range).
template <typename T>
void Array2d<T>::Set( unsigned int x, unsigned int y, T value )
{
  if( OutOfBounds(x, y) )
  {
    throw std::out_of_range("Error: Set() was given an invalid index.");
  }

  array_[ Index(x, y) ] = value;
  return;
}

// This method resizes the array to a rectangle with:
//   the top-left coordinate (start_x, start_y - 1) and
//   the bottom right coordinate (end_x, end_y - 1), inclusive.
// An exception is thrown if a coordinate is out of bounds or if the
// coordinates will not create a valid rectangle (out_of_range).
template <typename T>
void Array2d<T>::Shrink( unsigned int start_x, unsigned int start_y,
                         unsigned int end_x, unsigned int end_y )
{
  if( OutOfBounds(start_x, start_y) )
  {
    throw std::out_of_range("Error: Shrink() was given an invalid "\
                            "start coordinate,");
  }
  else if( OutOfBounds(end_x-1, end_y-1) )
  {
    throw std::out_of_range("Error: Shrink() was given an invalid end "\
                            "coordinate.");
  }
  else if( start_x > end_x || start_y > end_y )
  {
    throw std::invalid_argument("Error: Shrink() was given start and end "\
                                "coordinates which do not make a proper "\
                                "rectangle.");
  }

  unsigned int width_new  = end_x - start_x;
  unsigned int height_new = end_y - start_y;
  T* array_new = new T[ width_new * height_new ];

  for( int y = 0; y < height_new; ++y )
  {
    for( int x = 0; x < width_new; ++x )
    {
      std::cout << "Copying value " << array_[(y + start_y) * width_ + (x + start_x)] << " from (" << x + start_x << ", " << y + start_y << ") to (" << x << ", " << y << ")." << std::endl;
      array_new[ y * width_new + x ]
        = array_[ (y+start_y) * width_ + (x+start_x) ];
    }
  }

  delete [] array_;
  array_  = array_new;
  width_  = width_new;
  height_ = height_new;

  return;
}

// This method resizes the array to a larger rectangle with the dimensions
// of the current width plus x_greater, and the current height plus y_greater.
// The new elements are uninitialized.
template <typename T>
void Array2d<T>::Expand( unsigned int x_greater, unsigned int y_greater )
{
  unsigned int width_new = width_ + x_greater;
  unsigned int height_new = height_ + y_greater;

  T* array_new = new T[ width_new * height_new ];
  for( int y = 0; y < height_; ++y )
  {
    for( int x = 0; x < width_; ++x )
    {
      array_new[ y * width_new + x ] = array_[ y * width_ + x ];
    }
  }

  delete [] array_;
  array_ = array_new;
  width_  = width_new;
  height_ = height_new;

  return;
}



// Accessors:

// This method returns the value at a given set of coordinates.
// An exception is thrown if the coordinates given are out of range
// (out_of_range).
template <typename T>
T Array2d<T>::Get( unsigned int x, unsigned int y )
{
  if( OutOfBounds(x, y) )
  {
    throw std::out_of_range("Error: Get() was given an invalid index.");
  }

  return array_[ Index(x, y) ];
}

// This method returns the width of the array.
template <typename T>
unsigned int Array2d<T>::Width()
{
  return width_;
}

// This method returns the height of the array.
template <typename T>
unsigned int Array2d<T>::Height()
{
  return height_;
}

// This method returns the total size of the array.
template <typename T>
unsigned int Array2d<T>::Size()
{
  return width_ * height_;
}
