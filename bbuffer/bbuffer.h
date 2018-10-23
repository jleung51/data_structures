/*
 *
 * Author: Jeffrey Leung
 * Last edited: 2018-10-22
 *
 * This C program contains an implementation of a limited-size, thread-safe
 * bounded buffer to store data.
 *
 */

#ifndef BBUFFER_H
#define BBUFFER_H

#define BBUFFER_SIZE 100

// This function inserts an item into the bounded buffer, waiting if the buffer
// is full.
// This operation is thread-safe.
void bbuffer_blocking_insert(void* item);

// This function returns an item into the bounded buffer, waiting if the buffer
// is empty.
// This operation is thread-safe.
void* bbuffer_blocking_extract();

// This function returns whether or not the bounded buffer is empty.
_Bool bbuffer_is_empty();

#endif