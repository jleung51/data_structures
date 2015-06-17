/*
 *
 * Author: Jeffrey Leung
 * Last edited: 2015-06-17
 *
 * This C program contains a testing implementation of the functions in
 * int_array.c.
 *
 */

#include <stdio.h>

#include "../int_array/int_array.h"

int main()
{
  IntArray* array1 = IntArrayCreate();

  printf( "Empty array:\n" );
  IntArrayPrint( array1 );
  printf( "\n\n" );

  for( int i = 0; i < 50; i++ )
  {
    IntArrayAppend( array1, i );
  }
  printf( "Array with the numbers 0-49:\n" );
  IntArrayPrint( array1 );
  printf( "\n\n" );

  IntArrayRemoveLast( array1 );
  IntArrayRemoveLast( array1 );
  IntArrayRemoveLast( array1 );
  IntArrayRemoveLast( array1 );
  IntArrayRemoveLast( array1 );
  printf( "Array with the numbers 0-44:\n" );
  IntArrayPrint( array1 );
  printf( "\n\n" );

  IntArrayRemove( array1, 0 );
  printf( "Array with the numbers 44, 1-43:\n" );
  IntArrayPrint( array1 );
  printf( "\n\n" );

  printf( "First element in the array: %d", IntArrayGet( array1, 0 ) );
  printf( "\n\n" );

  IntArray* array2 = IntArrayCopy( array1 );

  printf( "Copy of the array with the numbers 44, 1-43:\n" );
  IntArrayPrint( array2 );
  printf( "\n\n" );

  for( int i = 0; i < 50; i++ )
  {
    IntArrayAppend( array2, i );
  }
  printf( "Above array with the numbers 44, 1-43, 0-49:\n" );
  IntArrayPrint( array2 );
  printf( "\n\n" );

  IntArrayRemoveLast( array2 );
  printf( "Above array with the numbers 44, 1-43, 0-48:\n" );
  IntArrayPrint( array2 );
  printf( "\n\n" );

  printf( "First element in the array: %d", IntArrayGet( array2, 0 ) );
  printf( "\n\n" );

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
  IntArrayDelete( array1 );
  IntArrayDelete( array2 );

  return 0;
}
