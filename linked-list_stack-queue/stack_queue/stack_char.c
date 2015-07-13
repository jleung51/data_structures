/*
 *
 * Author: Jeffrey Leung
 * Date: 2015-04-23
 *
 * This program contains an implementation of the functions required to simulate a stack
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
#include "stack_char.h"

// Only to be used by stack_char_print().
static void stack_char_print_( element_char* stack_element );



// CREATION/DESTRUCTION OF A STACK

// This function creates an empty stack of characters.
list_char* stack_char_create()
{
  return list_char_create();
}

// This function deallocates the memory associated with a stack of characters.
void stack_char_destroy( list_char* stack )
{
  list_char_destroy( stack );
  return;
}



// STACK PROPERTIES

// Only to be used by stack_char_print().
// This function recursively prints the elements of a stack in order (backwards in
// linked list order).
static void stack_char_print_( element_char* stack_element )
{
  if( stack_element != NULL )
  {
    stack_char_print_( stack_element->next );
    printf( "%c ", stack_element->value );
  }

  return;
}

// This wrapper function recursively prints the elements of a stack in order (backwards in
// linked list order).
void stack_char_print( list_char* stack )
{
  printf( "| " );
  stack_char_print_( stack->head );
  printf( ">" );

  return;
}

// This function returns the length of a stack of characters.
unsigned int stack_char_len( list_char* stack )
{
  return list_char_len( stack );
}

// This function returns the value at the top of the stack.
char stack_char_peek( list_char* stack )
{
  if( stack->head == NULL )
  {
    printf( "Error: stack_char_peek() was given an empty stack.\n" );
    exit( 1 );
  }

  return stack->head->value;
}



// BASIC OPERATIONS

// This function removes all elements from a stack of characters.
void stack_char_initialize( list_char* stack )
{
  list_char_initialize( stack );
  return;
}

// This function places (prepends; from the head) a value onto the stack.
void stack_char_push( list_char* stack, char c )
{
  list_char_prepend( stack, c );
  return;
}

// This function removes (from the head) an element from the top of the stack.
void stack_char_pop( list_char* stack )
{
  if( stack_char_len( stack ) == 0 )
  {
    printf( "Error: stack_char_pop() was given an empty stack.\n" );
    exit( 1 );
  }

  list_char_remove( stack, 0 );
  return;
}
