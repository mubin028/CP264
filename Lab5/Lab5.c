/*
 * ---------------------------------
 * Student Name:Mubin Qureshi
 * Student ID:180181900
 * Student Email:qure1900@mylaurier.ca
 * Marked by Kavitha kunku
 * ---------------------------------
 */
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <math.h>
# include <ctype.h>

char* encrypt(char *plaintext, int key) {

	int size = strlen(plaintext), index;
	char *ciphertext = (char*) malloc(size * sizeof(char));
	for (int i = 0; i < size; i++) {
		if (isalpha(plaintext[i])) {

			index = plaintext[i];

			if (index <= 90) {
				index = 'A' + (plaintext[i] - 'A' + key + 26) % 26;
			} else
				index = 'a' + (tolower(plaintext[i]) - 'a' + key + 26) % 26;

			//index = 'a' + (tolower(plaintext[i]) - 'a' + key + 26) % 26;

			ciphertext[i] = index;

		} else {
			ciphertext[i]=plaintext[i];
		}
		ciphertext[i + 1] = '\0';
	}

	return ciphertext;
}

char* decrypt(char *ciphertext, int key) {

	int size = strlen(ciphertext), index;
	char *plaintext = (char*) malloc(size * sizeof(char));
	for (int i = 0; i < size; i++) {
		if (isalpha(ciphertext[i])) {
			index = ciphertext[i];
			if (index <= 90) {
				index = 'A' + (ciphertext[i] - 'A' - key + 26) % 26;
			} else
				index = 'a' + (tolower(ciphertext[i]) - 'a' - key + 26) % 26;

			plaintext[i] = index;
		} else
			plaintext[i]=ciphertext[i];
		plaintext[i + 1] = '\0';
	}
	return plaintext;
}
