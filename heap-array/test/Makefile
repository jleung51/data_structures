# Source files
SOURCES  = ../heap-array/heap_array.c \
           test.c

# Header files
HSOURCES = ../heap-array/heap_array.h

# Compiler options
CFLAGS = -std=c99 -g -Wall

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
	#   To test heap_array.c, run: make output
	#   To test for memory allocation, run: make output mem_chk
	#   To remove compiled output files, run: make clean

# $ make
output: $(SOURCES) $(HSOURCES)
	gcc $(CFLAGS) $(SOURCES) -o output -lm
	# To execute the program, run: $ ./output

# $ make mem_chk
mem_chk: $(SOURCES) $(HSOURCES)
	valgrind --leak-check=full --track-origins=yes ./output

# $ make clean
# Removes created files
clean:
	rm -f output *.o *~ ../*~ ../int_array/*~
