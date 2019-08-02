/* HEADER FILES FOR STAGE 2 DICTIONARY (LIST)
 * Author: Maleakhi Agung Wijaya
 * Student Number: 784091
 * Date: 8/09/2016
 * Version: 1.0
 */

#ifndef LIST_H
#define LIST_H

/**************************CONSTANT***********************************/

#define MAX_DATA 1466  // Maximum character for data (including NULL)
#define NULL_BYTE_LENGTH 1

/***************************DECLARATION********************************/

typedef struct list list_t;

typedef char data_t[MAX_DATA];   // Store the data for given key

/* Node for linked list */
struct list {
	char *data;
	list_t *next;
};


/** Linked list function declaration */
list_t *createEmptyList();
void insertList(list_t **head, data_t data);
void freeList(list_t *head);

#endif