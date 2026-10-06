#include <stdio.h>
#include <stdlib.h>

typedef struct string_compare_status{
	char is_same_data;
	char is_same_size;
	long long till_nth_element;
}string_compare_status;

char* enter_string();

string_compare_status get_string_compare_status(char* string1, char* string2);

void print_string_compare(char* string1, char* string2);

int main() {
	printf("This program compares two strings without using string library functions.\n\n");
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
	printf("\n\nYour string no. 1: %s", string1);
	printf("\n\nYour string no. 2: %s\n\n", string2);

	print_string_compare(string1, string2);

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

string_compare_status get_string_compare_status(char* string1, char* string2) {
	string_compare_status return_status;
	long long i = 0;
	char check1 = (string1[i] != '\0');
	char check2 = (string2[i] != '\0');
	while (check1 && check2)
	{
		if (string1[i] != string2[i]) {
			return_status.is_same_data = 0;
			return_status.is_same_size = 0;
			return_status.till_nth_element = i;
			return return_status;
		}
		i++;
		check1 = (string1[i] != '\0');
		check2 = (string2[i] != '\0');
	}
	return_status.is_same_data = 1;
	if (check1 || check2) {
		return_status.is_same_size = 0;
	}
	else {
		return_status.is_same_size = 1;
	}
	return_status.till_nth_element = i;
	return return_status;
}

void print_string_compare(char* string1, char* string2) {
	string_compare_status status = get_string_compare_status(string1, string2);
	if (status.is_same_data) {
		printf("The two strings have the same data\n");
	}
	else {
		printf("The two strings DON'T have the same data\n");
	}
	if (status.is_same_size) {
		printf("The two strings have the same size\n");
	}
	else {
		printf("The two strings DON'T have the same size\n");
	}
	if (status.is_same_data) {
		if (status.is_same_size) {
			printf("The two strings are typically equal in data and size\n");
		}
		else {
			printf("The two strings match till element no. %lld (index [%lld])\n", status.till_nth_element, status.till_nth_element - 1);
		}
	}
	else {
		if (!status.till_nth_element) {
			printf("The two strings DON'T match from the beginning\n");
		}
		else {
			printf("The two strings match till element no. %lld (index [%lld])\n\n", status.till_nth_element, status.till_nth_element - 1);
		}
	}
}











