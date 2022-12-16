/**
 * -------------------------
 * Student Name:
 * Student ID:
 * Student email:
 * -------------------------
 */

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <ctype.h>

# include "R5.h"

//-----------------------------------------------------
void print_array(int *array, const int size) {
	int i;
	printf("[");
	for (i = 0; i < size; i++) {
		printf("%d", array[i]);
		if (i != size - 1)
			printf(",");
	}
	printf("]\n");
	return;
}

int indx(int *array, const int size, int value) {
	int i, indx = -1;
	for (i = 0; i < size; i++)
		if (array[i] == value) {
			indx = i;
			break;
		}
	return indx;
}
//-----------------------------------------------------

//------------------ Task 1 ---------------------------
int* get_array1(int start, int end) {
	int n = (end - start + 1);
	int *array = (int*) malloc(n * sizeof(int));
	for (int i = 0; i < n; i++) {
		array[i] = start++;
	}
	return array;
}

long* get_array2(long start, long end) {
	int n = (end - start + 1);
	long *array = (long*) calloc(n,sizeof(long));
	for (int i = 0; i < n; i++) {
		array[i] = start++;
	}
	return array;
}

//------------------ Task 2 ---------------------------
void insert_item(int *array, const int size, int item, int pos) {

	if (!array){
		printf("Error(insert_item): invalid array\n");
	}
	if (pos >= size || pos < 0){
		printf("Error(insert_item): invalid position\n");

	}
	array = realloc(array,sizeof(int)*(size+1));

	for(int i = size;i>= pos;i--){
		array[i+1] = array[i];
	}
	array[pos] = item;

	return;
}

void remove_item(int *array, const int size, int value) {
	if (!array) {
		printf("Error(remove_item): invalid array\n");
	}
	int i, pos = indx(array, size, value);
	if (pos == -1) {
		printf("Error(remove_item): item not found\n");
	}
	for (i = pos; i < size; i++) {
		array[i] = array[i + 1];
	}
	array = (int*) realloc(array, sizeof(int) * (size - 1));
	return;
}

//------------------ Task 3 ---------------------------
void init_str() {
	char s1[MAX];
	strcpy(s1,"String1");
	printf("s1 = %s, sizeof(s1 = %d)\n",s1,sizeof(s1));

	char s2[8] = {'S','t','r','i','n','g','2','\0'};

	printf("s2 = %s, sizeof(s2 = %d)\n",s2,sizeof(s2));

	int size = strlen(s2);
	char* s3 =(char*)malloc((size+1));
	for (int i = 0; i < size+1;i++){
		s3[i] = s2[i];
	}
	s3[size-1] = '3';
	printf("s3 = %s, sizeof(s3 = %d)\n",s3,sizeof(s3));

	char* s4 = "String4";
	printf("s4 = %s, sizeof(s4 = %d)\n",s4,sizeof(s4));

	char s5[] = "String5";
	printf("s5 = %s, sizeof(s5 = %d)\n",s5,sizeof(s5));

	return;
}

//------------------ Task 4 ---------------------------
void reverse_str1(char *s) {
	if (!s||!*s)
		return;
	strrev(s);
	return;
}

void reverse_str2(char *s) {
	if (!s||!*s)
		return;

	char temp;
	int i = 0, size = 0;

	while(s[i] != '\0'){
		size++;
		i++;
	}
	//strlen(s);

	for (i = 0;i < size/2;i++){
		temp = *(s+i); //s[i]
		*(s+i) = *(s+size-i-1);//s[i] = s[size-i-1]
		*(s+size-i-1) = temp;
	}

	return;
}

char* reverse_str3(char *s) {
	if (!s || !*s)
		return s;
	int size = strlen(s);
	int i = size - 1, j = 0;
	char temp;

	while (i>j){
		temp = s[i];
		s[i--]=s[j];
		s[j++] = temp;
	}

	return s;
}

char* reverse_str4(char *s) {
	if(!s || !*s)
		return s;
	int size = strlen(s),i,j;
	char *s2 = (char*)malloc(size+1),temp;
	strcpy(s2,s);
	i = size - 1;
	j = 0;

	while (i > j){
		temp=s2[i];
		s2[i--] = s2[j];
		s2[j++] = temp;
	}
	return s2;
}

//------------------ Task 5 ---------------------------
void swap_str1(char *s1, char *s2) {
	int size1 = strlen(s1);
	char*temp = malloc(size1+1);
	strcpy(temp,s1);
	strcpy(s1,s2);
	strcpy(s2,temp);
	free(temp);
	return;
}

void swap_str2(char **s1, char **s2) {
	char* temp;
	temp = *s1;
	*s1 = *s2;
	*s2 = temp;
	return;
}

//------------------ Task 6 ---------------------------
int has_double(char *s) {
	char counter[26];
	int j, i = 0, index;
	for (j = 0; j < 26; j++) {
		counter[j] = 0;
	}
	while (s[i]) {
		if (isalpha(s[i])) {
			index = tolower(s[i]) - 'a'; // a - a = 0, b -a = 1;
			counter[index]++;
			if (counter[index] == 2)
				return True;

		}
		i++;
	}
	return False;
}

void plural_to_singular(char* word){
	if (!word){
		return;
	}
	int length=strlen(word);
	if (length < 4 || word[length - 1]!='s'){
		return;
	}
	if (word[length-2]=='e'&&word[length - 3]=='i'){
		word[length-3]= 'y';
		word[length-2]= '\0';
		word = (char*)realloc(word,(length-1)*sizeof(char));


	}else{
		word[length-1] = '\0';
		word = (char*)realloc(word,(length)*sizeof(char));

	}

	return;

}

