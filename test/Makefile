# Source files
SOURCES  = test.cpp

# Header files
HSOURCES = array2d.hpp

# Compiler options
CFLAGS = -std=c++14 -g -Wall

#####
###
#
# 'Make' commands
#
###
#####

# $ 'make' or 'make help'
#help:
	# INSTRUCTIONS:
	#   To test array2.hpp, run: make output
	#   To test memory allocation, run: make output && make mem_chk
	#   To remove compiled output files, run: make clean

# $ make <output_name>
output: $(SOURCES) $(HSOURCES)
	g++ $(CFLAGS) $(SOURCES) -o output
	# To execute the program, run: ./output

# $ make mem_chk
mem_chk: $(SOURCES) $(HSOURCES)
	valgrind --leak-check=full ./output

# $ make clean
# Removes created files
clean:
	rm -f output *.o *~
