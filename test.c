/*
 *
 * Name: Jeffrey Leung
 * Date: 2015-03-19
 *
 * This program contains tests for the linked list functions in list.c.
 *
 */

#include <stdio.h>

#include "test.h"
#include "list_char.h"



// This function prints a long spacer for separating sections.
void spacer()
{
  printf( "_____________________________________________________________________\n\n" );
  return;
}



int main()
{

  spacer();
  printf( "Each pair of the following lines should match exactly.\n" );
  spacer();

  list_char* list = list_char_create();

  printf( "Test 1:\n" );
  int i;
  char c;
  for( i = 0; i < 5; i++ )
  {
    c = '0' + i;
    list_char_append( list, c );
  }
  printf( "{ 0 1 2 3 4 }\n" );
  list_char_print( list );
  printf( "\n\n" );

  printf( "Test 2:\n" );
  for( i = 0; i < 5; i++ )
  {
    c = 'e' - i;
    list_char_prepend( list, c );
  }
  printf( "{ a b c d e 0 1 2 3 4 }\n" );
  list_char_print( list );
  printf( "\n\n" );

  printf( "Test 3:\n" );
  int len = list_char_len( list );
  printf( "10\n" );
  printf( "%d\n\n", len );

  printf( "Test 4:\n" );
  int index1 = list_char_index( list, 'a' );
  int index2 = list_char_index( list, 'd' );
  int index3 = list_char_index( list, '4' );
  int index4 = list_char_index( list, '9' );
  printf( "0 3 9 -1\n" );
  printf( "%d %d %d %d\n\n", index1, index2, index3, index4 );

  spacer();

  printf( "Test 5:\n" );
  list_char_remove( list, index3 );
  list_char_remove( list, index2 );
  list_char_remove( list, index1 );
  printf( "{ b c e 0 1 2 3 }\n" );
  list_char_print( list );
  printf( "\n\n" );

  printf( "Test 6:\n" );
  list_char_insert( list, 3, 'X' );
  printf( "{ b c e X 0 1 2 3 }\n" );
  list_char_print( list );
  printf( "\n\n" );

  printf( "Test 7:\n" );
  list_char_remove( list, 3 );
  printf( "{ b c e 0 1 2 3 }\n" );
  list_char_print( list );
  printf( "\n\n" );

  printf( "Test 8:\n" );
  list_char_insert( list, list_char_len(list), 'X' );
  printf( "{ b c e 0 1 2 3 X }\n" );
  list_char_print( list );
  printf( "\n\n" );

  spacer();

  printf( "Test 9:\n" );
  list_char_remove( list, list_char_len(list)-1 );
  printf( "{ b c e 0 1 2 3 }\n" );
  list_char_print( list );
  printf( "\n\n" );

  printf( "Test 10:\n" );
  list_char* list2 = list_char_duplicate( list );
  list_char_append( list, 'X' );
  printf( "{ b c e 0 1 2 3 X }\n" );
  list_char_print( list );
  printf( "\n\n" );

  printf( "Test 11:\n" );
  printf( "{ b c e 0 1 2 3 }\n" );
  list_char_print( list2 );
  printf( "\n\n" );

  printf( "Test 12:\n" );
  len = list_char_len( list );
  list_char_slice( list, 1, len-2 );
  printf( "{ c e 0 1 2 3 }\n" );
  list_char_print( list );
  printf( "\n\n" );

  spacer();

  printf( "Test 13:\n" );
  len = list_char_len( list );
  list_char_slice( list, 0, 0 );
  printf( "{ c }\n" );
  list_char_print( list );
  printf( "\n\n" );

  printf( "Test 14:\n" );
  list_char_initialize( list );
  printf( "(intentionally blank)\n" ); 
  list_char_print( list );
  printf( "\n" );

  printf( "Test 15:\n" );
  for( i = 0; i < 5; i++ )
  {
    list_char_append( list, 'a' + i );
  }
  list_char_append( list, '1' );
  printf( "{ A B C D E 1 }\n" );
  list_char_upper( list );
  list_char_print( list );
  printf( "\n\n" );

  printf( "Test 16:\n" );
  printf( "{ a b c d e 1 }\n" );
  list_char_lower( list );
  list_char_print( list );
  printf( "\n\n" );

  spacer();

  printf( "Test 17:\n" );
  list_char_initialize( list );
  printf( "(intentionally blank)\n" ); 
  list_char_print( list );
  printf( "\n" );

  printf( "Test 18:\n" );
  list_char_initialize( list );
  for( i = 0; i < 5; i++ )
  {
    list_char_append( list, 'a' + i );
  }
  list_char_initialize( list2 );
  for( i = 0; i < 5; i++ )
  {
    list_char_append( list, 'b' + i );
  }
  i = list_char_compare( list, list );
  int j = list_char_compare( list, list2 );
  printf( "1 0\n" );
  printf( "%d %d\n\n", i, j );

  list_char_destroy( list  );
  list_char_destroy( list2 );

  return 0;
}
