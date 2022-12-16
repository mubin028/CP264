/*
 * ---------------------------------
 * Student Name:Mubin Qureshi
 * Student ID:180181900
 * Student Email:qure1900@mylaurier.ca
 * ---------------------------------
 */


# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <assert.h>
# include "A8.h"

/*---------------------Task 1 -----------------------------*/
void schedule(char *type, Data *processes, const int size) {
	char ptr;


	if (strcmp(type,"FIFO")==0){
		pQueue *q = create_pqueue(size*2,'L');

		for (int i = 0; i < size;i++){
			insert_pqueue2(q,&processes[i]);
		}
		schedule_FIFO(q);
	}else if (strcmp(type,"SJF")==0){
		pQueue *q = create_pqueue(size*2,'L');

		for (int i = 0; i < size;i++){
			insert_pqueue2(q,&processes[i]);
		}
		schedule_SJF(q);
	}else if (strstr(type,"DRR")){
		ptr = type[3];
		int num = ptr - '0';

		//printf("%d",ptr);
		pQueue *q = create_pqueue(size*2,'L');

		for (int i = 0; i < size;i++){
			insert_pqueue2(q,&processes[i]);
		}
		schedule_DRR(q,num);
	}else if (strstr(type,"RR")){
		ptr = type[2];
		int num = ptr - '0';

		pQueue *q = create_pqueue(size*2,'L');

		for (int i = 0; i < size;i++){
			insert_pqueue2(q,&processes[i]);
		}
		schedule_RR(q,num);
	}else{
		printf("Error(schedule): Unsupported scheduler type\n");

	}


	return;
}

/*---------------------Task 2 -----------------------------*/
void schedule_FIFO(pQueue *q) {
	unsigned int timer = 0;
	printf("[Timer:%d]: Starting FIFO Scheduler\n",timer++);


	while(!is_empty_pqueue(q)){


		if (timer >=peek_pqueue2(q)->arrival){
				int i = 0;
				printf("Fetching Process: ");
				print_process(peek_pqueue2(q));
				printf("\n");

			while (i < peek_pqueue2(q)->time){
				printf("[Timer:%d]: ",timer);
				print_process(peek_pqueue2(q));
				printf("\n");
				i++;
				timer++;
			}
			remove_pqueue2(q);

		}
		else{
			printf("[Timer:%d]: Idle\n",timer++);
		}

	}
	printf("[Timer:%d]: Closing FIFO Scheduler\n",timer++);
	return;
}

/*---------------------Task 3 -----------------------------*/
void schedule_SJF(pQueue *q) {

	Data *arrival = NULL;
	unsigned int arrSize = 0, timer = 0;
	Data shortest;
	printf("[Timer:%d]: Starting SJF Scheduler\n", timer++);

	arrival = (Data*) malloc(sizeof(Data) * len_pqueue(q));

	while (!is_empty_pqueue(q)) {

		arrSize = 0;
		//print_pqueue(q);
		//printf("%d\n",len_pqueue(q));

		if (timer >= peek_pqueue2(q)->arrival && len_pqueue(q) > 1) {
			while (timer >= peek_pqueue2(q)->arrival) {
				arrival[arrSize++] = *copy_data(remove_pqueue2(q));
			}
			//print_data(arrival);
			if (arrSize > 0) {
				int spot = 0;
				shortest = arrival[0];

				for (int i = 0; i < arrSize; i++) {
					if (arrival[i].time < shortest.time) {
						shortest = arrival[i];
						spot = i;
					}
				}
				//print_pqueue(q);

				for (int i = 0; i < arrSize; i++) {
					//printf("%d\n",len_pqueue(q));
					//	print_pqueue(q);
					//	printf("%d %d \n",arrSize,i);
					if (i != spot) {
						insert_pqueue2(q, &arrival[i]);
					}
				}

			}
			printf("Fetching Process: ");
			print_process(&shortest);
			printf("\n");

			for (int i = 0; i < shortest.time; i++) {
				printf("[Timer:%d]: ", timer++);
				print_process(&shortest);
				printf("\n");
			}

		} else if (len_pqueue(q) == 1) {

			int i = 0;
			printf("Fetching Process: ");
			print_process(peek_pqueue2(q));
			printf("\n");

			while (i < peek_pqueue2(q)->time) {
				printf("[Timer:%d]: ", timer);
				print_process(peek_pqueue2(q));
				printf("\n");
				i++;
				timer++;
			}
			remove_pqueue2(q);

		}

		else {
			printf("[Timer:%d]: idle\n", timer++);
		}

	}
	return;
}


/*---------------------Task 4 -----------------------------*/
void schedule_RR(pQueue *q, int period) {
	unsigned int timer = 0;
	printf("[Timer:%d]: Starting RR%d Scheduler\n", timer, period);
	timer++;

	Data *data = NULL;


	while (!is_empty_pqueue(q)) {
		//print_pqueue(q);

		if (timer>=peek_pqueue2(q)->arrival) {
			int i = 0;
			printf("Fetching Process: ");
			print_process(peek_pqueue2(q));
			printf("\n");


			if (peek_pqueue2(q)->time>= period) {
				for (i = 0; i < period; i++) {
					printf("[Timer:%d]: ", timer++);
					print_process(peek_pqueue2(q));
					printf("\n");

				}
				data = remove_pqueue2(q);
			} else {
				for (i = 0; i < peek_pqueue2(q)->time; i++) {
					printf("[Timer:%d]: ", timer++);
					print_process(peek_pqueue2(q));
					printf("\n");
				}
				data = remove_pqueue2(q);

				if (data->time > period) {
					data->arrival = timer;
					data->time = data->time - period;
					insert_pqueue2(q, data);

				}
			}

		} else
			printf("[Timer:%d]: idle\n", timer++);


	}
	return;
}

/*---------------------Task 5 -----------------------------*/
//void schedule_DRR(pQueue *q, int period){
//	unsigned int timer = 0;
//	printf("[Timer:%d]: Starting DRR%d Scheduler\n", timer, period);
//	timer++;
//
//	Data *data = NULL;
//	Data *store = NULL;
//	int len = 0;
//	int multiple;
//	store = (Data*) malloc(sizeof(Data) * len_pqueue(q));
//
//	while (!is_empty_pqueue(q)) {
//		//print_pqueue(q);
//
//		if (timer>=peek_pqueue2(q)->arrival) {
//			int i = 0;
//			printf("Fetching Process: ");
//			print_process(peek_pqueue2(q));
//			printf("\n");
//
//			multiple = 1;
//			data = peek_pqueue2(q);
//			for (int z = 0;z < len;z++){
//				if(compare_data(data,&store[z])==0){
//					multiple++;
//				}
//			}
//
//			if (peek_pqueue2(q)->time>= period*multiple) {
//				for (i = 0; i < period*multiple; i++) {
//					printf("[Timer:%d]: ", timer++);
//					print_process(peek_pqueue2(q));
//					printf("\n");
//
//				}
//				data = remove_pqueue2(q);
//			} else {
//				for (i = 0; i < peek_pqueue2(q)->time; i++) {
//					printf("[Timer:%d]: ", timer++);
//					print_process(peek_pqueue2(q));
//					printf("\n");
//				}
//				data = remove_pqueue2(q);
//
//				if (data->time > period*multiple) {
//					data->arrival = timer;
//					data->time = data->time - (period*multiple);
//					insert_pqueue2(q, data);
//					store[len++]=*copy_data(data);
//
//
//				}
//			}
//
//		} else
//			printf("[Timer:%d]: idle\n", timer++);
//
//
//	}
//	return;
//}
void schedule_DRR(pQueue *q, int period) {
    //your solution here
    int timer = 0;
    Data *value = NULL;
    printf("[Timer:%d]: Starting DRR3 Scheduler\n", timer);
    timer++;

    while (!is_empty_pqueue(q)) {
        value = remove_pqueue(q);
        while (timer < value->arrival) {
            printf("[Timer:%d]: idle\n", timer);
            timer++;
        }
        printf("Fetching Process: ");
        print_process(value);
        printf("\n");
        int time_count = (period < value->time) ? period : value->time;
        int time_count_copy = time_count;
        while (time_count > 0) {
            printf("[Timer:%d]: ", timer);
            print_process(value);
            printf("\n");
            timer++;
            time_count--;
        }
        value->arrival += time_count_copy;

        if (value->arrival < timer) {
            value->arrival = timer;
        }

        if (period > value->time) {
            value->time = 0;
        } else {
            value->time = value->time - time_count_copy;
        }
        period *= 2;
        if (value->time == 0) {
            destroy_process(&value);
            value = NULL;
        } else {
            insert_pqueue(q, value);
        }
        printf("[Timer:%d]: Closing DRR3 Scheduler\n", timer);

    }

    return;
}
