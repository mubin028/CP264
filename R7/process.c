/**
 * -------------------------
 * Student Name:Mubin Qureshi
 * Student ID:180181900
 * Student email:qure1900@mylaurier.ca
 * -------------------------
 */

#include "process.h"
#include <stdlib.h>
#include<string.h>
#include <assert.h>
#include <assert.h>
#include <stdio.h>




Process* create_process(long pid, int time, int arrival){
	Process* p = (Process*) malloc(sizeof(Process));
	if (time <= 0) {
		fprintf(stderr, "Error(create_process): invalid time - set to 0\n");
		p->time = 0;
	} else
		p->time = time;

	if (arrival < 0) {
		fprintf(stderr,
				"Error(create_process): invalid arrival time - set to 0\n");
		p->arrival = 0;
	} else
		p->arrival = arrival;

	if (pid <= 0) {
		fprintf(stderr,
				"Error(create_process): invalid arrival time - set to random\n");
		p->PID = get_UPID();
	} else
		p->PID = pid;

	return p;

}
void destroy_process(Process** p){
	assert(*p!= NULL);
	(*p)-> PID = 0;
	(*p)->time=0;
	(*p)->arrival = 0;
	//free(*p);
	*p = NULL;
	return;


}
void print_process(Process *p){

	assert(p!=NULL);
	char info[30];
	strcpy(info, "");
	get_process_info(p,info);
	printf("%s", info);
	return;


}
Process* copy_process(Process* p){
	assert(p!=NULL);
	Process *p2= (Process*)malloc(sizeof(Process));
	p2->PID = p->PID;
	p2->arrival = p->arrival;
	p2->time = p->time;
	return p2;


}
void get_process_info(Process* p, char* info){
	assert(p!=NULL);
	char process[30];
	sprintf(process, "[%u](%lu,%lu)", p->arrival, p->PID, p->time);
	strcpy(info, process);
	return;
}
int is_equal_process(Process* p1,Process* p2){
	assert(p1!=NULL);
	assert(p2!=NULL);

	if (p2->PID != p1->PID)
		return False
	if (p2->arrival != p1->arrival)
		return False
	if (p2->time != p1->time)
		return False
	return True;

}
unsigned long get_UPID(){
	static int counter = 10000;
	//get higher 5 digits
	unsigned long higher5 = rand()% (39999-10000+1)+10000;
	higher5 = higher5 * 100000;

	int lower5 = counter;
	counter++;
	return higher5 + lower5;


}
