#include <stdio.h>
#include <math.h>

typedef struct Point {
	float x;
	float y;
}Point;

void Define_Coordinate(float* coordinate, char coordinate_letter, char cnt)
{
	char check = 1;
	while (check) {
		printf("Please Enter the %c coordinate of point %i: ", coordinate_letter, cnt);
		check = scanf("%f", coordinate);
		if (!check) {
			printf("You have entered non-numerical input... please try again a numerical input\n\n");
			check = 1;
			scanf("%*[^\n]"); //% type specifier /  * disacard / [^\n] read except new line
		}
		else
		{
			check = 0;
		}
	}
}

void Define_Point(Point * p) {
	static char cnt = 1;
	Define_Coordinate(&p->x, 'x', cnt);
	Define_Coordinate(&p->y, 'y', cnt);
	cnt++;
}

float Calculate_Distance(Point p1, Point p2) {
	return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

int main() {
	Point P[2];
	Define_Point(&P[0]);
	Define_Point(&P[1]);
	printf("\nPoint 1 = (%.2f,%.2f)", P[0].x, P[0].y);
	printf("\nPoint 2 = (%.2f,%.2f)\n", P[1].x, P[1].y);
	float Distance = Calculate_Distance(P[0], P[1]);
	printf("The Distance Between Point 1 & 2 = %.2f", Distance);
}
