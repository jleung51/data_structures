/*
 *
 * Name: Jeffrey Leung
 * Date: 2015-04-15
 *
 * This header file contains function prototypes for the implementation of a linked list
 * of characters.
 *
 */

#ifndef LIST_CHAR_H
#define LIST_CHAR_H



// STRUCTURES

struct list_char;
struct element;

// This structure contains the values of a single element in a linked list of characters.
typedef struct element
{
  char value;
  struct element* next;
} element_char;

// This structure contains the head and tail of a linked list of characters.
typedef struct
{
  element_char* head;
  element_char* tail;
} list_char;



// CREATION/DESTRUCTION OF AN ELEMENT/LIST
element_char* element_char_create();  // User is responsible for freeing the allocated memory.
list_char* list_char_create();  // User is responsible for freeing the allocated memory.
void list_char_destroy( list_char* list );

// LIST PROPERTIES
void list_char_print( list_char* list );
int list_char_len( list_char* list );
int list_char_index( list_char* list, char c );  // Returns the index of the first appearance of
                                                 // char c, or -1 if c is not found or the list
                                                 // is empty.

// BASIC OPERATIONS
void list_char_initialize( list_char* list );  // Frees all elements and sets head and tail to NULL.
void list_char_append( list_char* list, char c );
void list_char_prepend( list_char* list, char c );
void list_char_insert( list_char* list, const int INDEX, char c );
void list_char_remove( list_char* list, const int index );

// COMPLEX OPERATIONS
void list_char_upper( list_char* list );
void list_char_lower( list_char* list );
int list_char_compare( list_char* list1, list_char* list2 );  // Returns 1 if the two given
                                                              // linked lists of characters
                                                              // are the same, and 0 otherwise.
list_char* list_char_duplicate( list_char* list );
void list_char_slice( list_char* list, const unsigned int BEGIN, const unsigned int END );
    // BEGIN and END are inclusive

// PRIVATE FUNCTIONS

// Only for use by list_char_destroy().
// Parameter 'el' is the first element of a linked list.
void list_char_destroy_elements( element_char* el );

// Only for use by list_char_remove().
// The tail cannot be removed with this function.
void list_char_element_remove( list_char* list, element_char* el );


#endif
