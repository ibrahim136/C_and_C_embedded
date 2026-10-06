#include <stdio.h>
#include <stdlib.h>

char* enter_string();

long long get_length(char* string);

void copy_string(char* string1, char* string2);

int main() {
	printf("This program copy one string to another string\n\n");
	char * string1 = enter_string();
	if (!string1) {
		printf("string no. 1 has not been allocated");
		return -1;
	}
	char* string2 = enter_string();
	if (!string2) {
		printf("string no. 2 has not been allocated");
		free(string1);
		return -1;
	}
	printf("\n\n-----Before Copying string no.1 in string no.2");
	printf("\n\nYour string no. 1: %s", string1);
	printf("\n\nYour string no. 2: %s\n\n", string2);

	copy_string(string1, string2);

	printf("\n\n-----After Copying string no.1 in string no.2");
	printf("\n\nYour string no. 1: %s", string1);
	printf("\n\nYour string no. 2: %s\n\n", string2);

	free(string1);
	free(string2);
}

char* enter_string()
{
	static int cnt_string_no = 1;
	printf("Please enter your string no. %i: ",cnt_string_no++);
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

void copy_string(char* string1, char* string2) {
	long long l1 = get_length(string1);
	long long l2 = get_length(string2);
	long long l;
	if (l1 != l2) {
		if (l1 > l2) {
			printf("The first %lld element",l2);
			if (l2 > 1) {
				printf("s");
			}

			printf(" will be copied from string no.1 into string no.2");
			l = l2;
		}
		else {
			printf("All elements of string no.1 will be copied into string no.2");
			l = l1;
		}
	}
	else {
		printf("All elements of string no.1 will be copied into string no.2");
		l = l1;
	}
	
	long long i;
	for (i = 0; i < l; i++)
	{
		string2[i] = string1[i];
	}
	string2[l] = '\0';
}

long long get_length(char* string) {
	long long i = 0;
	while (string[i] != '\0')
	{
		i++;
	}
	return i;
}













