#include <stdio.h>
#include <math.h>

char is_integer(float* temp);

void Define_Integer(int* n, char arr[]);

void print_right_triangle(int* b, int* h);


int main() {
	printf("This program is printing right angle triangle for a given base and height\n\n");
	int b, h;
	Define_Integer(&b, "base");
	Define_Integer(&h, "height");
	print_right_triangle(&b, &h);
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

void print_right_triangle(int* b, int* h) {
	int i, j;
	printf("\nEt Voila\n\n");
	for (i = 1; i <= *h; i++)
	{
		int ast = i * *b / *h;
		if (ast == 0) ast = 1;
		for (j = 1; j <= ast; j++)
		{
			printf("*");
		}
		printf("\n");
	}
}
