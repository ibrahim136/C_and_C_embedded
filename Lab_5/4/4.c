#include <stdio.h>
#include <stdlib.h>

typedef enum Department {
	HR,IT,Finance,Engineering,department_count
}dep;

typedef enum Type {
	Full_Time,Part_Time,Intern,type_count
}type;

typedef struct Employee {
	dep d;
	type t;
	int id;
	union Compensation {
		double monthly_salary;
		double hourly_rate;
	};
	char* name;

}emp;

void print_employee(emp** emps, int index);

void Employee_Management_System();
char main_menu();
int menu_filter();
int menu_filter_department();
int menu_filter_type();

void Define_Integer(int* n, char arr[]);
void Define_double(double* n, char* arr);

char is_integer(float* temp);
void unduplicated_id_enter(emp ** emps,int *emp_count);
dep Define_Deparment();
type Define_Type();
void Define_Salary(type* t,emp * e);

char* return_department_string(dep d);
char* return_type_string(type t);

char* enter_name(char* arr);
char is_valid_name_check(char x);
int Search_by_ID(emp** emps, int* emp_count, int id);

void Add_Employee(emp** emps, int* emp_count);
void Remove_Employee(emp** emps, int* emp_count);
void Search_emp_by_ID(emp** emps, int* emp_count);
void Filter(emp** emps, int* emp_count);
void Calculate_Total_Payroll(emp** emps, int* emp_count);

void print_all_emp(emp** emps, int* emp_count);

int main(void) {
	Employee_Management_System();
}

void Employee_Management_System() {
	int choice;
	int emp_count = 0;
	emp* emps = NULL;
	do {
		choice = main_menu();
		switch (choice)
		{
		case 1:
			Add_Employee(&emps, &emp_count);
			break;
		case 2:
			Remove_Employee(&emps, &emp_count);
			break;
		case 3:
			Search_emp_by_ID(&emps, &emp_count);
			break;
		case 4:
			Filter(&emps, &emp_count);
			break;
		case 5:
			Calculate_Total_Payroll(&emps, &emp_count);
			break;
		case 6:
			print_all_emp(&emps, &emp_count);
			break;
		case 7: {
					int i;
					for (i = 0; i < emp_count; i++) {
						free(emps[i].name);
					}
					free(emps);
					emps = NULL;
					break;
				}
		}
	} while (choice != 7);
}

char main_menu() {
	int choice;
	do
	{
		printf("======= Employee Management System =======\n\n");
		printf("1. Add Employee\n");
		printf("2. Remove Employee\n");
		printf("3. Search Employee by ID\n");
		printf("4. Filter Employees (Department / Type)\n");
		printf("5. Calculate Total Payroll\n");
		printf("6. Display All Employees\n");
		printf("7. Exit\n\n");
		Define_Integer(&choice, "Enter your choice: ");
		if (choice > 7 || choice < 1) {
			printf("Please enter a choice in the valid range (1~7)\n\n");
		}
	} while (choice > 7 || choice < 1);
	return choice;
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
			getchar();
		}
		else if (!is_integer(&temp))
		{
			printf("You have entered a decimal input... please try again a positive or zero integer input\n\n");
			check = 1;
			scanf("%*[^\n]"); //% type specifier /  * disacard / [^\n] read except new line
			getchar();
		}
		else if (temp < 0) {
			printf("You have entered negative input... please try again a positive or zero integer input\n\n");
			check = 1;
			scanf("%*[^\n]"); //% type specifier /  * disacard / [^\n] read except new line
			getchar();
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

char is_integer(float* temp) { return *temp == (int)*temp; }

void Add_Employee(emp** emps, int* emp_count) {
	emp* temp = (emp*)realloc(*emps, ++(*emp_count) * sizeof(emp));
	if (temp == NULL)
	{
		printf("New employee can't be allocated");
		(*emp_count)--;
		return;
	}
	*emps = temp;

	printf("------- Adding new employee to the System -------\n\n");
	unduplicated_id_enter(emps, emp_count);
	(*emps)[*emp_count - 1].name = enter_name("Enter Name : ");
	if (!(*emps)[*emp_count - 1].name) {
		(*emp_count)--;
		printf("\n[ERROR] Failed to allocate memory for employee name. Operation aborted! \n\n");
		if (*emp_count == 0) {
			free(*emps);
			*emps = NULL;
		}
		else {
			emp* temp = (emp*) realloc(*emps, *emp_count * sizeof(emp));
			if (temp == NULL) {
				printf("\n[ERROR] Failed to reallocate for less memory usage\n\n");
				return;
			}
			*emps = temp;
		}
		return;
	}
	(*emps)[*emp_count - 1].d = Define_Deparment();
	(*emps)[*emp_count - 1].t = Define_Type();
	Define_Salary(&(*emps)[*emp_count - 1].t, &(*emps)[*emp_count - 1]);
	printf("\n[SUCCESS] Employee (\"%s\") added successfully!\n\n", (*emps)[*emp_count - 1].name);
}

char* enter_name(char* arr)
{
	char* temp = NULL;
	char is_valid_name = 0;
	while (!is_valid_name) {
		temp = (char*)malloc(sizeof(char));
		if (!temp) {
			printf("string has not been allocated");
			return NULL;
		}
		printf("%s", arr);
		int character;
		character = getchar();
		int cnt = 1;
		if (character == '\n') {
			printf("Name cannot be empty. Please try again.\n\n");
			free(temp);
			continue;
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
			free(temp);
			continue;
		}
	}
	return temp;
}

char is_valid_name_check(char x) {
	if ( (x >= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z' ) || (x == ' ' ) )
		return 1;
	else {
		return 0;
	}
}

void unduplicated_id_enter(emp** emps, int* emp_count)
{
	char is_duplicated;
	do {
		is_duplicated = 0;
		 Define_Integer(&(*emps)[*emp_count - 1].id, "Enter ID : ");
		int i;
		for (i = 0; i < *emp_count - 1; i++)
		{
			if ((*emps)[*emp_count - 1].id == (*emps)[i].id) {
				printf("\nThis ID is reserved for another employee\n\n");
				is_duplicated = 1;
				break;
			}
		}
	} while (is_duplicated);
}

dep Define_Deparment() {
	int choice;
	do
	{
		printf("\nSelect Department : \n\n");
		printf("1. HR\n");
		printf("2. IT\n");
		printf("3. FINANCE\n");
		printf("4. ENGINEERING\n\n");
		printf("Enter your choice: ");
		Define_Integer(&choice, "");
		if (choice > 4 || choice < 1) {
			printf("Please enter a choice in the valid range (1~4)\n\n");
		}
	} while (choice > 4 || choice < 1);
	dep temp;
	switch (choice) {
	case 1:
		temp = HR;
		break;
	case 2:
		temp = IT;
		break;
	case 3:
		temp = Finance;
		break;
	default:
		temp = Engineering;
		break;
	}
	return temp;
}

type Define_Type() {
	int choice;
	do
	{
		printf("\nSelect Employee Type : \n\n");
		printf("1. Full-Time\n");
		printf("2. Part-Time\n");
		printf("3. Intern\n\n");
		printf("Enter your choice: ");
		Define_Integer(&choice, "");
		if (choice > 3 || choice < 1) {
			printf("Please enter a choice in the valid range (1~3)\n\n");
		}
	} while (choice > 3 || choice < 1);
	type temp;
	switch (choice) {
	case 1:
		temp = Full_Time;
		break;
	case 2:
		temp = Part_Time;
		break;
	default:
		temp = Intern;
		break;
	}
	return temp;
}

void Define_Salary(type* t,emp * e)
{
	switch (*t) {
	case 0:
		Define_double(&((*e).monthly_salary), "Enter Monthly Salary : ");
		break;
	case 1:
	case 2:
		Define_double(&((*e).hourly_rate), "Enter Hourly Rate : ");
		break;
	}
}

void Search_emp_by_ID(emp** emps, int* emp_count)
{
	if (*emp_count == 0) {
		printf("There's no employees in data base. Please add an employee first.\n\n");
		return;
	}
	int search_ID;
	printf("\n ------ Search Employee ------\n\n");
	Define_Integer(&search_ID, "Enter Employee ID : ");
	int index = Search_by_ID(emps, emp_count, search_ID);
	if (index == -1) {
		printf("[ERROR] Employee with ID %i not found!\n\n", search_ID);
		return;
	}
	printf("\n--- Employee Details ---\n");
	print_employee(emps, index);
	printf("-----------------------------\n\n");
}

int Search_by_ID(emp** emps, int* emp_count, int search_ID) {
	int i = 0;
	int index = -1;
	for (i = 0; i < *emp_count; i++) {
		if (search_ID == (*emps)[i].id) {
			index = i;
			break;
		}
	}
	return index;
}

void Remove_Employee(emp** emps, int* emp_count)
{
	if (*emp_count == 0) {
		printf("There's no employees in data base. Please add employees first.\n\n");
		return;
	}
	int search_ID;
	Define_Integer(&search_ID, "Enter Employee ID to be deleted : ");
	int index = Search_by_ID(emps, emp_count,search_ID);
	if (index == -1) {
		printf("[ERROR] Employee with ID %i not found!\n\n",search_ID);
		return;
	}
	free((*emps)[index].name);
	for (; index < *emp_count-1; index++)
	{
		(*emps)[index] = (*emps)[index + 1];
	}
	(*emp_count)--;
	if (*emp_count == 0)
	{
		free(*emps);
		*emps = NULL;
	}
	else {
		emp* temp = (emp*)realloc(*emps, *emp_count * sizeof(emp));
		if (temp == NULL)
		{
			printf("Can't reallocating to use less memory\n");
			printf("[SUCCESS] Employee with ID %i has been removed.\n\n", search_ID);
			return;
		}
		(*emps) = temp;
	}
	printf("[SUCCESS] Employee with ID %i has been removed.\n\n", search_ID);
}

void Define_double(double* n,char * arr) {
	double temp;
	char check = 1;
	while (check) {
		printf("%s",arr);
		check = scanf("%lf", &temp);
		if (!check) {
			printf("You have entered non-numerical input... please try again\n\n");
			check = 1;
			scanf("%*[^\n]"); //% type specifier /  * disacard / [^\n] read except new line
			getchar();
		}
		else if (temp <= 0) {
			printf("You have entered non-positive input... please try again a positive input\n\n");
			check = 1;
			scanf("%*[^\n]"); //% type specifier /  * disacard / [^\n] read except new line
			getchar();
		}
		else
		{
			*n = temp;
			scanf("%*[^\n]"); //% type specifier /  * disacard / [^\n] read except new line
			check = 0;
			getchar();
		}
	}
}



void print_employee(emp** emps,int index) {
	printf("ID:                 %i\n", (*emps)[index].id);
	printf("Name:               %s\n", (*emps)[index].name);
	printf("Department:         %s\n", return_department_string ( (*emps)[index].d));
	printf("Compensation Type:  %s\n", (*emps)[index].t == Full_Time ? "Monthly Salary":"Hourly Rate");
	printf("Amount:             %.2lf $\n", (*emps)[index].t == Full_Time ? (*emps)[index].monthly_salary : (*emps)[index].hourly_rate);
}

char* return_department_string(dep d) {
	switch (d)
	{
	case 0:
		return "HR";
	case 1:
		return "IT";
	case 2:
		return "Finance";
	default:
		return "Engineering";
	}
}

char* return_type_string(type t) {
	switch (t)
	{
	case 0:
		return "Full-Time";
	case 1:
		return "Part-Time";
	default:
		return "Intern";
	}
}

int menu_filter() {
	int choice;
	do
	{
		printf("--- Filter Employees ---\n\n");
		printf("Filter by:\n\n");
		printf("1. Department\n");
		printf("2. Employee Type\n\n");
		Define_Integer(&choice, "Enter your choice: ");
		if (choice > 2 || choice < 1) {
			printf("Please enter a choice in the valid range (1~2)\n\n");
		}
	} while (choice > 2 || choice < 1);
	return choice;
}

int menu_filter_department() {
	int choice;
	do
	{
		printf("--- Filter Employees ---\n\n");
		printf("Filter by:\n\n");
		printf("1. HR\n");
		printf("2. IT\n");
		printf("3. Finance\n");
		printf("4. Engineering\n\n");
		Define_Integer(&choice, "Enter your choice: ");
		if (choice > 4 || choice < 1) {
			printf("Please enter a choice in the valid range (1~4)\n\n");
		}
	} while (choice > 4 || choice < 1);
	return choice;
}

int menu_filter_type() {
	int choice;
	do
	{
		printf("--- Filter Employees ---\n\n");
		printf("Filter by:\n\n");
		printf("1. Full-Time\n");
		printf("2. Part-Time\n");
		printf("3. Intern\n\n");
		Define_Integer(&choice, "Enter your choice: ");
		if (choice > 3 || choice < 1) {
			printf("Please enter a choice in the valid range (1~3)\n\n");
		}
	} while (choice > 3 || choice < 1);
	return choice;
}

void Filter(emp ** emps,int * emp_count) {
	if (*emp_count == 0) {
		printf("There's no employees in data base. Please add an employee first.\n\n");
		return;
	}
	int choice_1,choice_2;
	choice_1 = menu_filter();
	switch (choice_1)
	{
	case 1:
		choice_2 = menu_filter_department();
		break;
	default:
		choice_2 = menu_filter_type();
	}
	emp temp = { 0 };
	switch (choice_1) {
	case 1:
		switch (choice_2) {
		case 1:
			temp.d = HR;
			break;
		case 2:
			temp.d = IT;
			break;
		case 3:
			temp.d = Finance;
			break;
		default:
			temp.d = Engineering;
		}
		break;
	case 2:
		switch (choice_2) {
		case 1:
			temp.t = Full_Time;
			break;
		case 2:
			temp.t = Part_Time;
			break;
		default:
			temp.t = Intern;
		}
	}
	int cnt = 0;
	printf("\n----------------------------\n");
	int i;
	for (i = 0; i < *emp_count; i++) {
		if ( (choice_1 ==1 && temp.d == (*emps)[i].d) || (choice_1 ==2 && temp.t == (*emps)[i].t) ) {
			print_employee(emps,i);
			cnt++;
			printf("----------------------------\n");
		}
	}
	printf("\nTotal Match");
	if (cnt != 1) {
		printf("es");
	}
	printf(" : % i\n\n", cnt);
}

void print_all_emp(emp** emps, int* emp_count)
{
	if (*emp_count == 0) {
		printf("There's no employees in data base. Please add an employee first.\n\n");
		return;
	}
	printf("\n========= printing all employees =========\n");
	printf("\n------------------------------------------\n");
	int i;
	for (i = 0; i < *emp_count; i++) {
			print_employee(emps, i);
			printf("------------------------------------------\n");
	}
	printf("\nTotal Employee");
	if (*emp_count != 1) {
		printf("s");
	}
	printf(" : % i\n\n", *emp_count);
}

void Calculate_Total_Payroll(emp **emps,int * emp_count) {
	if (*emp_count == 0) {
		printf("There's no employees in data base. Please add an employee first.\n\n");
		return;
	}
	double hr;
	Define_double(&hr, "Enter standard monthly working hours for hourly staff : ");
	double total_monthly = 0, cost_per_hr_monthly = 0;
	int i;
	for (i = 0; i < *emp_count; i++) {
		if ((*emps)[i].t == Full_Time) {
			total_monthly += (*emps)[i].monthly_salary;
		}
		else {
			cost_per_hr_monthly += (*emps)[i].hourly_rate;
		}
	}
	double total_hourly = cost_per_hr_monthly * hr;
	double total = total_hourly + total_monthly;
	printf("\n\n-------- Payroll Summary --------\n\n");
	printf("Total Full-Time Base Salaries   : %.2lf $\n", total_monthly);
	printf("Total Hourly Estimates (%.2lfh)  : %.2lf $\n", hr,total_hourly);
	printf("--------------------------------------\n");
	printf("Total Payroll Expense :           %.2lf $\n\n", total);
}