/**
 * CP264 Spring 2020
 * Week1: R1
 * This program is for testing size of data types at your machine
 */
# include <stdio.h>
# include <limits.h>

int main() {
	printf("%-25s%-10s%-25s%-25s\n", "Data Type", "Bytes", "Min", "Max");
	printf(
			"-------------------------------------------------------------------------------\n");
	printf("%-25s%-10d%-25d%-25d\n", "char", sizeof(char), CHAR_MIN, CHAR_MAX);
	printf("%-25s%-10d%-25d%-25d\n", "unsigned char", sizeof(unsigned char), 0,
	UCHAR_MAX);
	printf("\n");
	printf("%-25s%-10d%-25d%-25d\n", "short", sizeof(short), SHRT_MIN,
	SHRT_MAX);
	printf("%-25s%-10d%-25d%-25d\n", "unsigned short", sizeof(unsigned short),
			0,
			USHRT_MAX);
	printf("\n");
	printf("%-25s%-10d%-25d%-25d\n", "int", sizeof(int), INT_MIN, INT_MAX);
	printf("%-25s%-10d%-25d%-25u\n", "unsigned int", sizeof(unsigned), 0,
	UINT_MAX);
	printf("\n");
	printf("%-25s%-10d%-25ld%-25lu\n", "long", sizeof(long), LONG_MIN,
	LONG_MAX);
	printf("%-25s%-10d%-25d%-25lu\n", "unsigned long", sizeof(unsigned long), 0,
	ULONG_MAX);
	printf("\n");
	printf("%-25s%-10d%-25I64d%-25I64d\n", "long long", sizeof(long long),
	LLONG_MIN, LLONG_MAX);
	printf("%-25s%-10d%-25d%-25I64u\n", "unsigned long long",
			sizeof(unsigned long long), 0, (unsigned long long) ULLONG_MAX);
	return 0;
}
