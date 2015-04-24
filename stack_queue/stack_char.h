#ifndef STACK_H
#define STACK_H

// CREATION/DESTRUCTION OF A STACK
list_char* stack_char_create();
void stack_char_destroy( list_char* stack_char );

// STACK PROPERTIES
void stack_char_print( list_char* stack );
unsigned int stack_char_len( list_char* stack );
char stack_char_peek( list_char* stack );  // Returns the element at the top of the stack.

// BASIC OPERATIONS
void stack_char_initialize( list_char* stack );  // Removes all elements and sets head and tail
                                                 // to NULL.
void stack_char_push( list_char* stack, char c );  // Places a value onto the stack.
char stack_char_pop( list_char* stack );  // Removes a value from the stack and returns it.

#endif
