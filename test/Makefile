# Source files
SOURCES  = test.cpp

# Header files
HSOURCES = ../expandable_array.hpp

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
output: $(SOURCES) $(HSOURCES)
	g++ $(CFLAGS) $(SOURCES) -o output
	# To execute the program, run: $ ./output

# $ make clean
# Removes created files
clean:
	rm -f output *.o *~
