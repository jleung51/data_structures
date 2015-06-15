/*
 *
 * Author: Jeffrey Leung
 * Last edited: 2015-06-10
 *
 * This C++ program tests the implementation of the Array2d class in
 * array2d.hpp.
 *
 */

#include <iostream>

#include "array2d.hpp"
#include "test.hpp"

// This function prints the contents of a given array.
void PrintArray( int* arr, unsigned int width, unsigned int height )
{
  for( int y = 0; y < height; ++y )
  {
    for( int x = 0; x < width; ++x )
    {
      try
      {
        std::cout << arr.Get( x, y ) << " ";
      }
      catch  //TODO what goes here?
      {
        //
      }
    }
    std::cout << endl;
  }

  return;
}

int main()
{
  Array2d<int> arr;
  Array2d<int> arr_param = Array2d(10, 10);
  for( int y = 0; y < 10; ++y )
  {
    for( int x = 0; x < 10; ++x )
    {
      try
      {
        arr.Set( x, y, x + y );
        arr_param.Set( x, y, x + y );
      }
      catch  //TODO what goes here?
      {
        //
      }
    }
  }

  Array2d<int> arr_copy = Array2d( arr );

  std::cout << "New 2-d array:" << endl;
  PrintArray( arr, arr.Width(), arr.Height() );
  std::cout << endl;

  std::cout << "Width:  " << arr.Width() << endl;
  std::cout << "Height: " << arr.Height() << endl;
  std::cout << "Size:   " << arr.Size() << endl;
  std::cout << endl;

  try
  {
    arr.Shrink( 1, 1, 9, 1 );
  }
  catch  //TODO what goes here?
  {
    //
  }
  std::cout << "Shrunk to its first row from the second column to the last column:" << endl;
  PrintArray( arr, arr.Width(), arr.Height() );
  std::cout << endl;

  unsigned int height_temp = arr.Height();
  unsigned int width_temp = arr.Width();
  arr.Expand( 2, 3 );
  for( int y = height_temp; y < arr.Height(); ++y )
  {
    for( int x = width_temp; x < arr.Width(); ++x )
    {
      try
      {
        arr.Set( x, y, 0 );
      }
      catch  //TODO what goes here?
      {
        //
      }
    }
  }
  std::cout << "Expanded 2 columns and 3 rows, with the new spaces filled with 0:" << endl;
  PrintArray( arr, arr.Width(), arr.Height() );
  std::cout << endl;

  std::cout << "Original array created with the parametrized constructor:" << endl;
  PrintArray( arr_param );
  std::cout << endl;

  std::cout << "Original array made with the copy constructor:" << endl;
  PrintArray( arr_copy );
  std::cout << endl;

  std::cout << "All tests finished." << endl;
  return 0;
}
