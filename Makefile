# Source files
SOURCES = merge_sort/merge_sort.c list_char.c test.c

# Header files
HSOURCES = merge_sort/merge_sort.h list_char.h test.h

# Compiler options
CFLAGS = -std=c99 -g -lm -Wall

#####
###
#
# 'Make' commands
#
###
#####

# $ make
out: $(SOURCES) $(HSOURCES)
	gcc $(CFLAGS) $(SOURCES) -o out
	# To execute the program, run: ./out

# $ make <custom>
#<custom>: <source_files>
#	<command>

# $ make clean
# Removes created files
clean:
	rm -f out *.o
