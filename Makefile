# Source files
SOURCES  = binary_tree_basic.cpp binary_tree_sorted.cpp test.cpp

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
	# To run the output file, enter ./out

# $ make clean
# Removes created files
clean:
	rm -f out *.o *~
