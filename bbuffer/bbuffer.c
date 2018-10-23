/*
 *
 * Author: Jeffrey Leung
 * Last edited: 2018-10-22
 *
 * This C program contains an implementation of a limited-size, thread-safe
 * bounded buffer to store data.
 *
 */

#include <semaphore.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "logger.h"
#include "bbuffer.h"

// Buffer and management variables
static void* buffer[BBUFFER_SIZE];
static int len = 0;

static sem_t mutex;
static sem_t current;
static sem_t available;

static _Bool initialized = false;

// Function prototypes

// This function initializes the semaphores used by the bounded buffer.
static void bbuffer_init();

// Functions

void bbuffer_blocking_insert(void* item) {
  if (!initialized) {
    initialized = true;
    bbuffer_init();
  }

  sem_wait(&available);
  sem_wait(&mutex);

  logger_log(DEBUG, "Adding item to bounded buffer.");
  buffer[len] = item;
  ++len;

  sem_post(&mutex);
  sem_post(&current);
}

void* bbuffer_blocking_extract() {
  if (!initialized) {
    initialized = true;
    bbuffer_init();
  }

  sem_wait(&current);
  sem_wait(&mutex);

  logger_log(DEBUG, "Removing item from bounded buffer.");
  void* retval = buffer[len-1];
  --len;

  sem_post(&mutex);
  sem_post(&available);
  return retval;
}

_Bool bbuffer_is_empty() {
  return len == 0;
}

static void bbuffer_init() {
  sem_init(&mutex, 0, 1);
  sem_init(&current, 0, 0);
  sem_init(&available, 0, BBUFFER_SIZE);
}