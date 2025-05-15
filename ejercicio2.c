#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

// Verificamos si es palindromo
bool Palindrome(const char *word) {
	int length = strlen(word);
	for (int i = 0; i < length / 2; i++) {
		if (word[i] != word[length - i - 1]) {
			return 0;
		}
    	}	
    	return 1;
}

// Funcion para solo dejar letras en minusculas
void clean(char *word) {
	int i = 0, j = 0;
	while (word[i]) {
		if (isalnum(word[i])) {
			word[j] = tolower(word[i]);
			j++;
		}
		i++;
	}
    word[j] = '\0';
}

int main() {
	char currentWord[100];
	char longestPalindrome[100] = "";
	int maxLength = 0;
	
	//Lee el archivo
	FILE *file = fopen("input.txt", "r");
	if (file == NULL) {
		printf("No se pudo abrir el archivo.\n");
		return 1;
	}

	//Lee palabra por palabra
	while (fscanf(file, "%s", currentWord) == 1) {
		clean(currentWord);
		if (strlen(currentWord) > 0 && Palindrome(currentWord)) {
			
			if (strlen(currentWord) > maxLength) {
				maxLength = strlen(currentWord);
				strcpy(longestPalindrome, currentWord);
			}
		}
	}

	fclose(file);

	if (maxLength > 0) {
		printf("El palíndromo más largo es: %s (longitud: %d)\n", longestPalindrome, maxLength);
	} else {
		printf("No se encontraron palíndromos en el archivo.\n");
	}

	return 0;
}
