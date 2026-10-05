#include <stdio.h>
#include <math.h>

char is_integer(float *temp)
{
	return *temp == (int)*temp;
}

void Define_Integer(int * n)
{
	float temp;
	static int cnt = 1;
	char check = 1;
	while (check) {
		printf("Please enter the value no. %i: ",cnt);
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
		else if ((int)temp ==0)
		{
			printf("You have entered a zero input... please try again a non-zero integer input\n\n");
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
	cnt++;
}

char is_muliplied(int* x, int* y)
{
	return (*x % *y == 0 || *y % *x == 0);
}

int main() {
	int x, y;
	Define_Integer(&x);
	Define_Integer(&y);
	if (is_muliplied(&x, &y))
	{
		printf("\n\nMultiplied\n");
	}
	else {
		printf("\n\nNot Multiplied\n");
	}
}
