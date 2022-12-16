/**
 * -------------------------
 * Student Name:Mubin Qureshi
 * Student ID:180181900
 * Student email:qure1900@mylaurier.ca
 * -------------------------
 */

#ifndef DATA_H_
#define DATA_H_
#include "process.h"
typedef Process Data;

void print_data(Data* d);
void destroy_data(Data** d);
Data* copy_data(Data *d);



#endif /* DATA_H_ */
