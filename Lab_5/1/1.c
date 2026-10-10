#include <stdio.h>
#include <stdlib.h>

typedef struct Count {
	int students;
	int exams;
}count;

typedef struct Student{
	int* exams;
	int total_marks;
	char* name;
	char age;
	char id;
}student;

count Enter_Students_Exams_count();

void Define_Integer(int* n, char arr[]);

char is_integer(float* temp);

char* enter_name();

char is_valid_name_check(char x);

student* enter_students_data(count c);

float get_avg_total_marks_per_student(student* s,count c);

void print_marks(student* s, count c);
void print_avg(student* s, count c);
void print_top_3(student* s, count c);
void print_in_order(student * s, count c);

int get_max_ch_name(student* s,count c);

int get_string_len(char* x);

void arrange_top_3(student* s, count c);

int main(void) {
	count counts = Enter_Students_Exams_count();
	student* students = enter_students_data(counts);
	print_marks(students,counts);
	print_avg(students,counts);
	if (counts.students > 2) {
		print_top_3(students, counts);
	}
	else {
		print_in_order(students, counts);
	}
	free(students);
}

count Enter_Students_Exams_count() {
	count c;
	while (1) {
		Define_Integer(&c.students, "Please enter the number of students you have:");
		if (c.students < 1) {
			printf("Please enter a positive integer for the number of students\n");
			continue;
		}
		break;
	}
	while (1) {
		Define_Integer(&c.exams, "Please enter the number of exams they have taken:");
		if (c.exams < 1) {
			printf("Please enter a positive integer for the number of exams\n");
			continue;
		}
		break;
	}
	
	return c;
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
		printf("%s ", arr);
		check = scanf("%f", &temp);
		if (!check) {
			printf("You have entered non-integer input... please try again a positive or zero integer input\n\n");
			check = 1;
			scanf("%*[^\n]"); //% type specifier /  * disacard / [^\n] read except new line
		}
		else if (!is_integer(&temp))
		{
			printf("You have entered a decimal input... please try again a positive or zero integer input\n\n");
			check = 1;
			scanf("%*[^\n]"); //% type specifier /  * disacard / [^\n] read except new line
		}
		else if (temp < 0) {
			printf("You have entered negative input... please try again a positive or zero integer input\n\n");
			check = 1;
			scanf("%*[^\n]"); //% type specifier /  * disacard / [^\n] read except new line
		}
		else
		{
			*n = (int)temp;
			scanf("%*[^\n]"); //% type specifier /  * disacard / [^\n] read except new line
			check = 0;
			getchar();
		}
	}
	printf("\n");
}

char* enter_name()
{
	char* temp = (char*)malloc(sizeof(char));
	char is_valid_name = 0;
	while (!is_valid_name) {
		printf("Student Name: ");
		int character;
		character = getchar();
		int cnt = 1;
		
		if (!temp) {
			printf("string has not been allocated");
			return NULL;
		}
		temp[0] = '\0'; //puting null to handle the string if empty

		char* temp_temp;
		while (character != '\n') {
			is_valid_name = is_valid_name_check(character);
			if (!is_valid_name) {
				while (character != '\n') {
					character = getchar();
				}
				break;
			}
			temp_temp = (char*)realloc(temp, ++cnt * sizeof(char));
			if (!temp_temp) {
				printf("string has not been allocated");
				free(temp);
				return NULL;
			}
			temp_temp[cnt - 2] = (char)character;
			temp_temp[cnt - 1] = '\0';
			temp = temp_temp;
			character = getchar();
		}
		if (!is_valid_name) {
			printf("Please Enter a Valid name without any numbers or these seperators:\n(tab, , , . , ; , : , ! , ? , _ , - , ' , { , } , [ , ] , ( , ) , / , \\)\n\n");
			continue;
		}
	}
	return temp;
}

char is_valid_name_check(char x) {
	switch (x) {
	case '\t':
	case ',':
	case '.':
	case ';':
	case ':':
	case '!':
	case '?':
	case '_':
	case '-':
	case '\'':
	case '{':
	case '}':
	case '[':
	case ']':
	case '(':
	case ')':
	case '\\':
	case '/':
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
		return 0;
	default:
		return 1;
	}
}

student* enter_students_data(count c) {
	printf("------Students Data------\n\n");
	student* s = (student*)malloc(c.students * sizeof(student));
	if (!s) {
		printf("Students has not been allocated");
		return NULL;
	}
	int i, j;
	for (i = 0; i < c.students; i++)
	{
		s[i].id = i+1;
		printf("Please Enter the data of student no. %i\n", i + 1);
		s[i].name = enter_name();
		int temp_age;
		Define_Integer(&temp_age, "Student Age: ");
		s[i].age = (char)temp_age;
		printf("\n\n------Student no. %i (%s) marks (out of 100)------\n\n",i+1,s[i].name);
		s[i].exams = (int*)malloc(c.exams * sizeof(int));
		if (!s[i].exams) {
			printf("Exams has not been allocated");
			return NULL;
		}
		s[i].total_marks = 0;
		for (j = 0; j < c.exams; j++) {
			while (1) {
				char arr[15];
				int ii=0;
				while (ii < 9) {
					arr[ii] = "Exam no. "[ii];
					ii++;
				}
				arr[ii] = j + 48 +1;
				arr[ii + 1] = ':';
				arr[ii + 2] = ' ';
				arr[ii + 3] = '\0';
				Define_Integer(&s[i].exams[j], arr);
				if (s[i].exams[j] > 100)
				{
					printf("Please Enter a value between 0 and 100\n\n");
					continue;
				}
				s[i].total_marks += s[i].exams[j];
				break;
			}
		}
		printf("\n");
	}
	return s;
}

float get_avg_total_marks_per_student(student* s, count c) {
	float ret=0;
	int i;
	for (i = 0; i < c.students; i++) {
		ret += s[i].total_marks;
	}
	return ret;
}

void print_marks(student* s, count c) {
	printf("========================== Student Records =======================\n");
	printf("ID   Name");
	int max_name = get_max_ch_name(s, c);
	int i;
	for (i = 1; i < max_name; i++) {
		printf(" ");
	}
		
	printf("Age   Total Marks\n");
	printf("----------------------------------------------------------------\n");
	for (i = 0; i < c.students; i++)
	{
		printf("%i    %s",s[i].id, s[i].name);
		int spaces = max_name - get_string_len(s[i].name) + 4;
		int j;
		for (j = 0; j < spaces; j++) {
			printf(" ");
		}
		printf("%i         %i\n",s[i].age, s[i].total_marks);
	}
	printf("----------------------------------------------------------------\n\n");
	printf("========================== Exams Records =========================\n");
	printf("ID    Name");
	for (i = 1; i < max_name-1; i++) {
		printf(" ");
	}
	for (i = 0; i < c.exams; i++) {
		printf("Exam %i    ", i+1);
	}
	printf("\n----------------------------------------------------------------\n");
	for (i = 0; i < c.students; i++)
	{
		printf("%i     %s", s[i].id, s[i].name);
		int spaces = max_name - get_string_len(s[i].name) + 4;
		int j;
		for (j = 1; j < spaces; j++) {
			printf(" ");
		}
		for (j = 0; j < c.exams; j++) {
			printf("  %i      ", s[i].exams[j]);
		}
		printf("\n");
	}
	printf("\n----------------------------------------------------------------\n\n");
}

int get_max_ch_name(student* s,count c) {
	int i = 0;
	int max = get_string_len(s[i].name);
	for (i=1; i < c.students; i++) {
		int temp = get_string_len(s[i].name);
		if (temp > max) {
			max = temp; 
		}
	}
	return max;
}

int get_string_len(char* x) {
	int cnt =0;
	while (x[cnt] != '\0') {
		cnt++;
	}
	return ++cnt;
}

void arrange_top_3(student *s,count c) {
	int i, j;
	int limit = c.students > 2 ? c.students - 4 : 0;
	for (i = c.students-1; i >= limit; i--) {
		char swap = 0;
		for (j = i - 1; j >= 0; j--) {
			if (s[i].total_marks > s[j].total_marks)
			{
				student temp;
				temp = s[i];
				s[i] = s[j];
				s[j] = temp;
				swap = 1;
			}
		}
		if (!swap) {
			break;
		}
	}
}

void print_avg(student* s, count c) {
	double sum =0;
	int i;
	for (i = 0; i < c.students; i++)
	{
		sum += s[i].total_marks;
	}
	double avg = sum / c.students;
	arrange_top_3(s, c);
	printf("Class Average Marks: %.2f\n", avg);
	printf("Highest Mark: %i (Student: %s)\n\n", s[0].total_marks, s[0].name);
}

void print_top_3(student* s, count c) {
	arrange_top_3(s, c);
	printf("------------------------- Top 3 Ranked ---------------------------\n");
	printf("Rank   Name");
	int max_name = get_max_ch_name(s, c);
	int i;
	for (i = 1; i < max_name; i++) {
		printf(" ");
	}

	printf("Age   Total Marks\n");
	printf("----------------------------------------------------------------\n");
	for (i = 0; i < 3; i++)
	{
		printf("#%i     %s", i+1, s[i].name);
		int spaces = max_name - get_string_len(s[i].name) + 4;
		int j;
		for (j = 0; j < spaces; j++) {
			printf(" ");
		}
		printf("%i         %i\n", s[i].age, s[i].total_marks);
	}
	printf("----------------------------------------------------------------\n\n");
	
}

void print_in_order(student* s, count c) {
	arrange_top_3(s, c);
	printf("----------------------- Arranged Ranked ------------------------\n");
	printf("Rank   Name");
	int max_name = get_max_ch_name(s, c);
	int i;
	for (i = 1; i < max_name; i++) {
		printf(" ");
	}

	printf("Age   Total Marks\n");
	printf("----------------------------------------------------------------\n");
	for (i = 0; i < c.students; i++)
	{
		printf("#%i     %s", i + 1, s[i].name);
		int spaces = max_name - get_string_len(s[i].name) + 4;
		int j;
		for (j = 0; j < spaces; j++) {
			printf(" ");
		}
		printf("%i         %i\n", s[i].age, s[i].total_marks);
	}
	printf("----------------------------------------------------------------\n\n");
}