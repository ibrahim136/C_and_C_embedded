#include <stdio.h>
#include <math.h>
#include <stdlib.h>

char is_integer(float* temp);

void Define_Integer(int* n, char arr[]);

void Define_Float(float* n, int i);

void Define_array(float* arr, int n);

void print_array_reverse(float* arr, int n);

int main() {
	printf("This program is reversing the given array\n\n");
	int n;
	Define_Integer(&n,"the size of array");
	float* arr = (float*)malloc(n * sizeof(float));
	if (!arr) {
	printf("\nArray hasn't allocated... please try again later\n");
	return -1;
	}
	Define_array(arr,n);
	print_array_reverse(arr, n);
	
	free(arr);
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

void Define_Float(float* n, int i) {
	float temp;
	char check = 1;
	while (check) {
		printf("Please enter element no. %i (index [%i]): ",i+1,i);
		check = scanf("%f", &temp);
		if (!check) {
			printf("You have entered non-numerical input... please try again\n\n");
			check = 1;
			scanf("%*[^\n]"); //% type specifier /  * disacard / [^\n] read except new line
		}
		else
		{
			*n = temp;
			scanf("%*[^\n]"); //% type specifier /  * disacard / [^\n] read except new line
			check = 0;
		}
	}
}

void Define_array(float* arr,int n) {
	int i;
	for (i = 0; i < n; i++)
	{
		Define_Float(&arr[i], i);
	}
}

void print_array_reverse(float* arr, int n) {
	int i;
	printf("\n\n");
	for (i = n - 1; i >= 0; i--)
	{

		printf("%.2f  ", arr[i]);
	}
	printf("\n\n");
}
