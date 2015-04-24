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
#include "../stack_queue/queue_char.h"

// This function prints a long spacer for separating sections.
void spacer()
{
  printf( "_____________________________________________________________________\n\n" );
  return;
}

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

  stack_char_pop( stack );
  printf( "After removing the top element, the stack is " );
  stack_char_print( stack );
  printf( "\n" );
  printf( "The amount of items on this stack is %d.\n\n", stack_char_len( stack ) );

  stack_char_initialize( stack );
  printf( "After initializing, the stack is " );
  stack_char_print( stack );
  printf( "\n" );
  printf( "The amount of items on this stack is %d.\n\n", stack_char_len( stack ) );

  stack_char_destroy( stack );



  spacer();

  list_char* queue = queue_char_create();

  queue_char_print( queue );
  printf( "\n" );
  printf( "The amount of items in this queue is %d.\n\n", queue_char_len( queue ) );

  queue_char_enqueue( queue, 'A' );
  queue_char_enqueue( queue, 'B' );
  queue_char_print( queue );
  printf( "\n" );
  printf( "The amount of items in this queue is %d.\n\n", queue_char_len( queue ) );

  printf( "The front element in the queue " );
  queue_char_print( queue );
  printf( " is %c.\n\n", queue_char_peek( queue ) );

  queue_char_dequeue( queue );
  printf( "After removing the front element, the queue is " );
  queue_char_print( queue );
  printf( "\n" );
  printf( "The amount of items in this queue is %d.\n\n", queue_char_len( queue ) );

  queue_char_initialize( queue );
  printf( "After initializing, the queue is " );
  queue_char_print( queue );
  printf( "\n" );
  printf( "The amount of items in this queue is %d.\n\n", queue_char_len( queue ) );

  queue_char_destroy( queue );

  return 0;
}
