/*
 * ---------------------------------
 * Student Name:Mubin Qureshi
 * Student ID:180181900
 * Student Email:qure1900@mylaurier.ca
 * ---------------------------------
 */


#ifndef QUEUE_ARRAY_H_
#define QUEUE_ARRAY_H_


#include "data.h"
#define True 1
#define False 0

typedef struct{
Data *array; //array containing data items
int front; //index of first item in queue
int rear; //index of last item in queue
int capacity; //maximum queue length

}Queue;


Queue* create_queue(int capacity);
int is_empty_queue(Queue *q);
int len_queue(Queue *q);
int is_full_queue(Queue *q);
int insert_queue(Queue *q,Data* d);
Data* peek_queue(Queue *q);
Data* remove_queue(Queue *q);
void destroy_queue(Queue **q);
void print_queue(Queue *q);
int get_capacity_queue(Queue *q);


#endif /* QUEUE_ARRAY_H_ */
