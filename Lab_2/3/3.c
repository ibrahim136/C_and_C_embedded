#include <stdio.h>
#include <math.h>

char is_integer(float* temp);

void Define_Integer(int* n, char arr[]);

void print_multiplication_table(int* n);

int main() {
	printf("This program is printing a multiplication table for a given number\n\n");
	int n;
	Define_Integer(&n, "a integer");
	print_multiplication_table(&n);
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
		else if (temp < 1) {
			printf("You have entered negative integer... please try again a positive integer\n\n");
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

void print_multiplication_table(int* n)
{
	int i;
	printf("\nEt Voila\n\n");
	for (i = 1; i <= 10; i++) {
		printf("%i x %i = %i\n", *n, i, *n * i);
	}
}
