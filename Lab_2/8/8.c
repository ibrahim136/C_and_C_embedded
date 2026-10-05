#include <stdio.h>
#include <math.h>

void Define_char(char* l, char arr[]);

char is_vowel_or_consonant(char* l);

void print_vowel_or_consonant(char* l);

int main() {
	printf("This program is detecting the given alphabet letter is vowel or consonant\n\n");
	char l;
	Define_char(&l, "letter");
	print_vowel_or_consonant(&l);
}

void Define_char(char* l, char arr[])
{
	char temp[3];
	char check = 1;
	while (check) {
		printf("Please enter the %s: ", arr);
		check = scanf("%2s", temp);
		if (temp[1] != '\0') {
			printf("You have entered more than 1 input... please try again a single letter input\n\n");
			check = 1;
			scanf("%*[^\n]"); //% type specifier /  * disacard / [^\n] read except new line
		}
		else if (temp[0] < 'A' || temp[0] > 'z') {
			printf("You didn't enter a letter input... please try again a letter input\n\n");
			check = 1;
			scanf("%*[^\n]"); //% type specifier /  * disacard / [^\n] read except new line
		}
		else
		{
			*l = temp[0];
			scanf("%*[^\n]"); //% type specifier /  * disacard / [^\n] read except new line
			check = 0;
		}
	}
}

char is_vowel_or_consonant(char* l)
{
	int i;
	char arr[] = { 'a','A','E','e','I','i','o','O','u','U' };
	for (i = 0; i < 10; i++) {
		if (*l == arr[i])
		{
			return 1;
		}
	}
	return 0;
}

void print_vowel_or_consonant(char* l) {
	printf("\nThis alhabet letter is ");
	if (is_vowel_or_consonant(l))
	{
		printf("vowel.\n");
	}
	else {
		printf("consonant.\n");
	}
}