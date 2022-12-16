/*
 * ---------------------------------
 * Student Name:Mubin Qureshi
 * Student ID:180181900
 * Student Email:qure1900@mylaurier.ca
 * ---------------------------------
 */

#ifndef CQUEUE_H_
#define CQUEUE_H_



#include "data.h"
#define True 1
#define False 0

typedef struct{
Data *array; //array containing data items
int front; //index of first item in queue
int rear; //index of last item in queue
int capacity; //maximum queue length
int size; //numbers of elements in queue

}cQueue;


cQueue* create_queue(int capacity);
int is_empty_queue(cQueue *q);
int len_queue(cQueue *q);
int is_full_queue(cQueue *q);
int insert_queue(cQueue *q,Data* d);
Data* peek_queue(cQueue *q);
Data* remove_queue(cQueue *q);
void destroy_queue(cQueue *q);
void print_queue(cQueue *q);
int get_capacity_queue(cQueue *q);

#endif /* CQUEUE_H_ */
