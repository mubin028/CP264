/**
 * -------------------------
 * Student Name:Mubin Qureshi
 * Student ID:180181900
 * Student email:qure1900@mylaurier.ca
 * -------------------------
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/**
 * --------------------------------------------------------
 * Computes the value of a using the four integer input parameters: r,y,x and b.
 * The value of a is computed according to the following equation:
 *		a = floor((cube(3)-y)/x) - square_root(b to power 4))
 * The function prints the output in a format similar to the following
 *		[r = 2, y = 3, x = 2, b = 2] --> a = -2.0
 * The function also returns the value of a, which is of type double
 * ----------------------------------------------------------
 */
void solve2(short w, int x, float y, double z) {
	double r = log(y);
	r = r* fabs((pow(w,3)-x));
	r = r/ cbrt(z);
	r = r + pow(M_E,3) * ((y*pow(z,3))/x);
	r = r - cbrt(pow(x,y)-y);

	printf("w =       %hd         ", w);
	printf("x =       %d         \n", x);
	printf("y =       %.2f      ", y);
	printf("z =       %.4lf         \n", z);


	printf("r =       %.4lf         \n", r);
	return;
}

/**
 * --------------------------------------------------------
 * Generates and returns a random integer.
 * the mode input parameter controls how the random number is generated, as follows:
 * 1-	If mode is ‘1’: The function generates a random number in the range [0,x1], i.e. inclusive both ends.
 * 2-	If mode is ‘2’: The function generates a random number in the range (0,x2), i.e. exclusive both ends.
 * 3-	If mode is ‘i’: The function generates a random number in the range [x1,x2], i.e. inclusive both ends.
 * 4-	If mode is ‘x’: The function generates a random number in the range (x1,x2), i.e. exclusive both ends.
 * 5-	If mode is ‘L’: The function generates a random number in the range [x1,x2), i.e. inclusive only from the left which is x1.
 * 6-	If mode is ‘R’: The function generates a random number in the range (x1,x2], i.e. inclusive only from the right which is x2.
 * 7-	For any other mode value, the function generates a random number between 0 and RAND_MAX.
 * The function is implemented using switch-case statement.
 * Assume that x1 is always less than x2 by at least 2.
 * ----------------------------------------------------------
 */
unsigned int rand_int(unsigned int x1, unsigned int x2, char mode) {
	srand(time(0));

	int upper, lower, num;


	switch(mode) {

	case '1':

		num = (rand() % (x1 - 0 + 1)) + 0;
		return num;

	case '2':

			num = (rand() % (x2 - 0 + 1)) + 0;
			return num;

	case 'i':

			num = (rand() % (x2 - x1 + 1)) + x1;
			return num;

	case 'x':
				num = (rand() % (x2-1 - x1+1 + 1)) + x1+1;
				return num;

	case 'L':
				num = (rand() % (x2-1 - x1 + 1)) + x1;
				return num;

	case 'R':
					num = (rand() % (x2 - x1+1 + 1)) + x1+1;
					return num;
	default:
		num = rand();

	}
	return num;
	}
