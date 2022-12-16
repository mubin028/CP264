	/*
 * ---------------------------------
 * Student Name:Mubin Qureshi
 * Student ID:180181900
 * Student Email:qure1900@mylaurier.ca
 * ---------------------------------
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "A6.h"
#include <string.h>
#include "stack_array.h"
#include "process.h"

void remove_largest(Process *process_array, const int size) {
	if (process_array == NULL) {
		printf("Error(remove_largest): given pointer is NULL\n");
		return;
	}
	if (size <= 0) {
		printf("Error(remove_largest): invalid array size\n");
		return;
	}
	Process* temp = copy_process(&process_array[0]);
	int process_time;

	int i = 0;
	int pos;
	for (i = 1; i < size; i++) {
		if ((&process_array[i])->time >= temp->time) {
			if ((&process_array[i])->time == temp->time) {

				if ((&process_array[i])->arrival <= temp->arrival) {

					if ((&process_array[i])->arrival == temp->arrival) {

						if ((&process_array[i])->PID < temp->PID) {
							temp = (&process_array[i]);
							pos = i;
						}

					} else {
						temp = (&process_array[i]);
						pos = i;
					}
				} else {
					temp = (&process_array[i]);
					pos = i;

				}
			} else {
				temp = (&process_array[i]);
				pos = i;
			}

		}
	}
	process_time = (&process_array[pos])->PID ;
if (size != 1){
	((&process_array[pos])->arrival = (&process_array[size-1])->arrival);
	((&process_array[pos])->PID = (&process_array[size-1])->PID);
	((&process_array[pos])->time = (&process_array[size-1])->time);
	process_array = realloc(process_array,sizeof(Process)*(size-1));
}else{
	((&process_array[0])->arrival = 0);
		((&process_array[0])->PID =0);
		((&process_array[0])->time =0);
}
	printf("Largest Process is : %d\n",process_time);
	return;
}

void reverse_stack(Stack *s) {
	int length = len_stack(s);

	if (is_empty_stack(s)) {
		return;
	}
	int i;
	Process** temp = (Process**) malloc(length * sizeof(Process));

	for (i = 0; i < length;i++){
		temp[i]= pop_stack(s);
	}

	for (i = 0; i < length;i++){
		push_stack(s,temp[i]);
		}
	free(temp);
	return;
}

Stack* slice_stack(Stack *s1, int index){

	if (is_empty_stack(s1)) {
		Stack *s2 = create_stack(0);
		printf("Error(slice_stack): cannot slice an empty stack\n");
		return s2;
	}
	if (index < 0) {
		Stack *s2 = create_stack(0);
		printf("Error(slice_stack): invalid index\n");
		return s2;
	}

	int i;
	int length = len_stack(s1);
	if (index > length)
		index = 0;

	Stack *s2 = create_stack(length);

	Process **temp = (Process**) malloc((length - index) * sizeof(Process));

	for (i = 0; i < (length - index); i++) {
		temp[i] = pop_stack(s1);

	}
	for (i = length - index-1; i >= 0; i--) {
		push_stack(s2, temp[i]);
	}

	return s2;
}

int resize_stack(Stack *s, int new_capacity) {
	if (new_capacity <= 0){
		printf("Error(resize_stack): invalid capacity size.\n");
		return False;
	}
	if (new_capacity == s->capacity){
		return False;
	}
	if (new_capacity > s->capacity){
		s->capacity = new_capacity;
		s->array= realloc(s->array,sizeof(Stack)*(new_capacity));
		return True;
	}
	int length = len_stack(s);
	if (new_capacity < s->capacity){
		if (new_capacity < length){
			for (int i = new_capacity; i < length; i++ ){
				pop_stack(s);
			}
			s->capacity = new_capacity;
			s->array= realloc(s->array,sizeof(Stack)*(new_capacity));
			return True;
		}else{
			s->capacity = new_capacity;
			s->array = realloc(s->array, sizeof(Stack) * (new_capacity));
			return True;
		}
			return True;
		}
	return 0;
}
Stack* concat_stack(Stack *s1, Stack *s2) {

	Stack *s3 = create_stack(s1->capacity+s2->capacity);
	int len1 = len_stack(s1);
	int len2 = len_stack(s2);



		Stack *temp_stack1 = copy_stack(s1);


		Stack *temp_stack2 = copy_stack(s2);



	Process** temp1 = (Process**) malloc(s1->capacity * sizeof(Process));
	Process** temp2 = (Process**) malloc(s2->capacity * sizeof(Process));
	int i;


	for (i = 0; i < len1;i++){
			temp1[i]= pop_stack(temp_stack1);
		}

	for (i = 0; i < len2;i++){
				temp2[i]= pop_stack(temp_stack2);
			}

	for (i = len1-1; i >=0;i--){
			push_stack(s3,temp1[i]);
			}
	for (i = len2-1; i >=0;i--){
				push_stack(s3,temp2[i]);
				}
	free(temp1);
	free(temp2);



	return s3;
}
