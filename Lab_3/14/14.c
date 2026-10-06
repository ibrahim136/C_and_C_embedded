#include <stdio.h>
#include <stdlib.h>

char* enter_string();

void inverting_string_letters(char* string);

int main() {
	printf("This program reads a sentence and replace lowercase characters with uppercase and vice versa\n\n");
	char * string = enter_string();
	if (!string) {
		printf("string has not been allocated");
		return -1;
	}
	printf("\n\n-----Before Inverting-----\n\n");
	printf("String: %s", string);

	inverting_string_letters(string);

	printf("\n\n-----After Inverting-----\n\n");
	printf("String: %s\n\n", string);


	free(string);
}

char* enter_string()
{
	printf("Please enter your string: ");
	int character;
	character = getchar();
	int cnt = 1;
	char* temp = (char*)malloc(sizeof(char));
	if (!temp) {
		printf("string has not been allocated");
		return NULL;
	}
	temp[0] = '\0'; //puting null to handle the string if empty

	char* temp_temp;
	while (character != '\n') {
		temp_temp = (char*)realloc(temp,++cnt * sizeof(char));
		if (!temp_temp) {
			printf("string has not been allocated");
			free(temp);
			return NULL;
		}
		temp_temp[cnt - 2] = (char)character;
		temp_temp[cnt - 1] = '\0';
		temp = temp_temp;
		character = getchar();
	}
	return temp;
}

void inverting_string_letters(char* string) {
	long long i = 0;
	char shift = 'a' - 'A';
	while (string[i] != '\0') {
		if (string[i] >= 'A' && string[i] <= 'Z') {
			string[i] += shift;
		}
		else if (string[i] >= 'a' && string[i] <= 'z') {
			string[i] -= shift;
		}
		i++;
	}
}













