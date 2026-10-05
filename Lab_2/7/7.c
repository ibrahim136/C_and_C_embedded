#include <stdio.h>
#include <math.h>

char is_integer(float* temp);

void Define_Integer(int* n, char arr[]);


char leap_or_not(int* y);

void print_leap_or_not(int* y);

int main() {
	printf("This program is detecting the given year is leap or not\n\n");
	int y;
	Define_Integer(&y, "year number");
	print_leap_or_not(&y);
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
		printf("Please enter the %s: ", arr);
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
			printf("You have entered non-positive integer... please try again a positive integer\n\n");
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


char leap_or_not(int* y) {
	if (*y % 4 == 0) {
		if (*y % 100 == 0) {
			if (*y % 400 == 0) {
				return 1;
			}
			else {
				return 0;
			}
		}
		else {
			return 1;
		}
	}
	else {
		return 0;
	}
}

void print_leap_or_not(int* y) {
	char is_leap = leap_or_not(y);
	printf("%i Year is ", *y);
	if (!is_leap) {
		printf("NOT ");
	}
	printf("a leap year");

}
