# Source files
SOURCES  = test.c

# Header files
HSOURCES = ../int_array.h

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
	#   To test int_array.h, run: make output
	#   To remove compiled output files, run: make clean

# $ make
output: $(SOURCES) $(HSOURCES)
	gcc $(CFLAGS) $(SOURCES) -o output
	# To execute the program, run: $ ./output

# $ make clean
# Removes created files
clean:
	rm -f output *.o *~
