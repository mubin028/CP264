/*
 * ---------------------------------
 * Student Name:Mubin Qureshi
 * Student ID:180181900
 * Student Email:qure1900@mylaurier.ca
 * ---------------------------------
 */

#include "cqueue.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

cQueue* create_cqueue(int capacity) {
	cQueue *q = (cQueue*) malloc(sizeof(cQueue));

	if (capacity < 1) {
		printf("Error(create_queue): invalid cqueue capacity, set to 10\n");
		capacity = 10;

	}
	q->capacity = capacity;
	q->array = (Data*) malloc(sizeof(Data) * capacity);
	q->front = -1;
	q->rear = -1;
	q->size = 0;

	return q;
}
int is_empty_cqueue(cQueue *q) {

	assert(q!=NULL);
	return (q->size == 0);
}
int len_cqueue(cQueue *q) {
	assert(q!=NULL);
	return q->size;

}
int is_full_cqueue(cQueue *q) {
	assert(q!=NULL);
	return (q->size == q->capacity);

}
int insert_cqueue(cQueue *q, Data *d) {
	assert(q!=NULL&&d!= NULL);
	if (is_full_cqueue(q)) {
		printf("Error(insert_cqueue): cqueue is full\n");
		return False;
	}
	if (is_empty_cqueue(q)) {
		q->front++;
	}
	q->rear = (q->rear + 1) % q->capacity;
	q->array[q->rear] = *copy_data(d);
	q->size++;
	return True;
}
Data* peek_cqueue(cQueue *q) {

	assert(q!=NULL);
	if (is_empty_cqueue(q)) {
		printf("Error(peek_cqueue): cQueue is empty\n");
		return NULL;
	}

	return copy_data(&q->array[q->front]);

}
Data* remove_cqueue(cQueue *q) {

}
void destroy_cqueue(cQueue **q) {

	assert(q!=NULL);
	Data *d = NULL;
	while (!is_empty_cqueue(*q)) {
		d = remove_cqueue(*q);
		destroy_data(&d);
	}
	free((*q)->array);
	(*q)->array = NULL;
	(*q)->capacity = 0;
	(*q)->front = 0;
	(*q)->rear = 0;
	(*q)->size = 0;
	free(*q);
	*q = NULL;
	return;

}
void print_cqueue(cQueue *q) {

}
int get_capacity_cqueue(cQueue *q) {

	assert(q!=NULL);
	return q->capacity;

}
