#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

char is_integer(float* temp);

char is_in_range(int n, int start, int end);

void Define_Integer(char* n, char arr[]);

void print_menu();

char random_number();

char guessing(char* r, char* g);

void print_result(char* is_guessed, char* r);

int main() {
	printf("This program is generating random number between 1 and 100\n\n");
	char g = 0;
	char r = random_number();
	char is_guessed = guessing(&r, &g);
	print_result(&is_guessed, &r);

}


char is_integer(float* temp)
{
	return *temp == (int)*temp;
}

char is_in_range(int n, int start, int end)
{
	return (n > start && n < end);
}

void Define_Integer(char* n, char arr[])
{
	float temp;
	char check = 1;
	while (check) {
		printf("Please enter %s: ", arr);
		check = scanf("%f", &temp);
		if (!check) {
			printf("You have entered non-integer input... please try again an integer input\n\n");
			check = 1;
			scanf("%*[^\n]"); //% type specifier /  * disacard / [^\n] read except new line
		}
		else if (!is_integer(&temp))
		{
			printf("You have entered a decimal input... please try again an integer input\n\n");
			check = 1;
			scanf("%*[^\n]"); //% type specifier /  * disacard / [^\n] read except new line
		}
		else if (!is_in_range((int)temp, 1, 100))
		{
			printf("You did not enter a number between 1 and 100 ... please try again\n\n");
			check = 1;
			scanf("%*[^\n]"); //% type specifier /  * disacard / [^\n] read except new line
		}
		else
		{
			*n = (char)temp;
			scanf("%*[^\n]"); //% type specifier /  * disacard / [^\n] read except new line
			check = 0;
		}
	}
}

void print_menu()
{
	printf("\n\n--------------------------\n");
	printf("1) Print odd numbers\n");
	printf("2) Print even numbers\n");
	printf("\nPlease Enter you choice[1~2]: \n");
}

char random_number() {
	unsigned int tick;
	__asm__ __volatile__("rdtsc" : "=a" (tick) : : "%edx");
	return (tick % 100) + 1;
}

char guessing(char* r, char* g) {
	int i;
	for (i = 3; i > 0; i--)
	{
		printf("Trial no. %i (%i trial(s) remaining)\n", 4 - i, i);
		Define_Integer(g, "your guess number");
		if (*g == *r) {
			return 1;
			break;
		}
		else {
			printf("Oops! Wrong guess. Try again!\n");
		}
	}
	return 0;
}

void print_result(char* is_guessed, char* r) {
	if (*is_guessed) {
		printf("\n****************************************************\n");
		printf("*  BINGO! You guessed the right number which is %i!*\n", *r);
		printf("*                 CONGRATULATIONS!                 *\n");
		printf("****************************************************\n\n");
	}
	else {
		printf("\nHard luck! The correct number was %d. Better luck next time!\n\n", *r);
	}
}
