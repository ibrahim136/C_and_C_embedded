#include <stdio.h>

char is_integer(float* temp);

void Define_Integer(int* n, char arr[]);

void print_menu();

char is_in_range(int n, int start, int end);

void handling_end(int* end, int* start);

void handling_choice(int* choice);


void print_odd_even(int* start, int* end, int* choice);

int main() {
	printf("This program is printing odd/even numbers for a given range\n\n");
	int start, end;
	Define_Integer(&start, "start");
	handling_end(&end, &start);
	int choice;
	handling_choice(&choice);
	print_odd_even(&start, &end, &choice);
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

		else
		{
			*n = (int)temp;
			scanf("%*[^\n]"); //% type specifier /  * disacard / [^\n] read except new line
			check = 0;
		}
	}
}

void print_menu()
{
	printf("\n\n--------------------------\n");
	printf("1) Print odd numbers\n");
	printf("2) Print even numbers\n");
	printf("\nPlease Enter you choice[1~2]: \n");
}

char is_in_range(int n, int start, int end)
{
	return (n >= start && n <= end);
}

void handling_end(int* end, int* start)
{
	char valid_range = 0;
	do {
		Define_Integer(end, "end");
		if (*end >= *start) {
			valid_range = 1;
		}
		else {
			printf("Please Enter the end to be more than the start\n\n");
		}
	} while (valid_range == 0);
}

void handling_choice(int* choice)
{
	char valid_range = 0;
	do {
		print_menu();
		Define_Integer(choice, "choice");
		if (is_in_range(*choice, 1, 2)) {
			valid_range = 1;
		}
		else {
			printf("Please Enter a choice between 1 and 2\n\n");
		}
	} while (valid_range == 0);
}


void print_odd_even(int* start, int* end, int* choice)
{
	char temp = (*choice == 1) ? 1 : 0;
	int i;
	i = (*start % 2 == temp) ? *start : *start + 1;
	printf("\n---Et voila---\n\n");
	for (; i <= *end; i += 2)
	{
		printf("%i ", i);
	}
}
