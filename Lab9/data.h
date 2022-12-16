/*
 * data.h
 *
 *  Created on: Nov. 4, 2021
 *      Author: mubin
 */

#ifndef DATA_H_
#define DATA_H_
#include "process.h"
typedef Process Data;

void print_data(Data* d);
void destroy_data(Data** d);
Data* copy_data(Data *d);
void swap_data(Data *d1,Data *d2);
int compare_data(Data *d1, Data *d2);



#endif /* DATA_H_ */
