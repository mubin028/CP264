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

void write_nums(const char *filename, int start, int end) {
	FILE *out_file = NULL;
	out_file = fopen(filename, "w");
	if(out_file == NULL){
		printf("Error(write_nums): Could not open file %s\n",filename);
		return;
	}
	for(int i = start; i<= end; i++){
		fprintf(out_file,"%d\n",i);

	}
	fclose(out_file);
	return;
}

int read_nums(const char *filename, int *array) {
	FILE*in_file = NULL;
in_file =fopen(filename,"r");
if(in_file == NULL){
	printf("Error(read_nums): Could not open file %s\n",filename);
	return 0;
}
int temp, i=0;
fscanf(in_file,"%d",&temp);
while(!feof(in_file)){
	array[i++] = temp;

	fscanf(in_file,"%d",&temp);


}
fclose(in_file);

	return i-1;
}

int extract_minutes(char *filename, unsigned int *minutes_array, const int size) {
	FILE *in_file = NULL;
	in_file =fopen(filename, "r");
	if (in_file == NULL) {
		printf("Error(extract_minutes): Could not open file %s\n", filename);
		return 0;
	}
	char line[10];
	int counter = 0;
	while (fgets(line, sizeof(line), in_file )!= NULL && counter < size){
		printf("line = %s\n",line);
		counter++;
	}
	fclose(in_file);
	return 0;
}

void print_record_info1(char *record) {
	char *results[5], *token = NULL;
	int i = 0;
	record++;

	token = strtok(record,"-");
	results[i++] = token;

	while (token){
		token = strtok(NULL,"-");
		results[i++] = token;
	}
	int length = strlen(results[4]);
	results[4][length-1] = "\0";
	for (int j = 0; j < 5; j++){

		printf("token%d = %s\n",j+1, results[j]);

	}

	return;
}

void print_record_info2(char *record) {

	int reg_year,day,year;
	char month[11],first[20], last[20];
	record++;
	sscanf(record,"%d %s %d %d %s %s", &reg_year,month,&day,&year,first,last);
	last[strlen(last) - 1] = '\0';
	printf("Registration year = %d\n",reg_year);
	printf("Birthday = %s %d %d\n",month,day,year);
	printf("Name = %s %s\n",first,last);


	return;
}

void print_record_info3(char *record) {
	int reg_year, day, year;
	char month[11], first[20], last[20];
	char *buffer1 = NULL, *buffer2 = NULL, *buffer3 = NULL;
	buffer1 = strtok(record, ":"); //dummy to get rid of "record:"
	buffer1 = strtok(NULL, "-");
	sscanf(buffer1, "%d", &reg_year);
	buffer1 = strtok(NULL, "-"); //fetching birthday
	buffer3 = strtok(NULL, "-");
	buffer2 = strtok(buffer1, ",");
	strcpy(month, buffer2);
	buffer2 = strtok(NULL, ",");
	sscanf(buffer2, "%d", &day);
	buffer2 = strtok(NULL, ",");
	sscanf(buffer2, "%d", &year);
	buffer3++;
	sscanf(buffer3, "%s %s", first, last);
	last[strlen(last) - 1] = '\0';
	printf("Registration year = %d\n",reg_year);
		printf("Birthday = %s %d %d\n",month,day,year);
		printf("Name = %s %s\n",first,last);
	return;
}

void modify_grades(char *filename, int bonus) {
	FILE *in_file;
	in_file =fopen(filename,"r+");
	if (in_file == NULL){
		printf("Could not open file %s for reading. \n",filename);
		fclose(in_file);
		return;
	}
	char record[20],*grade_str,*end_ptr;
	int grade, record_num = 0;
		while(fgets(record,15,in_file)!=NULL){
			grade_str = strtok(record,",");
			grade_str = strtok(NULL,"]");
			grade = (int) strtol(grade_str,&end_ptr,10)+bonus;
			fseek(in_file,11+(14*record_num), SEEK_SET);
			fprintf(in_file,"%d",grade);
			fseek(in_file,1,SEEK_CUR);  //switch from writing to reading
			record_num++;

		}
		fclose(in_file);

	return;
}

int replace_char(char* filename, char letter1, char letter2){
int counter = 0;
FILE* fptr = NULL;
fptr = fopen(filename, "r+");
if (fptr == NULL){
	printf("Error{replace_char}: could not open file %s\n",filename);
	return -1;
}
	if (!isalpha(letter1) || !isalpha(letter2)) {
		printf("Error{replace_char): invalid input characters\n");
		fclose(fptr);
		return -1;
	}

	char c =fgetc(fptr);
	while (c != EOF) {
		if(isalpha(c) && tolower(c) == tolower(letter1)){
			fseek(fptr,-1,SEEK_CUR);//switch from reading to writing
			fputc(letter2,fptr);
			counter++;
			fseek(fptr,0,SEEK_CUR); //switch from writing to reading
		}
		c = fgetc(fptr);

	}
fclose(fptr);
return counter;
}

