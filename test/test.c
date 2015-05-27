/*
 *
 * Author: Jeffrey Leung
 * Last edited: 2015-05-27
 *
 * This C program contains a testing implementation of the functions in
 * int_array.c.
 *
 */

#include <stdio.h>

#include "../int_array.h"

int main()
{
  IntArray* array = IntArrayCreate();

  IntArrayPrint( array );
  printf( "\n" );

  for( int i = 0; i < 50; i++ )
  {
    IntArrayAppend( array, i );
  }

  IntArrayPrint( array );
  printf( "\n" );

  IntArrayRemoveLast( array );
  IntArrayPrint( array );
  printf( "\n" );

  IntArrayRemove( array, 0 );
  IntArrayPrint( array );
  printf( "\n" );

  printf( "First element in the array: %d\n", IntArrayGet( array, 0 ) );

/*
  printf( "The array containing the numbers 0-49 is " );
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
*/
  IntArrayDelete( array );

  return 0;
}
