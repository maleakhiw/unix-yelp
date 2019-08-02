/* STAGE 2 DATABASE IMPLEMENTATION
 * Author: Maleakhi Agung Wijaya
 * Student Number: 784091
 * Date: 8/09/2016
 * Version : 1.0
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "dictionary2.h"

/***************************CONSTANT***********************************/

#define NOT_FOUND "NOTFOUND" 

#define INPUT_FILE_ARGUMENT 1
#define OUTPUT_FILE_ARGUMENT 2
#define NUMBER_OF_ARGUMENT 3

#define KEY_DELIMITER ','
#define DATA_DELIMITER '\n'

#define TRUE 1
#define FALSE 0

/***************************DECLARATION*******************************/

/** Main function declaration */
void insert(FILE *fileIn, tree_t **root);
int getKey(char searchKey[], int limit);
void search(FILE* fileOut, tree_t *root);

/*******************************MAIN**********************************/

/* Main function control stage 2 implementation */
int 
main(int argc, char *argv[]) {

	// Create dictionary and initialize the root to NULL
	dict_t *tree = makedict(); 

	// Check input data and output data validity
	if (argc < NUMBER_OF_ARGUMENT) {
		printf("Please enter valid command line argument.\n");
		exit(EXIT_FAILURE);
	}

	// Process file input
	FILE *fileIn = fopen(argv[INPUT_FILE_ARGUMENT], "r");
	FILE *fileOut = fopen(argv[OUTPUT_FILE_ARGUMENT], "w");

	// Insert input file into dictionary (BST)
	insert(fileIn, &(tree -> root));

	// Search and output search results to output file
	search(fileOut, tree -> root);

	// Finish use of tree
	freedict(tree);

	// Close the file
	fclose(fileIn);
	fclose(fileOut);

	return 0;
}

/** Function that search and output the data retrieved from dictionary 
 * @param fileOut Pointer to ouput file for writing purpose
 * @param root First node of the tree
 */
void
search(FILE* fileOut, tree_t *root) {
	// Store the key that will be search
	name_t searchKey;

	tree_t *searchResult; // Take address of particular nodes found in search
	list_t *current; // used for traversal to get all data about that node

	/* Search the BST based on the key provided from stdin
     * and write the data to given output file
     */
	 while (getKey(searchKey, MAX_KEY - NULL_BYTE_LENGTH) != EOF) {
		searchResult = searchTree(root, searchKey);

		// If key is not found thus searchResult = NULL
		if (searchResult == NULL) {
			fprintf(fileOut, "%s --> %s\n\n", searchKey, NOT_FOUND);
		}
		
		// Search all result regarding particular key in the linked list
		else {
			current = searchResult -> head;
			while (current) {
				fprintf(fileOut, "%s --> %s\n\n" , searchKey, current -> data);
				current = current -> next;
			}
		}
	}
}

/** Function use to isolate word (key that are entered from user or txt file)
 * @param searchKey String used as container for search key input
 * @param limit Maximum of length that searchKey contain
 * @return Indicates success
 */
int
getKey(char searchKey[], int limit) {
	int character;
	int index = 0;

	// Take the first character (for checking EOF)
	character = getchar();

	// Check whether any character left to read
	if (character == EOF) {
		return EOF;
	}

	/** Process the character and append it to string for search key, note 
	 *  that key is given on each line
	 */
	while((character != EOF && character != '\n') && (index < limit)) {
		searchKey[index ++] = character;
		character = getchar();
	}
	// Close the string
	searchKey[index] = '\0';

	// Indicates there is key successfully read
	return TRUE;
}

/** Process input from file and append appropriate value to both key and data 
 * @param fileIn Pointer to input files used for read purpose
 * @param root Address of pointer, will be passed to insertTree
 */
void
insert(FILE *fileIn, tree_t **root) {
	int i, j;

	// Store key (name) and data that will be inserted into dictionary
	name_t key;
	data_t data;
	
	// Storage for each instance of object
	int lineLength = MAX_DATA + MAX_KEY + NULL_BYTE_LENGTH;
	char temporary[lineLength];

	// Iterate every single line on the file
	while(fgets(temporary, lineLength , fileIn) != NULL) {
		/* Iterate through every character in the string until (,) and store
		 * in first string array consist of key, iterate through until \n and
		 * store in second string array consist of data
		 */
		for (i = 0; temporary[i] != KEY_DELIMITER; i ++) {
			key[i] = temporary[i];
		}
		// Close the string
		key[i] = '\0'; 
	
		for (i ++, j = 0; temporary[i] != DATA_DELIMITER; i ++) {
			data[j ++] = temporary[i];
		}
		// Close the string
		data[j] = '\0';

		// Insert both key and data into BST
		insertTree(root, key, data);
	}
}
