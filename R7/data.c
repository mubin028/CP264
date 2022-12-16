/**
 * -------------------------
 * Student Name:Mubin Qureshi
 * Student ID:180181900
 * Student email:qure1900@mylaurier.ca
 * -------------------------
 */
#include"data.h"

void print_data(Data* d){
	print_process(d);
	return;


}
void destroy_data(Data** d){
	destroy_process(d);
	return;
}
Data* copy_data(Data *d){
	return copy_process(d);
}


