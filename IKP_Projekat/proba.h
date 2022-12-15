#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Structure that represents data that is transferred to Workers
typedef struct Queue {
	char data[50];
	struct Queue* next;
} Queue;


//Pops last item of queue
char* dequeue(Queue** head) {
	if (*head == NULL)
		return NULL;
	char ret[50];

	strcpy(ret, (*head)->data);
	*head = (*head)->next;
	return ret;
}

//Pushes to beginning of queue
bool enqueue(Queue** head, Queue** tail, char* data) {
	Queue* temp = (Queue*)malloc(sizeof(Queue));
	if (temp == NULL)
		return false;

	strcpy(temp->data, data);
	temp->next = NULL;

	(*tail)->next = temp;
	if (*head == NULL)
		*head = *tail;
	*tail = (*tail)->next;
	return true;
}

bool isQueueEmpty(Queue* head) {
	return head == NULL;
}

void clearQueue(Queue** head, Queue** tail = NULL) {
	if (*head != NULL) {
		clearQueue(&((*head)->next));
		free(*head);
		*head = *tail = NULL;
	}
}
