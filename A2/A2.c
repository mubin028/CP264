/**
 * -------------------------
 * Student Name:Mubin Qureshi
 * Student ID:180181900
 * Student email:qure1900@mylaurier.ca
 * -------------------------
 */

# include <stdio.h>
# include "matrix.h"

//----------- Task 1: Matrix Checkers ------------

int _is_square() {
	//implementing this private helper function is optional
	int rowlen, collen;
	rowlen = get_row_length(0);
	collen = get_column_length(0);
	if (rowlen < collen)
		rowlen = collen;

	if (!is_empty()) {
		for (int i = 0; i < +collen; i++) {
			if (get_column_length(i) != get_row_length(i))
				return False;
		}

	} else
		return False;
	return True;
}
/**
 * ----------------------------------------------------------------
 * Parameters:		no parameters
 * return:			True(1)/False(0)
 * Description:
 * 		inspect the current contents of matrix
 * 		return True if the contents represent a valid identity matrix
 * 		An identity matrix is a square matrix, all diagonal elements equal to 1,
 * 			all other elements are equal to 0
 * 		An empty matrix is NOT an identity matrix
 * ----------------------------------------------------------------
 */
int is_identity() {
	if (!_is_square())
		return False;

	int x = get_column_length(0);
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < x; j++) {
			if (i == j) {
				if (matrix[i][j] != 1)
					return False;
			} else {
				if (matrix[i][j] != 0)
					return False;
			}
		}
	}

	return True;
}

/**
 * ----------------------------------------------------------------
 * Parameters:		no parameters
 * return:			True(1)/False(0)
 * Description:
 * 		inspect the current contents of matrix
 * 		return True if the contents represent a valid unique matrix
 * 		A unique matrix is a matrix in which all elements have unique values
 * 			i.e. no two elements have equal value
 * 		An empty matrix is NOT a unique matrix
 * ----------------------------------------------------------------
 */
int is_unique() {




	if (is_empty())
			return False;
	if (!is_matrix())
		return False;

	char s[100]="";


	int cont=0;
	for (int x = 0;x <  get_row_length(0); x++){

		for (int y = 0;y <  get_column_length(0); y++){

			for (int z = 0; z < 100;z++){
				if (matrix[y][x]==s[z]){
					return False;
				}
			}

			s[cont] = matrix[y][x];
			cont+=1;

		}
	}

	return True;
}

/**
 * ----------------------------------------------------------------
 * Parameters:		no parameters
 * return:			True(1)/False(0)
 * Description:
 * 		inspect the current contents of matrix
 * 		return True if the contents represent a valid uniform matrix
 * 		A uniform matrix is a matrix in which all elements are equal
 * 		An empty matrix is NOT a uniform matrix
 * ----------------------------------------------------------------
 */
int is_uniform() {

	if (is_empty())
				return False;
		if (!is_matrix())
			return False;

	char key = matrix[0][0];

	for (int x = 0;x <  get_row_length(0); x++){

			for (int y = 0;y <  get_column_length(0); y++){

				if (matrix[y][x] != key){
					return False;
				}

				}
			}

	//your code here
	return True;
}

//----------- Task 2: Matrix Classifier ------------

/**
 * ----------------------------------------------------------------
 * Parameters:		mode(char): s = size, c = content
 * return:			type(int)
 * Description:
 * 		inspect the current contents of matrix
 * 		Returns the classification of the matrix
 * 		General classification (works for both modes):
 * 			-1: not matrix
 * 			 0: empty matrix
 * 		Matrix classification by size:
 * 			 1: vector
 * 			 2: square
 * 			 3: rectangle
 * 		Matrix classification by content:
 * 			 1: identity
 * 			 2: unique
 * 			 3: uniform
 * 			 4: undefined
 * Errors:	 		invalid mode
 * ----------------------------------------------------------------
 */
int classify_matrix(char mode){
	if (is_empty())
		return 0,0,"empty matrix";
	if (!is_matrix())
		return -1,-1,"invalid matrix";
	//int x = get_row_length();
	//int y = get_column_length();
	int size;
	int classification;

	/*if (x==y)
		size = 2;
		else if (x == 1 || y==1)
			size = 1;
		else
			size = 3;
*/
	return size;



	//your code here


	return -99;
}

/**
 * ----------------------------------------------------------------
 * Parameters:	no parameters
 * return:		no returns
 * Description:
 * 		prints classification of the matrix based on current values
 * 		classification includes both size and content
 * 		see sample output for format
 * Errors:	 	invalid mode
 * ----------------------------------------------------------------
 */
void print_matrix_classification(){
	//your code here
	return;
}

//----------- Task 3: Triangular Matrix  ------------

/**
 * ----------------------------------------------------------------
 * Parameters:	length(int): square side length
 * 				corner(char): 'T'= top corner, 'B' = bottom corner
 * 				side(char): 'L' = left side, 'R' = right side
 * 				fill(int): number to fill the matrix with
 * return:		no returns
 * Description:
 * 		Initialize a matrix then fill it in a triangular manner
 * 		The corner and side determine the position of the triangle right angle
 * 		All cells in the triangle are set to "fill", and the other cells to 0
 * Errors: 		invalid length, invalid corner, invalid side
 * ----------------------------------------------------------------
 */
void fill_triangle(int length, char corner, char side, int fill){
	//your code here
	return;
}

//----------- Task 4: Flip Matrix  ------------
/**
 * ----------------------------------------------------------------
 * Parameters:	mode(char): 'h': horizontal, 'v': vertical
 * return:		no returns
 * Description:
 * 		flips the contents of the global matrix
 * 		For horizontal flip, the first row is swapped with the last row
 * 			the second row is swapped with the second to last row, and so forth
 * 		For vertical flip, the first column is swapped with the last column
 * 			the second column is swapped with the second to last column, and so forth
 * Errors: 	invalid mode, invalid matrix
 * ----------------------------------------------------------------
 */
void flip(char mode){
	//your code here
	return;
}
