/* HEADER FILES FOR STAGE 2 DICTIONARY (BST)
 * Author: Maleakhi Agung Wijaya
 * Student Number: 784091
 * Date: 8/09/2016
 * Version: 1.0
 */

#ifndef DICTIONARY2_H
#define DICTIONARY2_H

#include "list.h"

/***************************CONSTANT***********************************/

#define MAX_KEY 65     // Maximum character for given key (including NULL)

/***************************DECLARATION*******************************/

typedef struct tree tree_t;

typedef char name_t[MAX_KEY];    // Store the string for key

/** Node for the tree */
struct tree {
	char *key;
	list_t *head; // pointer to linked list head
	tree_t *left;
	tree_t *right;
};

/** Structure of the dictionary (holds the root of the tree) */
typedef struct {
	tree_t *root;
} dict_t;


/** Tree function declaration */
dict_t *makedict();
void insertTree(tree_t **root, name_t key, data_t data);
tree_t *searchTree(tree_t *root, name_t key);
void freedict(dict_t *tree);
void recursiveFreeTree(tree_t *root);

#endif