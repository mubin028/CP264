/*
 * ---------------------------------
 * Student Name:Mubin Qureshi
 * Student ID:180181900
 * Student Email:qure1900@mylaurier.ca
 * ---------------------------------
 */

# include<stdio.h>
# include <stdlib.h>
# include <string.h>
# include <ctype.h>
#include "A5.h"

//---------------------- Task 1 ---------------------------------
void get_file_stats(const char *filename, const char *filename2)  {
	FILE *in_file = NULL;
	in_file = fopen(filename, "r");

	if (in_file == NULL) {
		printf("Error(get_file_stats): Could not open file %s\n", filename);
		return;
	}
	char c = fgetc(in_file);
	int paragraphs = 0, lines = 0, words = 0, whiteSpaces = 0, characters = 0,
			upper = 0, lower = 0, notAlpha = 0;

	while (c != EOF) {
		if (c == '\n') {
			lines++;
		}
		if (c == ' ' || c =='\t' || c =='\n') {
			whiteSpaces++;
		}


		if (isalpha((c))) {
			if (isupper(c)) {
				upper++;
				characters++;

			} else{
				lower++;
				characters++;
			}
		}

		if (!isalpha(c)&& c != ' ' && c!='\n' && c != '\t'){
			notAlpha++;
			characters++;
		}

		c = fgetc(in_file);
	}
	fclose(in_file);
	FILE *out_file = NULL;
	out_file = fopen(filename2, "a");
	fprintf(out_file,"Analyzing file %s:\n",filename);
	fprintf(out_file,"#Paragraphs = %d \n",paragraphs);
	fprintf(out_file,"#lines = %d \n",lines);
	fprintf(out_file,"#words = 38 %d \n",words);
	fprintf(out_file,"#characters = %d \n",characters);
	fprintf(out_file,"#uppers = %d \n",upper);
	fprintf(out_file,"#lowers = %d \n",lower);
	fprintf(out_file,"#others = %d \n",notAlpha);
	fprintf(out_file,"#spaces = %d \n",whiteSpaces);
	fclose(out_file);

	return;
}

//---------------------- Task 2 ---------------------------------
void format_file1(const char *in_file, const char *out_file) {
	FILE *inFile = NULL;
	FILE *outFile = NULL;

	outFile = fopen(in_file, "r");
	inFile = fopen(out_file, "w");

	char word[100];

	if (outFile == NULL) {
			printf("Error(format_file1): Could not open file %s\n", in_file);
			return;}
	while (!feof(outFile)){
		int empty = 0;
		fscanf(outFile, "%s", word);
		if (word[strlen(word)-1] == '\n') {
			if (empty % 2 == 0) {
				fprintf(inFile, '\n');
			} else {
				empty++;
			}
		} else{
			fprintf(inFile, "%s ", word);
		}
		if (word[strlen(word)]=='.'){
					fprintf(inFile, '\n');
				}

	}
	fclose(inFile);
	fclose(outFile);
	return;
}

//---------------------- Task 3 ---------------------------------
void format_file2(const char *in_file, const char *out_file)  {

	FILE *in = NULL;
	FILE *out = NULL;

	int buffer = 100;
	char line[buffer];
	int x = 1;
	in = fopen(in_file, "r");
	out = fopen(out_file, "w");

	    if(in == NULL) {
	    	printf("Error(format_file2): Could not open file %s\n", in_file);
	        return;
	    }

	    while(fgets(line, buffer, in)) {

	        fprintf(out, "%d ", x);


	        x++;
	        fprintf(out, "%s", line);
	    }

	    fclose(in);
	    	fclose(out);

	    return;
	}


//---------------------- Task 4 ---------------------------------
void filter_by_area(const char *in_file, const char *out_file, float area_threshold) {
	char line_str[100];
	FILE *input = NULL;
	FILE *output = NULL;
	input = fopen(in_file, "r");
	output = fopen(out_file, "a");
	char city[100];
	//long pop;
	float area;
	int ctr = 0;
	if (input == NULL) {
		printf("Error(filter_by_area): Could not open file %s\n", in_file);
		return;
	}

	fprintf(output, "Cities with area >= %.2f:\n", area_threshold);
	while (fgets(line_str, 100, input)) {

		char *t = strtok(line_str, " ");

		for (int i = 0; i < t; i++) {
			if (i == 2) {
				strcpy(city, t);
			}
			if (i == 9) {
				char *buff;
				area = strtod(t, &buff);
			}
			t = strtok(NULL, " ");
		}
		if (area >= area_threshold) {
			ctr++;
			fprintf(output, "%s = %.0f\n", city, area);
		}
	}
	if (ctr == 0) {
		fprintf(output, "No cities were found");
		return;
	}
	fprintf(output, "\n");
	fclose(input);
	fclose(output);
	return;
}




//---------------------- Task 5 ---------------------------------
void replace_two_chars(const char *filename, char *str1, char* str2) {
	FILE *file = NULL;
	file = fopen(filename, "r+");
	char word[1000];

	if (file == NULL) {
		printf("Error(replace_two_chars): Could not open file %s\n", filename);
		return;
	}

	fgets(word, 1000, file);
	while (word!= NULL) {
		for (int i = 0; i <= strlen(word); i++)

			if (word[i] == str1[0] && word[i + 1] == str1[1]) {
				fseek(file, -1, SEEK_CUR);
				fprintf(file, str2);
				fseek(file, 0, SEEK_CUR);

			} else {
				fputc(word[i], file);
			}
		fgets(word, 1000, file);
	}
	return;
}


