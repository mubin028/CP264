/*
 * data.c
 *
 *  Created on: Nov. 4, 2021
 *      Author: mubin
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


