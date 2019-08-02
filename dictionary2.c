/* STAGE 2 DICTIONARY (BST & LINKED LIST)
 * Author: Maleakhi Agung Wijaya
 * Student Number: 784091
 * Date: 8/09/2016
 * Version: 1.0
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "dictionary2.h"

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

	// Iterative solution to prevent stack overflow
	while (1 == 1) {
		// Process insertion after finding appropriate position
		if (*root == NULL) {
			// Creating new nodes for the tree to insert
			tree_t *new = (tree_t *) malloc(sizeof(tree_t));
			assert(new != NULL);

			// Dynamically allocated memory for key
			new -> key = (char *) malloc(strlen(key) + NULL_BYTE_LENGTH);
			assert(new -> key != NULL);

			// Inserting information to the new nodes
			strcpy(new -> key, key);
			// First insertion into the linked list
			new -> head = createEmptyList();
			insertList(&new -> head, data);
			new -> left = new -> right = NULL;

			// Assigning the previously NULL address to new
			*root = new;
			return;
		}
			
		// Key comparison with < on left and > on right
		if (strcmp(key, (*root) -> key) < 0) {
			root = &(*root) -> left;
		}
		else if (strcmp(key, (*root) -> key) > 0) {
			root = &(*root) -> right;
		}
		else {
			// Insert data into linked list (if found equal key)
			insertList(&(*root) -> head, data);
			return;
		}
	}
}

/** Search binary search tree (also count comparison)
 * @param root Nodes of the tree starting from the first (root)
 * @param key Search key
 * @return tree_t* the root (address) which contain that particular key
 */
tree_t
*searchTree(tree_t *root, name_t key) {
	int countComparison = 0;
	// Iterative solution to prevent stack overflow
	while (1 == 1) {
		// Base case when there is no element left to search
		if (root == NULL) {
			// Print to stdout the number of comparison for given key
			printf("%s --> %d\n", key, countComparison);

			// No data has been found
			return NULL;
		}

		// Compare key, print result if found and continue search until leaf
		if (strcmp(key, root -> key) == 0) {
			countComparison ++;

			// Print to stdout the number of comparison for given key
			printf("%s --> %d\n", key, countComparison);

			// Return address of nodes which contain particular key
			return root;
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

/** Free nodes in tree and linked list inside it 
 * @param root The first element in the tree
 */
void
recursiveFreeTree(tree_t *root) {
	// Base case
	if (root == NULL) {
		return;
	}

	/* Using post order traversal recursively freeing tree and linked list 
	 * attached to tree
	 */
	recursiveFreeTree(root -> left);
	recursiveFreeTree(root -> right);

	// Free dynamically allocated space for list and key
	freeList(root -> head);
	free(root -> key);
	free(root);
}

