#pragma once

#include <stdio.h>
#include <stdlib.h>

typedef struct WorkerData {
	int id;
	int dataCounter = 0;
} WorkerData;

typedef struct Worker {
	WorkerData data;
	struct Worker* next;
} Worker;

bool setLast(Worker** head, Worker** tail, WorkerData data) {
	Worker* temp = (Worker*)malloc(sizeof(Worker));
	if (temp == NULL)
		return false;

	temp->data = data;
	temp->next = NULL;
	if (*tail == NULL) {
		*head = *tail = temp;
		return true;
	}
	(*tail)->next = temp;
	(*tail) = (*tail)->next;
	return true;
}

bool setFirst(Worker** head, Worker** tail, WorkerData data) {
	Worker* temp = (Worker*)malloc(sizeof(Worker));
	if (temp == NULL)
		return false;

	temp->data = data;
	temp->next = NULL;
	if (*head == NULL) {
		*head = *tail = temp;
		return true;
	}
	temp->next = *head;
	*head = temp;
	return true;
}

bool clearList(Worker** head, Worker** tail = NULL) {
	if (*head != NULL) {
		clearList(&((*head)->next));
		free(*head);
		*head = *tail = NULL;
	}
}

