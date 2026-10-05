#include <stdio.h>
#include <math.h>

char is_integer(float* temp);

void Define_Integer(int* n, char arr[]);

void print_pyramid(int* rows);


int main() {
	printf("This program is printing a pyramid for a given number of rows\n\n");
	int rows;
	Define_Integer(&rows, "rows");
	print_pyramid(&rows);
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
		printf("Please enter the size of the %s: ", arr);
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
			printf("You have entered integer less than 1... please try again an integer more than 1\n\n");
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

void print_pyramid(int* rows) {
	int i, j;
	int spaces = *rows - 1;
	printf("\nEt Voila\n\n");
	for (i = 0; i < *rows; i++)
	{
		for (j = 1; j <= spaces; j++)
		{
			printf(" ");
		}
		for (j = 1; j <= 1 + i * 2; j++) {
			printf("*");
		}
		spaces--;
		printf("\n");
	}
}
