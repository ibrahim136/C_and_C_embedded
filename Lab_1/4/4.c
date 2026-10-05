#include <stdio.h>
#include <math.h>

void Define_Time(int * time)
{
	float temp;
	char check = 1;
	while (check) {
		printf("Please enter the time in seconds: ");
		check = scanf("%f", &temp);
		if (!check) {
			printf("You have entered non-integer input... please try again a positive integer input\n\n");
			check = 1;
			scanf("%*[^\n]"); //% type specifier /  * disacard / [^\n] read except new line
		}
		else if (temp < 0)
		{
			printf("You have entered negative time... please try again a positive integer input\n\n");
			check = 1;
			scanf("%*[^\n]"); //% type specifier /  * disacard / [^\n] read except new line
		}
		else
		{
			check = 0;
		}
	}
	*time = (int)roundf(temp);
	if (*time != temp)
	{
		printf("Time will be rounded to %i\n", *time);
	}
}

void Time_hr_min_sec(int * time) {
	int temp; // I have used one variable here to decrease memory usage
	temp = *time / 3600;
	printf("Hours: %i\n", temp);
	*time %= 3600;
	temp = *time / 60;
	printf("Minutes: %i\n", temp);
	*time %= 60;
	printf("Seconds: %i", *time);
}

int main() {
	int time=0;
	Define_Time(&time);
	Time_hr_min_sec(&time);
}
