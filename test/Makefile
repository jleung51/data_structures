# Source files
SOURCES  = ../int_array/int_array.c \
           test.c

# Header files
HSOURCES = ../int_array/int_array.h

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
	#   To test int_array.h, run: make output
	#   To test for memory allocation, run: make mem_chk
	#   To remove compiled output files, run: make clean

# $ make
output: $(SOURCES) $(HSOURCES)
	gcc $(CFLAGS) $(SOURCES) -o output -lm
	# To execute the program, run: $ ./output

# $ make mem_chk
mem_chk: $(SOURCES) $(HSOURCES)
	gcc $(CFLAGS) $(SOURCES) -o output -lm
	valgrind --leak-check=full ./output

# $ make clean
# Removes created files
clean:
	rm -f output *.o *~
