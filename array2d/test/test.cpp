/*
 *
 * Author: Jeffrey Leung
 * Last edited: 2015-06-17
 *
 * This C++ program tests the implementation of the Array2d class in
 * array2d.hpp.
 *
 */

#include <iostream>

#include "../array2d.hpp"
#include "test.hpp"

// This function prints the contents of a given array.
template <typename T>
void PrintArray( Array2d<T> arr, unsigned int width, unsigned int height )
{
  for( unsigned int y = 0; y < height; ++y )
  {
    for( unsigned int x = 0; x < width; ++x )
    {
      try
      {
        std::cout << arr.Get( x, y ) << " ";
      }
      catch( std::out_of_range except )
      {
        std::cout << except.what();
      }
    }
    std::cout << std::endl;
  }

  return;
}

int main()
{
  Array2d<int> arr;
  Array2d<int> arr_param(10, 10);
  for( int y = 0; y < 10; ++y )
  {
    for( int x = 0; x < 10; ++x )
    {
      try
      {
        arr.Set( x, y, x + y );
        arr_param.Set( x, y, x + y );
      }
      catch( std::out_of_range except )
      {
        std::cout << except.what();
      }
    }
  }

  Array2d<int> arr_copy( arr );

  std::cout << "New 2-d array:" << std::endl;
  PrintArray( arr, arr.Width(), arr.Height() );
  std::cout << std::endl;

  std::cout << "Width:  " << arr.Width() << std::endl;
  std::cout << "Height: " << arr.Height() << std::endl;
  std::cout << "Size:   " << arr.Size() << std::endl;
  std::cout << std::endl;

  try
  {
    arr.Shrink( 1, 0, 9, 0 );
  }
  catch( std::out_of_range except )
  {
    std::cout << except.what();
  }
  std::cout << "Shrunk to its first row from the second column to the last column:" << std::endl;
  PrintArray( arr, arr.Width(), arr.Height() );
  std::cout << std::endl;

  unsigned int height_temp = arr.Height();
  unsigned int width_temp = arr.Width();
  arr.Expand( 2, 3 );
  for( unsigned int y = height_temp; y < arr.Height(); ++y )
  {
    for( unsigned int x = width_temp; x < arr.Width(); ++x )
    {
      try
      {
        arr.Set( x, y, 0 );
      }
      catch( std::out_of_range except )
      {
        std::cout << except.what();
      }
    }
  }
  std::cout << "Expanded 2 columns and 3 rows, with the new spaces filled with 0:" << std::endl;
  PrintArray<int>( arr, arr.Width(), arr.Height() );
  std::cout << std::endl;

  std::cout << "Original array created with the parametrized constructor:" << std::endl;
  PrintArray<int>( arr_param, arr_param.Width(), arr_param.Height() );
  std::cout << std::endl;

  std::cout << "Original array made with the copy constructor:" << std::endl;
  PrintArray<int>( arr_copy, arr_copy.Width(), arr_param.Height() );
  std::cout << std::endl;

  std::cout << "All tests finished." << std::endl;

  return 0;
}
