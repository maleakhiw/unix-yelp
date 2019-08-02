# Makefile used for Assignment 1
# Author: Maleakhi Agung Wijaya
# Student Number: 784091
# Date: 8/09/2016
#

CC = gcc
FLAGS = -g -Wall

# Target for different stage
STAGE1 = yelp1
STAGE2 = yelp2

# run yelp1 if only typing make (default)
default: $(STAGE1) $(STAGE2)

# Compile Stage 1
dictionary1.o: dictionary1.c dictionary1.h
	$(CC) $(FLAGS) -c dictionary1.c 

$(STAGE1): main1.c dictionary1.o
	$(CC) $(FLAGS) -o $(STAGE1) main1.c dictionary1.o
	
# Compile Stage 2
list.o: list.c list.h
	$(CC) $(FLAGS) -c list.c

dictionary2.o: dictionary2.c dictionary2.h list.h
	$(CC) $(FLAGS) -c dictionary2.c

$(STAGE2): main2.c dictionary2.o list.o
	$(CC) $(FLAGS) -o $(STAGE2) main2.c dictionary2.o list.o

# Compile key generator
generate_key: generate_key.c
	$(CC) $(FLAGS) -o generate_key generate_key.c 

# Delete associate files
clean:
	rm -f *.o
	rm -f $(STAGE1) $(STAGE2)
	rm -f generate_key
