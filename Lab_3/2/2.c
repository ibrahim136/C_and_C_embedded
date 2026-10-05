#include <stdio.h>
#include <math.h>
#include <stdlib.h>

char is_integer(float* temp);

void Define_Integer(int* n, char arr[]);

void Define_Float(float* n, int i);

void Define_array(float* arr, int n);

void print_array_reverse(float* arr, int n);

void copying_arr1_into_arr2(float* arr1, int n1, float* arr2, int n2);

void print_array(float* arr, int n);

int main() {
	printf("This program is copying array no.1 into array no.2\n\n");
	int n1,n2;

	Define_Integer(&n1,"the size of array no.1");
	float* arr1 = (float*)malloc(n1 * sizeof(float));
	if (!arr1) {
	printf("\nArray no.1 hasn't allocated... please try again later\n");
	return -1;
	}
	Define_array(arr1,n1);
	
	Define_Integer(&n2, "the size of array no.2");
	float* arr2 = (float*)malloc(n2 * sizeof(float));
	if (!arr2) {
	printf("\nArray no.2 hasn't allocated... please try again later\n");
	return -1;
	}
	Define_array(arr2, n2);


	copying_arr1_into_arr2(arr1, n1, arr2, n2);

	print_array(arr1, n1);

	print_array(arr2, n2);
	
	free(arr1);
	free(arr2);

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

void copying_arr1_into_arr2(float* arr1, int n1, float* arr2, int n2)
{
	if (n1 > n2) {
		printf("Size of array no.1 more than size of array no.2\n");
		printf("The first %i elements of array no.1 will be copied into array no.2\n\n",n2);
		int i;
		for (i = 0; i < n2; i++)
		{
			arr2[i] = arr1[i];
		}
	}
	else if (n1 < n2) {
		printf("Size of array no.1 less than than size of array no.2\n");
		printf("Elements of array no.1 will be copied into the first %i elements of array no.2\n\n", n1);
		int i;
		for (i = 0; i < n1; i++)
		{
			arr2[i] = arr1[i];
		}
	}
	else
	{
		printf("Size of array no.1 equals size of array no.2\n");
		printf("Elements of array no.1 will be copied into array no.2\n\n");
		int i;
		for (i = 0; i < n2; i++)
		{
			arr2[i] = arr1[i];
		}
	}
}

void print_array(float* arr, int n ) {
	int i;
	static int cnt = 1;
	printf("Array no. %i: ",cnt);
	for (i = 0; i < n; i++)
	{
		printf("%.2f  ", arr[i]);
	}
	printf("\n\n");
	cnt++;
}