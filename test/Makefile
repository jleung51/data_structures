# Linked list source files
LL_SOURCES = ../merge_sort/merge_sort.c \
             ../linked_list/list_char.c

# Linked list header files
LL_HSOURCES = ../merge_sort/merge_sort.h \
              ../linked_list/list_char.h

# Stack/queue source files
STA_QUE_SOURCES = ../stack_queue/stack_char.c \
                  ../stack_queue/queue_char.c

# Stack/queue header files
STA_QUE_HSOURCES = ../stack_queue/stack_char.h \
                   ../stack_queue/queue_char.h

# Compiler options
CFLAGS = -std=c99 -g -lm -Wall

#####
###
#
# 'Make' commands
#
###
#####

# $ 'make' or 'make help'
help:
	# INSTRUCTIONS:
	#   To test the linked list implementation,  run: make list
	#   To test the stack/queue implementations, run: make sta_que
	#   To remove compiled output files, run:         make clean

# $ 'make list'
list: $(LL_SOURCES) $(LL_HSOURCES) test.c test.h
	gcc $(CFLAGS) $(LL_SOURCES) test.c -o list
	# To execute the program, run: ./list

# $ 'make sta_que'
sta_que: $(LL_SOURCES) $(LL_HSOURCES) $(STA_QUE_SOURCES) $(STA_QUE_HSOURCES) test_stack_queue.c test.h
	gcc $(CFLAGS) $(LL_SOURCES) $(STA_QUE_SOURCES) test_stack_queue.c -o sta_que
	# To execute the program, run: ./sta_que

# $ 'make clean'
# Removes created files
clean:
	rm -f list sta_que *.o
