#include <stdio.h>
#include <stdlib.h>

typedef struct Complex {
	double real;
	double img;
}complex;

char is_integer(float* temp);
void Define_Integer(int* n, char arr[]);

char* enter_string(int i);

char is_valid_expression_check(char character);

complex get_complex_from_string(char* string);

void print_add(complex* c, int count);
void print_multi(complex* c_no_s, int count);

char is_number(char x);
char is_plus_or_minus(char x);
char is_i(char x);
char is_negative(char x);

double set_number_with_sign(double temp, char sign);
char* remove_spaces(char* s);

complex read_complex(int i);
complex* reading_n_complex(int* i);

void print(complex* c_no_s, int count);

int main(void) {
	int count;
	complex* c_no_s = reading_n_complex(&count);
	print(c_no_s, count);
	print_add(c_no_s, count);
	print_multi(c_no_s, count);
	free(c_no_s);
}

char* enter_string(int i) {
	char* temp = (char*)malloc(sizeof(char));
	char is_valid = 0;
	while (!is_valid) {
		printf("Please enter complex number no. %i: ", i);
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
			is_valid = is_valid_expression_check(character);
			if (!is_valid) {
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
		if (!is_valid) {
			printf("Please Enter a valid complex number contains only of numbers , '+' , '-' , or 'i' \n");
			continue;
		}
	}
	return temp;
}

char is_valid_expression_check(char character) {
	if (is_number(character) || is_plus_or_minus(character) || is_i(character) || character == ' ' || character == '.') {
		return 1;
	}
	else {
		return 0;
	}
}

double set_number_with_sign(double temp, char sign) {
	if (sign == 1) {
		return -1 * temp;
	}
	return temp;
}

complex get_complex_from_string(char* string) {
	int i = 0;
	double temp = 0;
	complex c_no = { 0,0 };
	char is_real = 1;
	char in_decimal = 0;
	double dec_div = 1.0;
	char* string_no_spaces = remove_spaces(string);
	string = string_no_spaces;
	if (!string) {
		return c_no;
	}
	char nu_check = 0;
	char is_negative_flag = is_negative(string[i]);
	while (string[i] != '\0') {

		if (is_plus_or_minus(string[i])) {
			is_negative_flag = is_negative(string[i]);
		}
		else if (string[i] == '.') { 
			in_decimal = 1;
		}
		else if (string[i] != 'i') {
			if (in_decimal) {
				dec_div *= 10.0;
				temp = temp + (string[i] - '0') / dec_div;
			}
			else {
				temp = temp * 10 + (string[i] - '0');
			}
			nu_check = 1;
		}
		if (string[i] == 'i') {
			is_real = 0;
			if (!nu_check) {
				temp = 1;
			}
		}
		if (is_plus_or_minus(string[i + 1]) || string[i + 1] == '\0') {
			if (is_real) {
				c_no.real += set_number_with_sign(temp, is_negative_flag);
				temp = 0;
				nu_check = 0;
			}
			else {
				c_no.img += set_number_with_sign(temp, is_negative_flag);
				is_real = 1;
				
			}
			temp = 0;
			nu_check = 0;
			in_decimal = 0;
			dec_div = 1.0;
		}
		i++;
	}
	free(string_no_spaces);
	return c_no;
}

char is_number(char x) {
	if (x >= '0' && x <= '9') {
		return 1;
	}
	return 0;
}
char is_plus_or_minus(char x) {
	if (x == '+' || x == '-') {
		return 1;
	}
	return 0;
}
char is_i(char x) {
	if (x == 'i') {
		return 1;
	}
	return 0;
}

char is_negative(char x) {
	if (x == '-') {
		return 1;
	}
	else {
		return 0;
	}
}



void Define_Integer(int* n, char arr[])
{
	float temp;
	char check = 1;
	while (check) {
		printf("%s", arr);
		check = scanf("%f", &temp);
		if (!check) {
			printf("You have entered non-numerical input... please try again an integer input\n\n");
			check = 1;
			scanf("%*[^\n]"); //% type specifier /  * disacard / [^\n] read except new line
		}
		else if (!is_integer(&temp))
		{
			printf("You have entered a decimal input... please try again an integer input\n\n");
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
			getchar();
		}
	}
}

char is_integer(float* temp)
{
	return *temp == (int)*temp;
}

complex read_complex(int i) {
	char* s = enter_string(i);
	complex ret = get_complex_from_string(s);
	free(s);
	return ret;
}

complex* reading_n_complex(int* i) {
	Define_Integer(i, "Enter the number of Complex numbers will be entered: ");
	complex* c_no_s = (complex*)malloc(*i * sizeof(complex));
	if (!c_no_s) {
		printf("Complex numbers have not been allocated");
		return NULL;
	}
	int j;
	for (j = 0; j < *i; j++)
	{
		c_no_s[j] = read_complex(j + 1);
	}
	return c_no_s;
}

void print(complex* c_no_s, int count)
{
	printf("\n\nComplex Numbers have been entered: \n\n");
	int i;
	for (i = 0; i < count; i++) {
		if (c_no_s[i].real && c_no_s[i].img) {
			if (c_no_s[i].img > 0) {
				if (c_no_s[i].img == 1) {
					printf("Complex no. %i = %.2lf + i", i + 1, c_no_s[i].real);
				}
				else {
					printf("Complex no. %i = %.2lf + %.2lf i", i + 1, c_no_s[i].real, c_no_s[i].img);
				}
			}
			else {
				if (c_no_s[i].img == -1) {
					printf("Complex no. %i = %.2lf - i", i + 1, c_no_s[i].real);
				}
				else {
					printf("Complex no. %i = %.2lf - %.2lf i", i + 1, c_no_s[i].real, c_no_s[i].img * -1);
				}
			}
		}
		else if (c_no_s[i].real) {
			printf("Complex no. %i = %.2lf", i + 1, c_no_s[i].real);
		}
		else if (c_no_s[i].img) {
			if (c_no_s[i].img > 0) {
				if (c_no_s[i].img == 1) {
					printf("Complex no. %i = i", i + 1);
				}
				else {
					printf("Complex no. %i = %.2lf i", i + 1, c_no_s[i].img);
				}
			}
			else {
				if (c_no_s[i].img == -1) {
					printf("Complex no. %i = -i", i + 1);
				}
				else {
					printf("Complex no. %i = %.2lf i", i + 1, c_no_s[i].img);
				}
			}
		}
		else {
			printf("Complex no. %i = 0", i + 1);
		}
		printf("\n");
	}
}

void print_add(complex* c_no_s, int count)
{
	int i;
	complex c = { 0,0 };
	for (i = 0; i < count; i++)
	{
		c.real += c_no_s[i].real;
		c.img += c_no_s[i].img;
	}
	printf("\n\nTheir Addition : ");
	if (c.real && c.img) {
		if (c.img > 0) {
			if (c.img == 1) {
				printf("%.2lf + i", c.real);
			}
			else {
				printf("%.2lf + %.2lf i", c.real, c.img);
			}
		}
		else {
			if (c.img == -1) {
				printf("%.2lf - i", c.real);
			}
			else {
				printf("%.2lf - %.2lf i", c.real, c.img * -1);
			}
		}
	}
	else if (c.real) {
		printf("%.2lf", c.real);
	}
	else if (c.img) {
		printf("%.2lf i", c.img);
	}
	else {
		printf("0");
	}
	printf("\n");
}

char* remove_spaces(char* s) {
	int i = 0;
	int cnt = 0;
	while (s[i] != '\0')
	{
		if (s[i] != ' ') {
			cnt++;
		}
		i++;
	}
	cnt++;
	char* temp = (char*)malloc(cnt * sizeof(char));
	if (temp == NULL) {
		printf("String without spaces has not been allocated");
		return NULL;
	}
	i = 0;
	int j = 0;
	while (s[i] != '\0') {
		if (s[i] != ' ') {
			temp[j++] = s[i];
		}
		i++;
	}
	temp[cnt - 1] = '\0';
	return temp;
}

void print_multi(complex* c_no_s, int count)
{
	int i;
	complex c = { 1,0 };
	for (i = 0; i < count; i++)
	{
		double temp = c.real;
		c.real = (c.real * c_no_s[i].real) - (c.img * c_no_s[i].img);
		c.img = (temp * c_no_s[i].img) + (c.img * c_no_s[i].real);
	}
	printf("\n\nTheir Multiplication : ");
	if (c.real && c.img) {
		if (c.img > 0) {
			if (c.img == 1) {
				printf("%.2lf + i", c.real);
			}
			else {
				printf("%.2lf + %.2lf i", c.real, c.img);
			}
		}
		else {
			if (c.img == -1) {
				printf("%.2lf - i", c.real);
			}
			else {
				printf("%.2lf - %.2lf i", c.real, c.img * -1);
			}
		}
	}
	else if (c.real) {
		printf("%.2lf", c.real);
	}
	else if (c.img) {
		printf("%.2lf i", c.img);
	}
	else {
		printf("0");
	}
	printf("\n");
}
