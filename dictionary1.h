/* HEADER FILES FOR STAGE 1 DICTIONARY
 * Author: Maleakhi Agung Wijaya
 * Student Number: 784091
 * Date: 8/09/2016
 * Version: 1.0
 */

#ifndef DICTIONARY1_H
#define DICTIONARY1_H

#include <stdio.h>

/***************************CONSTANT***********************************/

#define NOT_FOUND "NOTFOUND" // Return value if search not found

#define MAX_KEY 65     // Maximum character for given key (including NULL)
#define MAX_DATA 1466  // Maximum character for data (including NULL)
#define NULL_BYTE_LENGTH 1

#define TRUE 1
#define FALSE 0

/***************************DECLARATION*******************************/

typedef struct tree tree_t;

typedef char name_t[MAX_KEY];    // Store the string for key
typedef char data_t[MAX_DATA];   // Store the data for given key


/** Node for the tree */
struct tree {
	char *data; // Dynamically allocated space
	char *key;  // Dynamically allocated space
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
void searchTree(tree_t *root, name_t key, FILE *fileOut);
void freedict(dict_t *tree);
void recursiveFreeTree(tree_t *root);

#endif