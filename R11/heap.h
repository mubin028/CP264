/*
 * ---------------------------------
 * Student Name:Mubin Qureshi
 * Student ID:180181900
 * Student Email:qure1900@mylaurier.ca
 * ---------------------------------
 */

#ifndef HEAP_H_
#define HEAP_H_
# include "data.h"
#define True 1
#define False 0
#define Left(i) (2*i+1)
#define Right(i) (2*i+2)
#define Parent(i) ((i-1)/2)

typedef struct{
	Data* array; //heap data (array implementation)
	int size;//number of items in heap
	int capacity;//maximum number of items


} Heap;

Heap* create_heap(int capacity);
void destroy_heap(Heap **h);
int is_empty_heap(Heap *h);
void insert_heap(Heap *h, Data *d);
Data* peek_heap(Heap *h);
void remove_heap (Heap *h);
int contains_heap(Heap *h, Data *d);
void print_heap(Heap *h);
void heap_sort(Data *array, const int size);

#endif /* HEAP_H_ */
