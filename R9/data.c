/*
 * ---------------------------------
 * Student Name:Mubin Qureshi
 * Student ID:180181900
 * Student Email:qure1900@mylaurier.ca
 * ---------------------------------
 */
#include"data.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void print_data(Data* d){
	assert(d);
	printf("%d",(int)d);
	return;


}
void print_data_array(Data* array,const int size){
	assert(array);
	assert(size >=1);
	int i;
	printf("[");
	for (i = 0; i < size;i++){
		printf("%d",array[i]);
		if(i!= size-1)
			printf(",");

	}
	printf("]\n");
	return;
}
void destroy_data(Data **d){
	assert(d && *d);
	free(*d);
	*d=NULL;

	return;
}

Data* copy_data(Data *d1) {
	assert(d1);
	int *d2 = (int*) malloc(sizeof(int));
	*d2 = *d1;
	return d2;
}

void swap_data(Data *d1, Data *d2) {
	assert(d1 && d2);
	Data temp = *d1;
	*d1 = *d2;
	*d2 = temp;

	return;
}
//0 : equal
//1: d1 > d2
//2: d1 < d2
int compare_data(Data* d1, Data* d2){
	assert(d1 && d2);
	if (*d1 > *d2)
		return 1;
	if (*d1 < *d2)
		return 2;
	return 0;

}
