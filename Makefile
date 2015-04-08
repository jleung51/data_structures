# Source files
SOURCES  = test.cpp merge_sort/merge_sort.c

# Header files
HSOURCES = binary_tree.hpp

# Compiler options
CFLAGS = -g -Wall

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
