#include <stdio.h>
#include <math.h>

char is_integer(float *temp)
{
	return *temp == (int)*temp;
}

void Define_Month(int * m)
{
	float temp;
	char check = 1;
	while (check) {
		printf("Please enter the number of the month [1~12]: ");
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
		else if (temp < 1 || temp > 12)
		{
			printf("You have entered a number out of range... please try again an integer input between 1 and 12\n\n");
			check = 1;
			scanf("%*[^\n]"); //% type specifier /  * disacard / [^\n] read except new line
		}
		else
		{
			*m = (int)temp;
			check = 0;
		}
	}
}

void Print_Month(int *m) {
	printf("------");
	switch (*m) {
	case 1:
		printf("January");
		break;
	case 2:
		printf("February");
		break;
	case 3:
		printf("March");
		break;
	case 4:
		printf("April");
		break;
	case 5:
		printf("May");
		break;
	case 6:
		printf("June");
		break;
	case 7:
		printf("July");
		break;
	case 8:
		printf("August");
		break;
	case 9:
		printf("September");
		break;
	case 10:
		printf("October");
		break;
	case 11:
		printf("November");
		break;
	case 12:
		printf("December");
		break;
	}
	printf("------\n");
}

int main() {
	int m;
	Define_Month(&m);
	Print_Month(&m);
}
