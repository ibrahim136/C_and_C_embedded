#include <stdio.h>
#include <math.h>
#include <stdlib.h>

char is_integer(float* temp);

void Define_Integer(int* n, char arr[]);

void Define_Float(float* n, int i);

void Define_array(float* arr, int n);

int* freq_array(float* arr, int n);

void print_array_freq(float* arr, int* arr_freq, int n);

int main() {
	printf("This program is counting the frequency of each element of an array\n\n");
	int n;
	Define_Integer(&n,"the size of array");
	float* arr = (float*)malloc(n* sizeof(float));
	if (!arr) {
		printf("\nArray hasn't allocated... please try again later\n");
		return 0;
	}
	Define_array(arr,n);
	
	int* arr_freq = freq_array(arr, n);

	print_array_freq(arr, arr_freq, n);

	free(arr);
	free(arr_freq);
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
			printf("You have entered non-positive input... please try again a positive integer input\n\n");
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

int* freq_array(float* arr, int n)
{
	int* arr_freq = calloc(n, sizeof(int));
	if (!arr_freq) {
		printf("\nFrequency array hasn't allocated... please try again later\n");
		return NULL;
	}
	int i,j;
	for (i = 0; i < n; i++)
	{
		if (arr_freq[i] == -1) continue;
		arr_freq[i] = 1;
		for (j = i + 1; j < n; j++) {
			if (arr[i] == arr[j]) {
				arr_freq[i]++;
				arr_freq[j] = -1;
			}
		}
	}
	return arr_freq;
}

void print_array_freq(float* arr,int * arr_freq, int n)
{
	int i;
	printf("The frequency of each element of the array:\n\n");
	for (i = 0; i < n; i++)
	{
		if (arr_freq[i] != -1)
		{
			printf("%.2f occurs %i time", arr[i], arr_freq[i]);
			if (arr_freq[i] > 1) {
				printf("s");
			}
			printf("\n");
		}
	}
}