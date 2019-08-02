/* STAGE 1 DICTIONARY (BST)
 * Author: Maleakhi Agung Wijaya
 * Student Number: 784091
 * Date: 8/09/2016
 * Version: 1.0
 */

#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "dictionary1.h"

/*****************************BST************************************/

/** Create empty tree (struct that holds the root)
 * @return tree Pointer to struct the holds the root
 */
dict_t 
*makedict() {
	dict_t *tree = malloc(sizeof(dict_t));
	assert(tree != NULL);

	// Initialize the root to NULL as it is empty
	tree -> root = NULL;
	return tree;
}

/** Insert into tree, this insert function handles first insertion (inserting
 * root/ creation of tree) and all insertions 
 * @param root The Address of pointer of particular nodes 
 * @param key Identifier of particular data
 * @param data Information about a person/ company (yelp case)
 */
void
insertTree(tree_t **root, name_t key, data_t data) {

	/* Iterate to find position to insert, note the use of iteration to prevent
	 * stack overflow 
	 */
	while (1 == 1) {
		// Process insertion after finding appropriate position
		if (*root == NULL) {
			// Creating new nodes for the tree to insert
			tree_t *new = (tree_t *) malloc(sizeof(tree_t));
			assert(new != NULL);

			// Creating dynamic space for key and data for every nodes
			new -> key = (char *) malloc(strlen(key) + NULL_BYTE_LENGTH);
			assert(new -> key != NULL);

			new -> data = (char *) malloc(strlen(data) + NULL_BYTE_LENGTH);
			assert(new -> data != NULL);

			// Inserting information to the new nodes
			strcpy(new -> key, key);
			strcpy(new -> data, data);
			new -> left = new -> right = NULL;

			// Assigning the previously NULL address to new
			*root = new;
			return;
		}
			
		// Key comparison with <= on left and > on right
		if (strcmp(key, (*root) -> key) <= 0) {
			root = &(*root) -> left;
		}
		else {
			root = &(*root) -> right;
		}
	}
}

/** Search binary search tree (modified version as neccessary to count 
 * operation and search until leaf)
 * @param root Nodes of the tree starting from the first (root)
 * @param key Search key
 * @param fileOut Pointer to output file as neccessary to traverse until
 * leaf, thus printing every time data has been found
 */
void
searchTree(tree_t *root, name_t key, FILE *fileOut) {
	int isFound = FALSE;
	int countComparison = 0;

	// Iterative solution to prevent stack overflow
	while (1 == 1) {
		// Base case when there is no element left to search
		if (root == NULL) {
			// Print to stdout the number of comparison for given key
			printf("%s --> %d\n", key, countComparison);
			
			// Print NOTFOUND if the key is nowhere
			if (isFound == FALSE) {
				fprintf(fileOut, "%s --> %s\n\n", key, NOT_FOUND);
			}
			return; 
		}

		/* Key comparison process, search until leafs as there are key
		 * duplication
		 */
		if (strcmp(key, root -> key) == 0) {
			isFound = TRUE; // indicate that already found at least 1 result
			countComparison ++; 
			
			// Print key and data found
			fprintf(fileOut, "%s --> %s\n\n", key, root -> data);

			// Continue search until leaf
			root = root -> left;
		}
		else if (strcmp(key, root -> key) < 0) {
			countComparison ++;
			root = root -> left;
		}
		else {
			countComparison ++;
			root = root -> right;
		}
	}
}

/** Free everything in the dictionary
 * @param tree Address to structure that holds the root
 */
void
freedict(dict_t *tree) {
	assert(tree != NULL);
	// Free every nodes that tree occupied
	recursiveFreeTree(tree -> root);

	// Free the structure of tree itself
	free(tree);
}

/** Free nodes in tree 
 * @param root The first element in the tree
 */
void
recursiveFreeTree(tree_t *root) {
	// Base case
	if (root == NULL) {
		return;
	}

	// Using post order traversal recursively freeing tree
	recursiveFreeTree(root -> left);
	recursiveFreeTree(root -> right);

	// Free dynamically allocated space for key and data
	free(root -> key);
	free(root -> data);
	free(root);
}