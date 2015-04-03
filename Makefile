# Source files
SOURCES  = binary_tree_basic.cpp test.cpp# binary_tree_sorted.cpp test.cpp

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

# $ make clean
# Removes created files
clean:
	rm -f out *.o *~
