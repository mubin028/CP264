/**
 -------------------------
 Student Name:Mubin Qureshi
 Student ID:180181900
 Student email:qure1900@mylaurier.ca
 -------------------------
 **/
void t1();
void t2();
void t3();

int main(){
	t1();
	printf("\n");
	//t2();
	printf("\n");
	//t3();
}

void t1(){
	int tall,small,total;
	double avg_height;
	char symbol = 84;
	const int val = 43;

	printf("Enter number of tall trees: ");
	scanf("%d", tall);
	printf("Enter number of short trees: ");
	scanf("%d",&small);
	total = tall + small;
	//printing report
	printf("Number of %c trees = %d\n", symbol, tall);
	symbol = symbol - 1;
	printf("Number of %c trees = %d\n",(symbol-1),small);
	printf("Average height = %.2lf", (val / total));
	return;
}

void t2(){
	unsigned int year;
	short month;
	int day;
	char university[30];

	//your code here
	return;
}

void t3(){
	//your code here
	return;
}