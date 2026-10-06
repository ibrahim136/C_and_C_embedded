#include <stdio.h>
#include <math.h>
#include <stdlib.h>

char is_integer(double* temp);

void Define_Integer(long long* n, char arr[]);

void dec_to_bin(long long d, char b[]);

void twos_complement(char b[]);

void print_bin(char b[]);

char is_negative(long long d);

int main() {
	printf("This program converts a decimal number to a binary number.\n\n");
	long long d;
	Define_Integer(&d,"a decimal number");
	
	char b[64] = { 0 };

	dec_to_bin(d, b);

	printf("The decimal value: %lld\n",d);
	
	print_bin(b);
}

char is_integer(double* temp)
{
	return *temp == (long long)*temp;
}

void Define_Integer(long long* n, char arr[])
{
	double temp;
	char check = 1;
	while (check) {
		printf("Please enter %s: ", arr);
		check = scanf("%lf", &temp);
		if (!check || !is_integer(&temp)) {
			printf("You have entered non-integer input... please try again an integer input\n\n");
			check = 1;
			scanf("%*[^\n]"); //% type specifier /  * disacard / [^\n] read except new line
		}
		else
		{
			*n = (long long)temp;
			scanf("%*[^\n]"); //% type specifier /  * disacard / [^\n] read except new line
			check = 0;
		}
	}
	printf("\n\n");
}

void dec_to_bin(long long d,char b []) {
	int i = 0;
	char is_neg = is_negative(d);
	if (is_neg) {
		d *= -1;
	}
	while (d != 0)
	{
		b[i] = d % 2;
		d /= 2;
		i++;
	}
	if (is_neg) {
		twos_complement(b);
	}
}

void twos_complement(char b[])
{
	int i = 0;
	for (i = 0; i < 64; i++) { //ones_complement
		if (b[i]) {
			b[i] = 0;
		}
		else {
			b[i] = 1;
		}
	}
	for (i = 0; i < 64; i++) { //twos_complement
		if (b[i]) {
			b[i] = 0;
		}
		else {
			b[i] = 1;
			break;
		}
	}

}

void print_bin(char b[])
{
	printf("The binary value: ");
	int i;
	char start = 0;
	for (i = 63; i >= 0; i--)
	{
		if (!start) {
			if (b[i] == 1) {
				start = 1;
				printf("%i", b[i]);
			}
		}
		else {
			printf("%i", b[i]);
		}
	}
	if (start == 0) {
		printf("0");
	}
	printf("\n\n");
}

char is_negative(long long d)
{
	return d<0;
}



