# Source files
SOURCES  = test_node.cpp \
           test_tree.cpp

# Header files
HSOURCES = ../binary_node.hpp \
           ../binary_tree.hpp

# Compiler options
CFLAGS = -std=c++11 -g -Wall

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
	#   To compile the binary node class, run: make node
	#   To compile the binary tree class, run: make tree
	#   To compile and test memory allocation, run: make mem_chk
	#   To remove compiled output files, run: make clean

# $ make node
node: $(SOURCES) $(HSOURCES)
	g++ $(CFLAGS) test_node.cpp -o out
	# To execute the program, run: $ ./out

# $ make tree
tree: $(SOURCES) $(HSOURCES)
	g++ $(CFLAGS) test_tree.cpp -o out
	# To execute the program, run: $ ./out

# $ make mem_chk
mem_chk: $(SOURCES) $(HSOURCES)
	g++ $(CFLAGS) $(SOURCES) -o <output_name>
	valgrind --leak-check=full --track-origins=yes ./out

# $ make clean
# Removes created files
clean:
	rm -f out *.o *~
