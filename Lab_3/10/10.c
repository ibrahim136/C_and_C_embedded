#include <stdio.h>
#include <stdlib.h>

char* enter_string();

long long words_count(char* string);

int main() {
	printf("This program counts the total number of words in a string\n\n");
	char * string = enter_string();
	if (!string) {
		printf("string has not been allocated");
		return -1;
	}
	long long words = words_count(string);
	printf("\n\nYour string: %s\n", string);
	printf("\nThe total number of words in the string: %lld word", words);
	if (words > 1 || words ==0) {
		printf("s\n");
	}
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

long long words_count(char* string)
{
	char check = 0;
	long long cnt = 0;
	int i =0;
	while (string[i] != '\0')
	{
		switch (string[i]) {
		case ' ':
		case '\t':
		case ',':
		case '.':
		case ';':
		case ':':
		case '!':
		case '?':
		case '_':
		case '-':
		case '\'':
		case '{':
		case '}':
		case '[':
		case ']':
		case '(':
		case ')':
		case '\\':
		case '/':
			if (check != 0) {
				cnt++;
				check = 0;
			}
			break;
		default:
			check = 1;
		}
		i++;
	}
	if (check) {
		cnt++;
	}
	return cnt;
}









