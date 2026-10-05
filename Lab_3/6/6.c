#include <stdio.h>
#include <math.h>
#include <stdlib.h>

char is_integer(float* temp);

void Define_Integer(int* n, char arr[]);

void Define_Float(float* n, int i);

void Define_array(float* arr, int n);

void get_min_max(float* arr, int n, float* min_max);

void print_min_max(float* min_max);

int main() {
	printf("This program finds the maximum and minimum element in an array.\n\n");
	int n;
	Define_Integer(&n,"the size of array");
	float* arr = (float*)malloc(n* sizeof(float));
	if (!arr) {
		printf("\nArray hasn't allocated... please try again later\n");
		return 0;
	}
	Define_array(arr,n);
	
	float min_max[4];
	get_min_max(arr, n, min_max);
	
	print_min_max(min_max);

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
	printf("\n\n");
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
	printf("\n\n");
}

void get_min_max(float* arr, int n, float* min_max)
{
	min_max[0] = arr[0];
	min_max[1] = 0;
	min_max[2] = arr[0];
	min_max[3] = 0;
	int i;
	for (i = 1; i < n; i++)
	{
		if (min_max[0] > arr[i])
		{
			min_max[0] = arr[i];
			min_max[1] = i;
		}
		if (min_max[2] < arr[i])
		{
			min_max[2] = arr[i];
			min_max[3] = i;
		}
	}
}

void print_min_max(float* min_max)
{
	printf("\n\nThe minimum element in the array is %.2f with index of %i (element no. %i)\n\n", min_max[0],(int) min_max[1], (int)min_max[1] + 1);
	printf("\n\nThe maximum element in the array is %.2f with index of %i (element no. %i)\n\n", min_max[2], (int)min_max[3], (int)min_max[3] + 1);

}

