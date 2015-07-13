#ifndef QUEUE_H
#define QUEUE_H

// CREATION/DESTRUCTION OF A QUEUE
list_char* queue_char_create();
void queue_char_destroy( list_char* queue );

// QUEUE PROPERTIES
void queue_char_print( list_char* queue );
unsigned int queue_char_len( list_char* queue );
char queue_char_peek( list_char* queue );  // Returns the element at the front of the queue.

// BASIC OPERATIONS
void queue_char_initialize( list_char* queue );  // Removes all elements and sets head and tail
                                                 // to NULL.
void queue_char_enqueue( list_char* queue, char c );  // Places a value into the queue.
void queue_char_dequeue( list_char* queue );  // Removes a value from the queue.

#endif
