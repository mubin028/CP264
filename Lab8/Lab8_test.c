/*
 * ---------------------------------
 * Student Name:Mubin Qureshi
 * Student ID:180181900
 * Student Email:qure1900@mylaurier.ca
 * ---------------------------------
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "Lab8.h"

void test_bubble_sort();
void test_insertion_sort();
void test_selection_sort();
void test_quick_sort();
void test_merge_sort();
void test_search();

Data* get_array(int);
int sizes[3] = { 1, 5, 10 };

int main() {
	setbuf(stdout, NULL);
	test_search();
	test_bubble_sort();
	test_insertion_sort();
	test_selection_sort();
	test_quick_sort();
	//test_merge_sort();
	return 0;
}

void test_search() {
	printf("------------------------------\n");
	printf("Start: Testing Linear and Binary Search:\n\n");

	Data *array = NULL;
	Data values[6] = { *copy_data(create_process(1000010000, 2, 5)),
			*copy_data(create_process(1000010002, 5, 7)),
			*copy_data(create_process(1000010007, 7, 33)),
			*copy_data(create_process(1000010004, 9, 17)),
			*copy_data(create_process(1000010003, 8, 10)),
			*copy_data(create_process(1000010040, 11, 49)) };

	for (int i = 0; i < 3; i++) {
		array = get_array(i);
		printf("Searching the array: ");
		print_data_array(array, sizes[i]);
		linear_search(array, sizes[i], values[0]);
		for (int j = 0; j < 6; j++) {
			printf("linear_search(%d) = %4s\n", values[j],
				linear_search(array, sizes[i], values[j]));
			printf("linear_search_r(%d) = %2s\n", values[j],
					linear_search_r(array, sizes[i], values[j]));
			printf("binary_search(%d) = %4d\n", values[j],
					binary_search(array, sizes[i], values[j]));
			printf("binary_search_r(%d) = %2d\n", values[j],
					binary_search_r(array, sizes[i], values[j]));
			printf("\n");
		}
		free(array);
		array = NULL;
	}
	printf("End: Testing Linear and Binary Search\n");
	printf("------------------------------\n\n");
	return;
}

void test_bubble_sort() {
	printf("------------------------------\n");
	printf("Start: Testing Bubble Sort:\n\n");

	Data *array = NULL;
	for (int i = 0; i < 3; i++) {
		array = get_array(i + 3);
		printf("Sorting array %d:\n", i);
		bubble_sort(array, sizes[i]);
		print_data_array(array, sizes[i]);
		free(array);
		array = NULL;
		printf("\n");
	}
	printf("End: Testing Bubble Sort\n");
	printf("------------------------------\n\n");
	return;
}

void test_selection_sort() {
	printf("------------------------------\n");
	printf("Start: Testing Selection Sort:\n\n");

	Data *array = NULL;
	for (int i = 0; i < 3; i++) {
		array = get_array(i + 3);
		printf("Sorting array %d:\n", i);
		selection_sort(array, sizes[i]);
		print_data_array(array, sizes[i]);
		free(array);
		array = NULL;
		printf("\n");
	}
	printf("End: Testing Selection Sort\n");
	printf("------------------------------\n\n");
	return;
}

void test_insertion_sort() {
	printf("------------------------------\n");
	printf("Start: Testing Insertion Sort:\n\n");

	Data *array = NULL;
	for (int i = 0; i < 3; i++) {
		array = get_array(i + 3);
		printf("Sorting array %d:\n", i);
		insertion_sort(array, sizes[i]);
		print_data_array(array, sizes[i]);
		free(array);
		array = NULL;
		printf("\n");
	}
	printf("End: Testing Insertion Sort\n");
	printf("------------------------------\n\n");
	return;
}

void test_quick_sort() {
	printf("------------------------------\n");
	printf("Start: Testing Quick Sort:\n\n");

	Data *array = NULL;
	for (int i = 0; i < 3; i++) {
		array = get_array(i + 3);
		printf("Sorting array %d:\n", i);
		quick_sort(array, sizes[i]);
		print_data_array(array, sizes[i]);
		free(array);
		array = NULL;
		printf("\n");
	}
	printf("End: Testing Quick Sort\n");
	printf("------------------------------\n\n");
	return;
}

void test_merge_sort() {
	printf("------------------------------\n");
	printf("Start: Testing Merge Sort:\n\n");

	Data *array = NULL;
	for (int i = 0; i < 3; i++) {
		array = get_array(i + 3);
		printf("Sorting array %d:\n", i);
		merge_sort(array, sizes[i]);
		print_data_array(array, sizes[i]);
		free(array);
		array = NULL;
		printf("\n");
	}
	printf("End: Testing Merge Sort\n");
	printf("------------------------------\n\n");
	return;
}
Data* get_array(int num) {
	Data *array = NULL;



	switch (num) {
	case 0:
	case 3:
		array = (Data*) malloc(sizeof(Data));
		*array = *copy_data(create_process(1000010002, 2, 5));

		break;

	case 1:
		array=  (Data*) malloc(sizeof(Data) * 5);
		Data*y = create_process(1000010000,2,5);
		array[0] = *copy_data(y);
		array[1] = *copy_data(create_process(1000010001,5,6));
		array[2] = *copy_data(create_process(1000010002,5,7));
		array[3] =*copy_data( create_process(1000010006,7,26));
		array[4] = *copy_data(create_process(1000010007,7,33));
		break;
	case 2:
		array =  (Data*) malloc(sizeof(Data)  * 10);
		array[0] = *copy_data(create_process(1000010000,2,5));
		array[1] =*copy_data( create_process(1000010001,5,6));
		array[2] =*copy_data( create_process(1000010002,5,7));
		array[3] = *copy_data(create_process(1000010006,7,26));
		array[4] =*copy_data( create_process(1000010007,7,33));

		array[5]= *copy_data(create_process(1000010003,8,10));
		array[6] =*copy_data(create_process(1000010015,8,64));
		array[7] =*copy_data( create_process(1000010004,9,17));
		array[8] =*copy_data( create_process(1000010005,10,18));
		array[9] =*copy_data( create_process(1000010001,10,48));
		break;
	case 4:
		array =  (Data*) malloc(sizeof(Data)  * 5);
		array[1] =*copy_data( create_process(1000010000,2,5));
		array[4] =*copy_data( create_process(1000010001,5,6));
		array[0] =*copy_data( create_process(1000010002,5,7));
		array[2] =*copy_data( create_process(1000010006,7,26));
		array[3] =*copy_data( create_process(1000010007,7,33));
		break;
	case 5:
		array =  (Data*) malloc(sizeof(Data)  * 10);

		array[1] = *copy_data(create_process(1000010000,2,5));
		array[4] =*copy_data( create_process(1000010001,5,6));
		array[0] =*copy_data( create_process(1000010002,5,7));
		array[2] = *copy_data(create_process(1000010006,7,26));
		array[3] =*copy_data( create_process(1000010007,7,33));

		array[9] =*copy_data( create_process(1000010003, 8, 10));
		array[8] =*copy_data( create_process(1000010015, 8, 64));
		array[6] =*copy_data( create_process(1000010004, 9, 17));
		array[5] =*copy_data( create_process(1000010005, 10, 18));
		array[7] =*copy_data( create_process(1000010001, 10, 48));
		break;
	}
	return array;
}

