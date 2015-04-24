/*
 *
 * Name: Jeffrey Leung
 * Date: 2015-04-15
 *
 * This program contains functions implementing a linked list of characters.
 *
 * Error codes:
 *   1: User error
 *   2: Internal (code implementation) error
 *
 */

#include <assert.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#include "list_char.h"
#include "../merge_sort/merge_sort.h"



// STATIC (PRIVATE) FUNCTIONS

// User is responsible for freeing the allocated memory.
static element_char* element_char_create();

// Only for use by list_char_destroy().
// Parameter 'el' is the first element of a linked list.
static void list_char_destroy_elements( element_char* el );

// Only for use by list_char_remove().
// The tail cannot be removed with this function.
static void list_char_element_remove( list_char* list, element_char* el );



// CREATION/DESTRUCTION OF AN ELEMENT/LIST

// This function creates a single, empty character element for a linked list of characters.
// User is responsible for freeing the allocated memory.
element_char* element_char_create()
{
  element_char* el = malloc( sizeof(element_char) );
  if( el == NULL )
  {
    printf( "Error: Memory allocation for element_char_create() failed.\n" );
    exit( 1 );
  }

  el->value = 0;
  el->next = NULL;

  return el;
}

// This function creates the base of a linked list of characters, with the head and tail as NULL.
// User is responsible for freeing the allocated memory.
list_char* list_char_create()
{
  list_char* list = malloc( sizeof(list_char) );
  if( list == NULL )
  {
    printf( "Error: Memory allocation for list_char_create() failed.\n" );
    exit( 1 );
  }

  list->head = NULL;
  list->tail = NULL;

  return list;
}

// Only for use by list_char_destroy().
// This recursive function deallocates the memory allocated for each element in a linked list of
// characters, given the first element.
static void list_char_destroy_elements( element_char* el )
{
  if( el != NULL )
  {
    if( el->next != NULL )
    {
      list_char_destroy_elements( el->next );
    }
    free( el );
  }
  return;
}

// This wrapper function deallocates the memory allocated for a linked list of characters, given the list.
void list_char_destroy( list_char* list )
{
  if( list == NULL )
  {
    printf( "Error: list_char_destroy() was given a null pointer.\n" );
    exit( 1 );
  }

  if( list->head != NULL )
  {
    list_char_destroy_elements( list->head );
  }  
  free( list );
  return;
}



// LIST PROPERTIES

// This function prints the elements of a linked list of characters.
void list_char_print( list_char* list )
{
  if( list == NULL )
  {
    printf( "Error: list_char_print() was given a null pointer.\n" );
    exit( 1 );
  }

  printf( "{ " );
  element_char* el;
  for( el = list->head; el != NULL; el = el->next )
  {
    printf( "%c ", el->value );
  }
  printf( "}" );

  return;
}

// This function returns the number of elements in a linked list of characters.
int list_char_len( list_char* list )
{
  if( list == NULL )
  {
    printf( "Error: list_char_len() was given a null pointer.\n" );
    exit( 1 );
  }

  int len = 0;
  element_char* el;
  for( el = list->head; el != NULL; el = el->next )
  {
    len++;
  }

  return len;
}

// This function returns the index of the first appearance of a given element in a linked list of
// characters, or -1 if the element is not found or the list is empty.
int list_char_find( list_char* list, char c )
{
  if( list == NULL )
  {
    printf( "Error: list_char_find() was given a null pointer.\n" );
    exit( 1 );
  }

  int index = 0;
  element_char* el;
  for( el = list->head; el != NULL; el = el->next )
  {
    if( c == el->value )
    {
      return index;
    }
    index++;
  }

  return -1;
}

// This function returns the value of an element at a given index.
char list_char_index( list_char* list, unsigned int index )
{
  if( list == NULL )
  {
    printf( "Error: list_char_index was given a null pointer.\n" );
    exit( 1 );
  }

  int len = list_char_len( list );
  if( index >= len )
  {
    printf( "Error: list_char_index was given an invalid index.\n" );
    exit( 1 );
  }

  element_char* el = list->head;
  int i;
  for( i = 0; i < index; i++ )
  {
    el = el->next;
  }

  return el->value;
}



// BASIC OPERATIONS

// This function frees all elements from a linked list of characters, and sets head and tail
// to NULL.
void list_char_initialize( list_char* list )
{
  if( list == NULL )
  {
    printf( "Error: list_char_initialize() was given a null pointer.\n" );
    exit( 1 );
  }

  int len = list_char_len( list );

  int i;
  for( i = 0; i < len; i++ )
  {
    list_char_remove( list, 0 );
  }

  if( list->head != NULL || list->tail != NULL )
  {
    printf( "Internal error: list_char_remove() did not set both head and tail to null when "\
            "called by list_char_initialize.\n"\
            "Please contact original owner of the repository.\n" );
    exit( 2 );
  }

  return;
}

// This function adds a character to the tail of a linked list of characters.
void list_char_append( list_char* list, char c )
{
  if( list == NULL )
  {
    printf( "Error: list_char_append() was given a null pointer.\n" );
    exit( 1 );
  }

  element_char* el = element_char_create();

  el->value = c;
  el->next  = NULL;

  // Empty list
  if( list->head == NULL )
  {
    list->head = el;
    list->tail = el;
  }
  else
  {
    list->tail->next = el;
    list->tail       = el;
  }

  return;
}

// This function adds a character to the head of a linked list of characters.
void list_char_prepend( list_char* list, char c )
{
  if( list == NULL )
  {
    printf( "Error: list_char_prepend() was given a null pointer.\n" );
    exit( 1 );
  }

  element_char* el = element_char_create();
  el->value = c;

  if( list->head == NULL )
  {
    el->next = NULL;
    list->tail = el;
  }
  else
  {
    el->next = list->head;
  }
  list->head = el;

  return;
}

// This function inserts an element in a given index of a linked list of characters.
void list_char_insert( list_char* list, const int INDEX, char c )
{
  if( list == NULL )
  {
    printf( "Error: list_char_insert() was given a null pointer.\n" );
    exit( 1 );
  }

  int len = list_char_len( list );
  if( INDEX < 0 || len < INDEX )
  {
    printf( "Error: list_char_insert() was given an index out of bounds - "\
            "%d in an array of length %d.\n", INDEX, len );
    exit( 1 );
  }

  if( INDEX != len )
  {
    element_char* el = list->head;
    int i;
    for( i = 0; i < INDEX; i++ )
    {
      el = el->next;
    }

    element_char* el_copy = element_char_create();

    el_copy->value = el->value;
    el_copy->next  = el->next;

    el->value = c;
    el->next  = el_copy;

    if( INDEX == len-1 )
    {
      list->tail = el_copy;
    }
  }
  else
  {
    list_char_append( list, c );
  }

  return;
}

// Only for use by list_char_remove().
// This function removes a single element from a linked list of characters, given a pointer to
// the element.
// The tail cannot be removed with this function.
static void list_char_element_remove( list_char* list, element_char* el  )
{
  if( el->next == NULL )
  {
    printf( "Internal error: list_char_remove() gave list_char_element_remove() the "\
            "tail element.\nPlease contact original owner of the repository.\n" );
    exit( 2 );
  }

  element_char* el_after = el->next;

  el->value = el_after->value;
  el->next  = el_after->next;

  free(el_after);

  return;
}

// This function searches for and removes an element from a linked list of characters,
// given its index.
void list_char_remove( list_char* list, const int INDEX )
{
  if( list == NULL )
  {
    printf( "Error: list_char_remove() was given a null pointer.\n" );
    exit( 1 );
  }

  if( list->head == NULL )
  {
    return;
  }

  int len = list_char_len( list );
  if( INDEX < 0 || len <= INDEX )
  {
    printf( "Error: list_char_remove() was given an index out of bounds - "\
            "%d in an array of length %d.\n", INDEX, len );
    exit( 1 );
  }

  int i = 0;
  element_char* el;
  element_char* el_before;
  for( el = list->head; el->next != NULL; el = el->next )  // First to second-last elements
  {
    if( INDEX == i )
    {
      list_char_element_remove( list, el );
      return;
    }
    i++;
    el_before = el;
  }

  // Manually freeing the only element
  if( len == 1 )
  {
    free( el );
    list->head = NULL;
    list->tail = NULL;
  }
  // Manually freeing the tail element
  else if( INDEX == len-1 )
  {
    el_before->next = NULL;
    list->tail = el_before;
    free( el );
  }

  return;
}



// COMPLEX OPERATIONS

// This function changes all alphabetical characters to uppercase in a linked list of characters.
void list_char_upper( list_char* list )
{
  if( list == NULL )
  {
    printf( "Error: list_char_upper() was given a null pointer.\n" );
    exit( 1 );
  }

  element_char* el;
  for( el = list->head; el != NULL; el = el->next )
  {
    el->value = toupper(el->value);
  }

  return;
}

// This function changes all alphabetical characters to lowercase in a linked list of characters.
void list_char_lower( list_char* list )
{
  if( list == NULL )
  {
    printf( "Error: list_char_lower() was given a null pointer.\n" );
    exit( 1 );
  }

  element_char* el;
  for( el = list->head; el != NULL; el = el->next )
  {
    el->value = tolower(el->value);
  }

  return;
}

// This function returns 1 if the two given linked lists of characters are the same,
// and 0 otherwise.
int list_char_compare( list_char* list1, list_char* list2 )
{
  if( list1 == NULL )
  {
    printf( "Error: list_char_compare() was given a null pointer for its first parameter.\n" );
    exit( 1 );
  }
  else if( list2 == NULL )
  {
    printf( "Error: list_char_compare() was given a null pointer for its second parameter.\n" );
    exit( 1 );
  }

  if( list_char_len(list1) != list_char_len(list2) )
  {
    return 0;
  }

  element_char* el1 = list1->head;
  element_char* el2 = list2->head;

  while( el1 != NULL && el2 != NULL )
  {
    if( el1->value != el2->value )
    {
      return 0;
    }

    el1 = el1->next;
    el2 = el2->next;
  }

  return 1;
}

// This function returns a pointer to a deep copy of the linked list of characters argument.
list_char* list_char_duplicate( list_char* list )
{
  if( list == NULL )
  {
    printf( "Error: list_char_duplicate() was given a null pointer.\n" );
    exit( 1 );
  }

  list_char* list_copy = list_char_create();

  if( list_copy != NULL )
  {
    element_char* el;
    for( el = list->head; el != NULL; el = el->next )
    {
      list_char_append( list_copy, el->value );
    }
  }

  return list_copy;
}

// This function concatenates a linked list of characters to begin with the index begin, and to
// end with the index end.
void list_char_slice( list_char* list, const unsigned int BEGIN, const unsigned int END )
{
  if( list == NULL )
  {
    printf( "Error: list_char_slice() was given a null pointer.\n" );
    exit( 1 );
  }

  int len = list_char_len( list );

  if( BEGIN > END )
  {
    printf( "Error: list_char_slice() was given a beginning value (%d) greater than its"\
            " end value (%d).\n", BEGIN, END );
    exit( 1 );
  }
  else if( END >= len )
  {
    printf( "Error: list_char_slice() was given an end value (%d) greater than its"\
            " length (%d).\n", END, len );
    exit( 1 );
  }

  element_char* el = list->head;
  element_char* el_temp;

  // Finds and assigns the new head element
  int i;
  for( i = 0; i < BEGIN; i++ )
  {
    el_temp = el;
    el = el->next;
    free( el_temp );
  }
  list->head = el;

  // Finds and assigns the new tail element
  int j;
  for( j = BEGIN; j < END; j++ )
  {
    el = el->next;
  }
  list->tail = el;

  // Frees the remaining elements
  el = el->next;
  while( el->next != NULL )
  {
    el_temp = el;
    el = el->next;
    free( el_temp );
  }

  list->tail->next = NULL;

  return;
}

// This function returns all the elements in a linked list into an array.
void list_char_to_array( list_char* list, char* array )
{
  if( list == NULL )
  {
    printf( "Error: list_char_to_array() was given a null pointer for its list.\n" );
    exit( 1 );
  }
  if( array == NULL )
  {
    printf( "Error: list_char_to_array() was given a null pointer for its array.\n" );
    exit( 1 );
  }

  int i = 0;
  element_char* el;
  for( el = list->head; el != NULL; el = el->next )
  {
    array[i] = el->value;
    i++;
  }

  return;
}

// This function sorts the elements in a linked list using merge_sort.
void list_char_sort( list_char* list )
{
  if( list == NULL )
  {
    printf( "Error: list_char_sort() was given a null pointer.\n" );
    exit( 1 );
  }
  else if( list->head == NULL )
  {
    return;
  }

  int len = list_char_len( list );
  char array_char[len];
  list_char_to_array( list, array_char );

  // Converting from char to int array
  int array_int[len];
  int i;
  for( i = 0; i < len; i++ )
  {
    array_int[i] = array_char[i];
  }

  merge_sort( array_int, len );

  // Converting from int to char array
  for( i = 0; i < len; i++ )
  {
    array_char[i] = array_int[i];
  }

  i = 0;
  element_char* el;
  for( el = list->head; el != NULL; el = el->next )
  {
    el->value = array_char[i];
    i++;
  }

  return;
}
