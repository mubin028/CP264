/*
 * ---------------------------------
 * Student Name:Mubin Qureshi
 * Student ID:180181900
 * Student Email:qure1900@mylaurier.ca
 * ---------------------------------
 */

#include "cqueue.h"

# include <stdio.h>
# include <stdlib.h>
# include <assert.h>

/**
 * Parameters: 	queue length (int)
 * Returns: 	A pointer to a Queue
 * Description:	Creates a new empty queue
 * 				Initializes size to 0
 * 				front and rear are set to -1
 * 				if given length is <1 --> through an error and set length to 10
 */
cQueue* create_cqueue(int capacity) {
	cQueue *q = (cQueue*) malloc(sizeof(cQueue));
	if (capacity < 1) {
		printf("Error(create_cqueue): invalid cqueue capacity, set to 10\n");
		capacity = 10;
	}
	q->capacity = capacity;
	q->array = (Data*) malloc(sizeof(Data) * capacity);
	q->front = -1;
	q->rear = -1;
	q->size = 0;
	return q;
}

/**
 * Parameters: 	A pointer to Queue (Queue*)
 * Returns: 	number of items in queue (int)
 * Description:	return number of items in queue
 */
int len_cqueue(cQueue *q) {
	assert(q!=NULL);
	return q->size;
}

/**
 * Parameters: 	A pointer to Queue (Queue*)
 * Returns: 	number of items in queue (int)
 * Description:	return length of queue (maximum number of items)
 */
int get_capacity_cqueue(cQueue *q) {
	assert(q!=NULL);
	return q->capacity;
}

/**
 * Parameters: 	A pointer to Queue (Queue*)
 * Returns: 	True(1)/False(0)
 * Description:	Check if queue is empty
 * 				queue is empty if size = 0
 */
int is_empty_cqueue(cQueue *q) {
	assert(q!=NULL);
	return (len_cqueue(q) == 0);
}

/**
 * Parameters: 	A pointer to Queue (Queue*)
 * Returns: 	True(1)/False(0)
 * Description:	Check if queue is full
 * 				queue is full if size == length
 */
int is_full_cqueue(cQueue *q) {
	assert(q!=NULL);
	return (len_cqueue(q) == q->capacity);
}

/**
 * Parameters: 	A pointer to Queue (Queue*)
 * Returns: 	None
 * Description:	prints contents of a queue
 * 				prints Queue info (length, size, front, rear)
 * 				then print all elements each 5 elements in a separate line
 */
void print_cqueue(cQueue *q) {

	assert(q!=NULL);
	int i;
	printf("Capacity = %d, Size = %d, front = %d, rear = %d\n", q->capacity,
			len_cqueue(q), q->front, q->rear);

	if (is_empty_cqueue(q)) {
		printf("<empty_cqueue>");
	} else {

		if (q->front <= q->rear) {
			int counter = 0;
			for (i = q->front; i <= q->rear; i++) {
				print_data(&q->array[i]);
				if ((counter + 1) % 5 == 0 && counter != len_cqueue(q) - 1) {
					printf("\n");
				} else {
					printf("\t");
				}
				counter++;
			}
			//printf("\n");

		} else {

			int counter = 0;
			for (i = q->front; i <= q->capacity; i++) {
				print_data(&q->array[i]);
				if ((counter + 1) % 5 == 0 && counter != len_cqueue(q) - 1) {
					printf("\n");
				} else {
					printf("\t");
				}
				counter++;
			}

			for (i = 0; i <= q->rear; i++) {
				print_data(&q->array[i]);
				if ((counter + 1) % 5 == 0 && counter != len_cqueue(q) - 1) {
					printf("\n");
				} else {
					printf("\t");
				}
				counter++;
			}
			//printf("\n");

		}

	}
	printf("\n");
	return;
}

/**
 * Parameters: 	A pointer to a Queue (Queue*)
 * 				A pointer to a data item (Data*)
 * Returns: 	True/False
 * Description:	Insert a Data item into the queue
 * 				if queue is full - print error and return False
 * 				The en_queue results in update to the following:
 * 					- the size (incremented by 1)
 * 					- the array (one more item added)
 * 					- the rear (incremented by 1)
 * 				When there are empty slots but the rear pointer is at the end
 * 				the function invokes adjust_queue to shift the queue before adding
 * 				the data item.
 */
int insert_cqueue(cQueue *q, Data *d) {
	assert(q!=NULL && d!=NULL);
	if (is_full_cqueue(q)) {
		printf("Error(insert_cqueue): cqueue is full\n");
		return False;
	}
	if (is_empty_cqueue(q))
		q->front++;
	q->rear = (q->rear + 1) % q->capacity;
	q->array[q->rear] = *copy_data(d);
	q->size++;
	return True;
}

/**
 * Parameters: 	A pointer to a Queue (Queue*)
 * Returns: 	item on front of queue (int)
 * Description:	returns first item in the queue
 * 				if queue is empty: print error message and return a NULL pointer
 */
Data* peek_cqueue(cQueue *q) {
	assert(q!=NULL);
	if (is_empty_cqueue(q)) {
		printf("Error(peek_cqueue): cQueue is empty\n");
		return NULL;
	}
	return copy_data(&(q->array[q->front]));
}

/**
 * Parameters: 	A pointer to a Queue (Queue*)
 * Returns: 	first item in queue (int)
 * Description:	returns the first item in queue and remove it from queue
 * 				If queue is empty: print error message and return -1
 * 				The de_queue results in update to the following:
 * 					- the size (decremented by 1)
 * 					- the array (one item removed)
 * 					- the front (incremented by 1)
 * 				When the last element is removed, front and rear are reset to -1
 */
Data* remove_cqueue(cQueue *q) {

	assert(q!=NULL);
	Data *d = NULL;
	if (is_empty_cqueue(q)) {
		printf("Error(remove_cqueue): cQueue is empty\n");
		return d;
	}
	d = copy_data(&q->array[q->front]);
	Data *temp = &q->array[q->front];
	destroy_data(&temp);

	if (q->front < q->rear) {
		q->front++;
	} else if (q->front > q->rear) {
		if (q->front < q->capacity-1){
			q->front++;
		}else{
			q->front = 0;
		}
	}

	q->size--;

	if (len_cqueue(q) == 0) {
		q->front = -1;
		q->rear = -1;
		q->size=0;

	}
	return d;
}

/**
 * Parameters: 	A double pointer to a Queue (Queue**)
 * Returns: 	None
 * Description:	Destroys the Queue by doing the following:
 * 					- destroy all queue data, and free the array pointer
 * 					- sets size, length, front, rear and length to 0
 * 					- free the queue pointer
 */
void destroy_cqueue(cQueue **q) {
	assert(q!= NULL);
	while (!is_empty_cqueue(*q)) {
		Data *d = remove_cqueue(*q);
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

