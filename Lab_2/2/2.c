#define __USE_MINGW_ANSI_STDIO 1 // makes compiler printf to support 80-bit 'long double' (%Lf) properly on Windows
#include <stdio.h>

char is_integer(float* temp);

void Define_Integer(int* n, char arr[]);

long double factorial(int* n);

int main() {
	printf("This program is Factorial for a given number\n\n");
	int n;
	Define_Integer(&n, "a positive integer");
	long double result = factorial(&n);
	// printing to be user friendly for proper reading of result
	if (n <= 20) {
		printf("The result is: %.0Lf", result);
	}
	else {
		printf("The result is: %.4Le", result);
	}
}


char is_integer(float* temp)
{
	return *temp == (int)*temp;
}

void Define_Integer(int* n, char arr[])
{
	float temp;
	char check = 1;
	while (check) {
		printf("Please enter %s: ", arr);
		check = scanf("%f", &temp);
		if (!check) {
			printf("You have entered non-integer input... please try again a positive integer input\n\n");
			check = 1;
			scanf("%*[^\n]"); //% type specifier /  * disacard / [^\n] read except new line
		}
		else if (!is_integer(&temp))
		{
			printf("You have entered a decimal input... please try again a positive integer input\n\n");
			check = 1;
			scanf("%*[^\n]"); //% type specifier /  * disacard / [^\n] read except new line
		}
		else if (temp < 0) {
			printf("You have entered a negative input... please try again a positive integer input\n\n");
			check = 1;
			scanf("%*[^\n]"); //% type specifier /  * disacard / [^\n] read except new line
		}
		else
		{
			*n = (int)temp;
			scanf("%*[^\n]"); //% type specifier /  * disacard / [^\n] read except new line
			check = 0;
		}
	}
}

long double factorial(int* n) // iterative way is more memory efficient than recursive one
{
	long double result = 1;
	if (*n <= 1) {
		return result;
	}
	int i;
	for (i = 2; i <= *n; i++) {
		result *= i;
	}
	return result;
}
