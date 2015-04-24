/*
 *
 * Author: Jeffrey Leung
 * Last edited: 2015-04-23
 *
 * This program contains testing for the functions in stack_char.c and queue_char.c.
 *
 */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "test.h"
#include "../linked_list/list_char.h"
#include "../stack_queue/stack_char.h"

int main()
{
  list_char* stack = stack_char_create();

  stack_char_print( stack );
  printf( "\n" );
  printf( "The amount of items on this stack is %d.\n\n", stack_char_len( stack ) );

  stack_char_push( stack, 'A' );
  stack_char_push( stack, 'B' );
  stack_char_print( stack );
  printf( "\n" );
  printf( "The amount of items on this stack is %d.\n\n", stack_char_len( stack ) );

  printf( "The top element on the stack " );
  stack_char_print( stack );
  printf( " is %c.\n\n", stack_char_peek( stack ) );

  assert( 'B' == stack_char_pop( stack ) );
  printf( "After removing the top element, the stack is " );
  stack_char_print( stack );
  printf( "\n" );
  printf( "The amount of items on this stack is %d.\n\n", stack_char_len( stack ) );

  list_char_initialize( stack );
  printf( "After initializing, the stack is " );
  stack_char_print( stack );
  printf( "\n" );
  printf( "The amount of items on this stack is %d.\n\n", stack_char_len( stack ) );

  stack_char_destroy( stack );

  return 0;
}
