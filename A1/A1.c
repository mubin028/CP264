/**
 * -------------------------
 * Student Name:Mubin Qureshi
 * Student ID:180181900
 * Student email:qure1900@mylaurier.ca
 * -------------------------
 */
 
# include <stdio.h>
# include <math.h>

double compute(double n, double p, double q){

	double exp1,exp2,exp3,r;
	exp1 = (n+p)/ceil(p-q);
	exp2 = floor(n*q)/(sqrt(p*q));
	exp3 = pow(M_PI,6)/log2(q-n);
	r = exp1 + exp2 - exp3;

	printf("n = %.4f\n",n);
	printf("p = %.4f\n",p);
	printf("q = %.4f\n",q);
	printf("r = %.4f + %.4f - %.4f\n",exp1,exp2,exp3);
	return r;
}

int print_country(short code){
	int success = 0;

	if (code == 1){
		printf("USA");
		success = 1;
	}
	else if (code ==2){
		printf("Canada");
		success = 1;
	}
	else
		printf("Undefined");
    return success;
}

int print_color(short code){
	int success = 0;
	switch(code){
	case 0:
			printf("Black");
			success = 1;
			break;
	case 1:
			printf("Grey");
			success = 1;
			break;
	case 2:
			printf("Brown");
			success = 1;
			break;
	case 3:
			printf("Purple");
			success = 1;
			break;
	case 4:
			printf("Blue");
			success = 1;
			break;
	case 5:
			printf("Green");
			success = 1;
			break;
	default:
		printf("Undefined");
		break;
	}
	return success;
}

int print_size(short code){
	int success = 0;
		switch(code){
		case 0:
				printf("Tiny");
				success = 1;
				break;
		case 1:
				printf("Small");
				success = 1;
				break;
		case 2:
				printf("Medium");
				success = 1;
				break;
		case 3:
				printf("Large");
				success = 1;
				break;
		case 4:
				printf("Huge");
				success = 1;
				break;
		default:
			printf("Undefined");
			break;
		}
		return success;
}

short get_code(long serial_number,char type){


	int code = -99;

	if ((serial_number / 100000==0 )|| (serial_number / 100000 > 9))
		return code;

		switch(type){
		case 'y':
				code = serial_number/100000;
				break;
		case 'r':
				code =fabs(serial_number/100000 * 10- serial_number/10000);
				break;
		case 's':
				code =serial_number/1000 - ( serial_number/10000 * 10 );
				break;
		case 'i':
				code = serial_number - ((serial_number / 1000)*1000);
				break;
		default:
			code = -99;
			break;
		}
		return code;
}

void print_description(long serial_number){
	int code1,code2,code3,code4;
	int country,color,size;

	code1 = get_code(serial_number,'y');
	code2 = get_code(serial_number,'r');
	code3 = get_code(serial_number,'s');
	code4 = get_code(serial_number,'i');
	printf("country = ");
	country = print_country(code1);
	printf("\n");
	printf("color = ");
	color = print_color(code2);
	printf("\n");
	printf("size = ");
	size = print_size(code3);
	printf("\n");
	printf("item = %d\n",code4);
	if (country != -0 || size !=0 || color != 0||code4 !=-99){
	printf("A Beautiful");

	if (size != 0){
	printf(" ");
	size = print_size(code3);
	}
	if (color != 0){
		printf(" ");
		color = print_color(code2);
	}
	printf(" Box item# %d",code4);

	if (country != 0){
	printf(" ");
	printf("made in ");
	country = print_country(code1);
	}

	printf("\n");

	}
	else
		printf("Description not found\n");
	return;
}

char math_game(long lv, int lmf, int lsf, int lrf, long rv, int rmf, int rsf, int rrf){
	int counter = 0,lcounter = 0, rcounter = 0;
	char winner;

	printf("Starting Math Game:\n");
	printf("[%lu,%d,%d,%d] vs [%lu,%d,%d,%d]\n",lv,lmf,lsf,lrf,rv,rmf,rsf,rrf);

	while ((counter < 5) && (lv < rv)){
		printf("Round = %d\n",counter+1);
		lcounter = 0;
		while (lcounter < lrf){
			lv = lv*lmf - lsf;
			printf("L = %li\n",lv);
			lcounter+=1;
		}
		rcounter = 0;
		while (rcounter < rrf){
			 rv = rv*rmf - rsf;
			 printf("R = %li\n",rv);
			 rcounter += 1;
		}

	counter += 1;
	}
	printf("Closing Math Game\n");
	if (counter==5)
		winner = 'R';
	else
		winner = 'L';

	return winner;
}
