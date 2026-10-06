#include <stdio.h>
#include <stdlib.h>

char* enter_string();
long long get_length(char* string);

int main() {
	printf("This program finds the length of a string without using library functions\n\n");
	char * string = enter_string();
	if (!string) {
		printf("string has not been allocated");
		return -1;
	}
	printf("\n\nYour string: %s\n", string);
	printf("\n\nThe length of string is %lld", get_length(string));
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
		free(temp);
		return 0;
	}
	temp[0] = '\0'; //puting null to handle the string if empty

	char* temp_temp;
	while (character != '\n') {
		temp_temp = (char*)realloc(temp,++cnt * sizeof(char));
		if (!temp_temp) {
			printf("string has not been allocated");
			free(temp);
			return 0;
		}
		temp_temp[cnt - 2] = (char)character;
		temp_temp[cnt - 1] = '\0';
		temp = temp_temp;
		character = getchar();
	}
	return temp;
}

long long get_length(char * string) {
	long long i = 0;
	while (string[i] != '\0')
	{
		i++;
	}
	return i;
}











