/*
 *
 * Author: Jeffrey Leung
 * Date: 2015-04-23
 *
 * This program contains an implementation of the functions required to simulate a queue
 * of characters.
 *
 * Error codes:
 *   1: User error
 *   2: Internal (code implementation) error
 *
 */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "../linked_list/list_char.h"
#include "queue_char.h"

// Only to be used by queue_char_print().
static void queue_char_print_( element_char* queue_element );



// CREATION/DESTRUCTION OF A QUEUE

// This function creates an empty queue of characters.
list_char* queue_char_create()
{
  return list_char_create();
}

// This function deallocates the memory associated with a queue of characters.
void queue_char_destroy( list_char* queue )
{
  list_char_destroy( queue );
  return;
}



// QUEUE PROPERTIES

// Only to be used by queue_char_print().
// This function recursively prints the elements of a queue in order (backwards in
// linked list order).
static void queue_char_print_( element_char* queue_element )
{
  if( queue_element != NULL )
  {
    queue_char_print_( queue_element->next );
    printf( "%c ", queue_element->value );
  }

  return;
}

// This wrapper function recursively prints the elements of a queue in order (backwards in
// linked list order).
void queue_char_print( list_char* queue_char )
{
  printf( "> " );
  queue_char_print_( queue_char->head );
  printf( ">" );

  return;
}

// This function returns the length of a queue of characters.
unsigned int queue_char_len( list_char* queue )
{
  return list_char_len( queue );
}

// This function returns the value at the top of the queue.
char queue_char_peek( list_char* queue )
{
  if( queue->head == NULL )
  {
    printf( "Error: queue_char_peek() was given an empty queue.\n" );
    exit( 1 );
  }

  return queue->head->value;
}



// BASIC OPERATIONS

// This function removes all elements from a queue of characters.
void queue_char_initialize( list_char* queue )
{
  list_char_initialize( queue );
  return;
}

// This function places (appends; at the tail) a value into the queue.
void queue_char_enqueue( list_char* queue, char c )
{
  list_char_append( queue, c );
  return;
}

// This function removes (from the head) an element from the front of the queue.
void queue_char_dequeue( list_char* queue )
{
  if( queue_char_len( queue ) == 0 )
  {
    printf( "Error: queue_char_dequeue() was given an empty queue.\n" );
    exit( 1 );
  }

  list_char_remove( queue, 0 );
  return;
}
