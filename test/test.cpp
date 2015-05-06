/*
 *
 * Author: Jeffrey Leung
 * Last edited: 2015-05-05
 *
 * This program contains a testing implementation of the expandable array class and methods.
 *
 */

#include <iostream>

#include "../expandable_array.hpp"

int main()
{
  ExpandableArray<int> array;

  for( int i = 0; i < 50; i++ )
  {
    array.Append( i );
  }
  std::cout << "The array containing the numbers 0-49 is " ;
  array.Print();
  std::cout << ".\n\n" ;

  for( int i = 0; i < 10; i++ )
  {
    array.Remove();
  }
  std::cout << "The array containing the numbers 0-39 is " ;
  array.Print();
  std::cout << ".\n\n" ;

  std::cout << "The first element of the array is " << array.Retrieve( 0 ) << ".\n\n" ;

  array.Remove( 0 );
  std::cout << "The array containing the numbers 39, and 1-38 is " ;
  array.Print();
  std::cout << ".\n\n" ;

  unsigned long len = array.Length();
  for( unsigned int i = 0; i < len; i++ )
  {
    array.Set( i, -i );
  }
  std::cout << "The array containing the numbers 0 to -38 is " ;
  array.Print();
  std::cout << ".\n\n" ;

  return 0;
}
