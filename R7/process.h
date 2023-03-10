/**
 * -------------------------
 * Student Name:Mubin Qureshi
 * Student ID:180181900
 * Student email:qure1900@mylaurier.ca
 * -------------------------
 */
#ifndef PROCESS_H_
#define PROCESS_H_

#define True 1;
#define False 0;

typedef struct Process_struct{
	unsigned long PID; //process id [10-digits]
	unsigned int time; //requested processing time
	unsigned int arrival; //arrival time
}Process;


Process* create_process(long p_pid, int p_time, int arrival_time);
void destroy_process(Process** p);
void print_process(Process* p);
Process* copy_process(Process* p);
void get_process_info(Process* p, char* info);
int is_equal_process(Process* p1,Process* p2);
unsigned long get_UPID();



#endif /* PROCESS_H_ */
