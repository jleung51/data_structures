# Source files
SOURCES  = ../merge_sort/merge_sort.c test.cpp

# Header files
HSOURCES = ../merge_sort/merge_sort.h ../binary_tree.hpp

# Compiler options
CFLAGS = -std=c++11 -g -Wall

#####
###
#
# 'Make' commands
#
###
#####

# $ make
out: $(SOURCES) $(HSOURCES)
	g++ $(CFLAGS) $(SOURCES) -o out
	# To execute the program, run: $ ./out

# $ make clean
# Removes created files
clean:
	rm -f out *.o *~
