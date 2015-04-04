# Source files
SOURCES  = test.cpp# binary_tree_sorted.cpp test.cpp

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
<<<<<<< HEAD
	# To run the output file, enter ./out
=======
	# To execute the program, run: $ ./out
>>>>>>> Template

# $ make clean
# Removes created files
clean:
	rm -f out *.o *~
