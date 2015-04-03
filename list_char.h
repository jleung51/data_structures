#ifndef LIST_CHAR_H
#define LIST_CHAR_H



// STRUCTURES

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
//typedef struct list_char;



// CREATION/DESTRUCTION OF AN ELEMENT/LIST

// This function creates a single character element for a linked list of characters.
// User is responsible for freeing the allocated memory.
element_char* element_char_create();

// This function creates the base of a linked list of characters.
// User is responsible for freeing the allocated memory.
list_char* list_char_create();

// This recursive function deallocates the memory allocated for each element in a linked list of
// characters, given the first element.
// The list cannot be empty.
// Only for use by list_char_destroy().
void list_char_destroy_elements( element_char* el );

// This function deallocates the memory allocated for a linked list of characters, given the list.
void list_char_destroy( list_char* list );



// LIST PROPERTIES

// This function prints the elements of a linked list of characters.
void list_char_print( list_char* list );

// This function returns the number of elements in a linked list of characters.
int list_char_len( list_char* list );

// This function returns the index of the first appearance of a given element in a linked list of
// characters, or -1 if the element is not found or the list is empty.
int list_char_index( list_char* list, char c );



// BASIC OPERATIONS

// This function frees all elements from a linked list of characters, and sets head and tail
// to NULL.
void list_char_initialize( list_char* list );

// This function adds a character to the tail of a linked list of characters.
void list_char_append( list_char* list, char c );

// This function adds a character to the head of a linked list of characters.
void list_char_prepend( list_char* list, char c );

// This function inserts an element in a given index of a linked list of characters.
// User is responsible for freeing the allocated memory.
void list_char_insert( list_char* list, const int INDEX, char c );

// This function removes a single element from a linked list of characters, given a pointer to
// the element.
// The tail cannot be removed with this function.
// Only for use by list_char_remove().
void list_char_element_remove( list_char* list, element_char* el );

// This function searches for and removes an element from a linked list of characters,
// given its index.
void list_char_remove( list_char* list, int index );



// COMPLEX OPERATIONS

// This function changes all alphabetical characters to uppercase.
void list_char_upper( list_char* list );

// This function changes all alphabetical characters to lowercase.
void list_char_lower( list_char* list );

// This function returns 1 if the two given linked lists of characters are the same,
// and 0 otherwise.
int list_char_compare( list_char* list1, list_char* list2 );

// This function returns a pointer to a deep copy of the linked list argument.
list_char* list_char_duplicate( list_char* list );

// This function concatenates a linked list of characters to begin with the index begin, and to
// end with the index end.
void list_char_slice( list_char* list, const unsigned int BEGIN, const unsigned int END );



#endif
