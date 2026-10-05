#include <stdio.h>
#include <math.h>

char is_integer(float* temp);

void Define_Integer(int* n, char arr[]);

int get_root_int(int* n);

void print_prime(int* r);


int main() {
	printf("This program is printing prime numbers for a given range\n\n");
	int r;
	Define_Integer(&r, "range");
	print_prime(&r);
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

int get_root_int(int* n) { //geting root of number
	int temp = 1;
	while (temp * temp <= *n) {
		temp++;
	}
	return --temp;

}

void print_prime(int* r) {
	int i, j;
	printf("\nEt Voila\n\n");
	for (i = 2; i <= *r; i++)
	{
		char is_prime = 1;
		int root = get_root_int(&i);
		for (j = 2; j <= root; j++) { //checking divisibility until root of no. (shortest way)
			if (i % j == 0) {
				is_prime = 0;
				break;
			}
		}
		if (is_prime) {
			printf("%i ", i);
		}
	}
	printf("\n");
}
