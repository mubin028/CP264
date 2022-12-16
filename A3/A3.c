/**
 * -------------------------
 * Student Name:Mubin Qureshi
 * Student ID:180181900
 * Student email:qure1900@mylaurier.ca
 * -------------------------
 */

# include <stdio.h>
# include "A3.h"

/**
 * -------------------------------------------------------------------
 * Parameters:
 * 	  array: a pointer to an array of integers (int*)
 * 	  size: size of an array (const int)
 * 	  value: some value to search for in the array (int)
 * returns:
 * 	  ptr: pointer to some element in the array (int*)
 * Description:
 *    Searches for the "value" in the array and identifies the first occurrence
 *    There are four scenarios:
 *    	1- if value is found at the last element --> ptr should point to last element
 *    	2- if value is found at any other location --> ptr should point to the next element
 *    	3- if value is not found --> ptr should point to the first element
 *      4- if the array pointer is NULL or the size is invalid --> ptr point to NULL
 * -------------------------------------------------------------------
 */
int* find_next(int *array, const int size, int value) {

	int *ptr;
	if (size < 1) {
		ptr = NULL;
		return ptr;
	}

	if (array == NULL) {
		ptr = NULL;
		return ptr;
	}
	ptr = array;
	for (int i = 0; i < size; i++) {
		if (value == array[i]) {

			if (i == (size - 1)) {
				return ptr;

			} else {
				ptr++;
				return ptr;

			}

		}
		ptr++;
	}
	ptr = array;
	return ptr;
}

/**
 * -------------------------------------------------------------------
 * Parameters:
 * 	  array: a pointer to an array of unknown data type (void*)
 * 	  size: size of the array (const int)
 * 	  indx: array index of the element to increment (int)
 * 	  char: array mode which controls the data type of the array. Defined types:
 * 	  		'i': integer
 * 	  		'l': long
 * 	  		'f': float
 * 	  		'd': double
 * returns: no returns
 * Description:
 *    Increments the value of the element at array[indx]
 *    Prints the value before increment
 *    The function should handle arrays of types: integer, long, float and double
 *    Before incrementing the function should print the current value at array[indx]
 *    There are four error scenarios:
 *    	1- array pointer is NULL
 *    	2- invalid array size
 *    	3- invalid value for indx
 *      4- invalid mode
 *    Whenever an error is detected, an error msg is printed
 * -------------------------------------------------------------------
 */
void increment_element(void *array, const int size, int indx, char mode) {

	if (array == NULL) {
		printf("Error(increment_element): NULL array\n");
		return;
	}

	if (size < 1) {
		printf("Error(increment_element): invalid size\n");
		return;
	}
	if (indx < 0 || indx > size - 1) {
		printf("Error(increment_element): invalid indx\n");
		return;
	}

	int i = 0;

	if (mode == 'i') {

		int *ptr;
		ptr = array;
		while (i < indx) {
			i++;
			ptr++;
		}
		printf("Value before increment = %d\n", *ptr);
		(*ptr)++;

	} else if (mode == 'l') {

		long *ptr;
		ptr = array;
		while (i < indx) {
			i++;
			ptr++;
		}
		printf("Value before increment = %lu\n", *ptr);
		(*ptr)++;

	} else if (mode == 'f') {

		float *ptr;
		ptr = array;
		while (i < indx) {
			i++;
			ptr++;
		}

		printf("Value before increment = %.2lf\n", *ptr);
		(*ptr)++;

	} else if (mode == 'd') {

		double *ptr;
		ptr = array;
		while (i < indx) {
			i++;
			ptr++;
		}

		printf("Value before increment = %.2lf\n", *ptr);
		(*ptr)++;

	} else {
		printf("Error(increment_element): invalid mode\n");
		return;
	}

	return;
}

/**
 * -------------------------------------------------------------------
 * Parameters:
 * 	  array: a pointer to an array of integers (int*)
 * 	  size: size of an array (const int)
 * 	  ptr:  double pointer to store location of average element
 * returns:
 * 	  no returns
 * Description:
 *    1- Finds the average of the values within the array and print it to the console.
 *    	Use 1 decimal point.
 *    2- The average is "ceiled", i.e. rounded to the upper integer value.
 *    3- Search the array for an element that is equal to the average,
 *      	and sets avg_pointer to that element
 *    	If there are multiple values equal to the average, a pointer to the
 *      	first element that equals to average is used
 *    	If no value is equal to the average, a pointer to the value
 *      	closest to the average is returned.
 *    4- prints an error message if
 *    		array pointer is NULL, invalid size or avg_ptr is NULL
 * -------------------------------------------------------------------
 */
void find_avg_element(int *array, const int size, int **avg_ptr) {

	if (array == NULL) {
		printf("Error(find_avg_element): NULL pointer\n");
		return;
	}

	if (size < 1) {
		printf("Error(find_avg_element): invalid array size\n");
		return;
	}
	if (avg_ptr == NULL) {
		printf("Error(find_avg_element): invalid pointer\n");
		return;
	}

	double sum = 0;
	int avg;
	int *ptr;
	ptr = array;

	for (int i = 0; i < size; i++) {
		sum += *(ptr);
		ptr++;
	}
	sum = (sum / size);
	avg = ceil(sum);
	printf("Average = %.1lf\n", sum);

	ptr = array;
	*avg_ptr = array;

	for (int j = 0; j < size; j++) {
		if (*ptr == avg) {
			*avg_ptr = ptr;
			return;
		} else if (abs(**avg_ptr - avg) > abs(*ptr - avg)) {
			*avg_ptr = ptr;
		}
		ptr++;
	}

//your solution here
	return;
}

/**
 * -------------------------------------------------------------------
 * Parameters:
 * 	  array: a pointer to an array of floats (float*)
 * 	  ptrs: an array of float pointers (float* [])
 * returns:
 * 	  No returns
 * Description:
 * 	  An array of float items is passed. The size of the array is unknown
 *    The pointer array stores some pointers to elements in the array
 *	  The size of the pointer array is unknown, but the maximum possible size is MAX
 *	  When iterating through the pointer array, if you encounter a NULL, then this is the end
 *    Access the pointer array to print the following:
 *    1-	The value of the element it points to
 *    2-	The index of that element in the array
 *    3-	The value of the previous element
 *    			If the pointer points to the first element, previous value is 0
 *    Assume that both array and ptrs are not NULL
 *    All printing follow a format space of 13 digits, and 2 decimal places
 * -------------------------------------------------------------------
 */
void print_ptr_array(double *array, double *ptrs[]) {

	int i = 0;
	double value;
	double *temp;
	printf("Value        Index        Previous     \n");
	while (*ptrs != NULL) {
		temp = array;
		while (**ptrs != *temp) {
			temp++;
			i++;

		}
		if (**ptrs == *temp) {
			value = *temp--;
			if (i == 0) {
				printf("%.2lf        %d            0.00        \n", value, i);

			} else
				printf("%.2lf        %d            %.2lf        \n", value, i,
						*temp);

			i = 0;
		}
		ptrs++;
	}

	return;
}

/**
 * -------------------------------------------------------------------
 * Parameters:
 * 	  array: a pointer to an array of shorts (short*)
 * 	  ptr: a pointer to an item in the array (short*)
 * returns:
 * 	  No returns
 * Description:
 * 	  An array of shorts is given, and you do not know its size
 * 	  However, you know the following about the array:
 * 	  	1- the minimum length is 3 items
 * 	  	2- The first element has a value of 1
 * 	  	3- The last element has a value of 1
 *    You are given some pointer to an element in the array.
 *    The pointer points to some item other than the first and last items
 *	  Your job is to print all the items in the array in the following format:
 *	  	[items before pointer]-->[items after pointer]
 *	  The printing ignores the first and last items which have the value of 1
 *    The function should print an error message if the array or the pointer is NULL
 * -------------------------------------------------------------------
 */
void special_array_print(short *array, short *ptr) {
	short *temp, *next;
	temp = array;

	next = array;
	next++;

	if (array == NULL) {
		printf("Error(special_array_print): NULL pointer\n");
		return;
	}

	if (ptr == NULL) {
		printf("Error(special_array_print): invalid pointer\n");
		return;
	}

	printf("[");
	while (*temp != *ptr) {
		if (*temp != 1) {
			if (*next == *ptr) {
				printf("%hu", *temp);

			} else

				printf("%hu, ", *temp);
		}

		temp++;
		next++;
	}
	printf("]");
	printf("-->");
	printf("[");
	while (*temp != 1) {

		if (*temp != *ptr) {
			if (*next == 1) {
				printf("%hu", *temp);
			} else
				printf("%hu, ", *temp);

		}
		temp++;
		next++;
	}
	printf("]\n");

	return;
}
