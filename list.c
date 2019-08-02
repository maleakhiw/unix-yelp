#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "list.h"

/*******************************LIST*********************************/

/** Create list (use for better abstraction during initialization)
 * return NULL when creating empty list there is still no head, thus NULL
 */
list_t
*createEmptyList() {
	return NULL;
}

/** Insertion of linked list at foot (to preserve ordering)
 * @param head Address to pointer of every nodes
 * @param data Data about instance (string)
 */
void
insertList(list_t **head, data_t data) {
	// Preventing stack overflow (process iteratively)
	while (1 == 1) {
		// Base case when found place to insert
		if (*head == NULL) {
			list_t *new;
			new = (list_t *) malloc(sizeof(list_t));
			assert(new != NULL);

			// Dynamically allocated space for data
			new -> data = (char *) malloc(strlen(data) + NULL_BYTE_LENGTH);
			assert(new -> data != NULL);

			// Insert data to the new nodes
			strcpy(new -> data, data);
			new -> next = NULL;
			
			// Add new to appropriate position
			*head = new;
			return;
		}

		else {
			head = &(*head) -> next;
		}
	}
}

/** Free list 
 * @param head Address to the head of linked list 
 */
void 
freeList(list_t *head) {
	list_t *oldHead;

	while (head) {
		oldHead = head;
		head = head -> next;
		free(oldHead -> data);
		free(oldHead);
	}
}