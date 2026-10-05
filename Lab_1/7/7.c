#include <stdio.h>
#include <math.h>

char is_integer(float *temp)
{
	return *temp == (int)*temp;
}

void Define_Number(int * n)
{
	float temp;
	char check = 1;
	while (check) {
		printf("Please enter a number to check divisibility [1~100]: ");
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
		else if (temp < 1 || temp > 100)
		{
			printf("You have entered a number out of range... please try again an integer input between 1 and 100\n\n");
			check = 1;
			scanf("%*[^\n]"); //% type specifier /  * disacard / [^\n] read except new line
		}
		else
		{
			*n = (int)temp;
			check = 0;
		}
	}
}

void print_divisible_numbers(int* n)
{
	int i;
	for (i = 1; i <= 100; i++)
	{
		if (i % *n == 0)
		{
			printf("%i ", i);
		}
	}
}

int main() {
	int n;
	Define_Number(&n);
	print_divisible_numbers(&n);
}
