#include <stdio.h>
#include <stdlib.h>

typedef enum Book_Status {
	Return, Issue, Reserved,Lost
}book_status;

typedef enum Book_Category {
	Fiction, Science, Computer_Science, History, Novel, Category_Count
}book_category;

typedef struct Book {
	float price;
	book_category category;
	book_status availability;
	char* title;
	char* author;

}book;

void Library_Management_System();

char main_menu();
book_status menu_Status();
void adding_book(book** books,int * books_count);

char* enter_name(char* arr);
void unduplicated_book_title_enter(book** books, int* books_count);
int get_length_string(char* s);
char string_compare(char* x, char* y);



void Define_Integer(int* n, char arr[]);
char is_integer(float* temp);
void Define_Float(float* n, char* s);
char is_valid_name_check(char x);
book_category Define_Category();
void Search_by_title_or_author(book** books, int * books_count);

void Change_Status(book** books, int* books_count);

char* return_category_string(book_category x);
char* return_status_string(book_status x);
void print_book(book* book);

void Category_Count_Books(book ** books, int *books_count);

int main(void) {
	Library_Management_System();
}

void Library_Management_System() {
	int choice;
	int books_count = 0;
	book* books = NULL;
	do {
		choice = main_menu();
		switch (choice)
		{
		case 1:
			adding_book(&books, &books_count);
			break;
		case 2:
			Search_by_title_or_author(&books, &books_count);
			break;
		case 3:
			Change_Status(&books, &books_count);
			break;
		case 4:
			Category_Count_Books(&books, &books_count);
			break;
		case 5: {
					int i;
					for (i = 0; i < books_count; i++) {
						free(books[i].title);
						free(books[i].author);
					}
					free(books);
					break;
				}
		}
	} while (choice != 5);
}

char main_menu() {
	int choice;
	do
	{
		printf("======= Library Management System =======\n\n");
		printf("1. Add New Book\n");
		printf("2. Search Book (by Title or Author)\n");
		printf("3. Change Book Status (Return (Available) / Issue (Borrowed) / Reserved / Lost)\n");
		printf("4. Count Books by Category\n");
		printf("5. Exit\n\n");
		Define_Integer(&choice, "Enter your choice: ");
		if (choice > 5 || choice < 1) {
			printf("Please enter a choice in the valid range (1~5)\n\n");
		}
	} while (choice > 5 || choice < 1);
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

char is_integer(float* temp) { return *temp == (int)*temp; }

void adding_book(book** books, int* books_count)
{
	book * temp = (book*)realloc(*books, ++(*books_count) * sizeof(book));
	if (temp == NULL)
	{
		printf("New book can't be allocated");
		(*books_count)--;
		return;
	}
	*books = temp;

	printf("------- Adding new book to the System -------\n\n");
	unduplicated_book_title_enter(books, books_count);
	(*books)[*books_count - 1].author = enter_name("Enter Author: ");
	Define_Float(&(*books)[*books_count - 1].price, "Enter Price: ");
	(*books)[*books_count - 1].category = Define_Category();
	(*books)[*books_count - 1].availability = Return;
	printf("Book \"%s\" added successfully!\n\n", (*books)[*books_count - 1].title);
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
		printf("%s",arr);
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
	if (x >= 'a' && x <= 'z' || x >= 'A' && x <= 'Z'|| x==' ')
		return 1;
	else {
		return 0;
	}
}

void Define_Float(float* n, char * s) {
	float temp;
	char check = 1;
	while (check) {
		printf("%s",s);
		check = scanf("%f", &temp);
		if (!check) {
			printf("You have entered non-numerical input... please try again\n\n");
			check = 1;
			scanf("%*[^\n]"); //% type specifier /  * disacard / [^\n] read except new line
		}
		else if (temp<0){
			printf("You have entered negative input... please try again\n\n");
			check = 1;
			scanf("%*[^\n]");
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

book_category Define_Category() {
	int choice;
	do
	{
		printf("\n======= Book Categories =======\n\n");
		printf("1. Fiction\n");
		printf("2. Science\n");
		printf("3. Computer Science\n");
		printf("4. History\n");
		printf("5. Novel\n\n");
		printf("Enter your choice: ");
		Define_Integer(&choice, "");
		if (choice > 5 || choice < 1) {
			printf("Please enter a choice in the valid range (1~5)\n\n");
		}
	} while (choice > 5 || choice < 1);
	book_category temp;
	switch (choice) {
	case 1:
		temp = Fiction;
		break;
	case 2:
		temp = Science;
		break;
	case 3:
		temp = Computer_Science;
		break;
	case 4:
		temp = History;
		break;
	default:
		temp = Novel;
		break;
	}
	return temp;
}

void unduplicated_book_title_enter(book ** books,int * books_count) {
	char is_duplicated;
	do {
		is_duplicated = 0;
		(*books)[*books_count - 1].title = enter_name("Enter Title: ");
		int i;
		for (i =0; i < *books_count - 1; i++)
		{
			if (string_compare( (*books)[*books_count - 1].title, (*books)[i].title)) {
				printf("\nThis Title of Book has been added before\n\n");
				is_duplicated = 1;
				break;
			}
		}
	} while (is_duplicated);
}

char string_compare(char * x,char*y) {
	int x_len = get_length_string(x);
	int y_len = get_length_string(y);

	if ( x_len != y_len) {
		return 0;
	}
	else {
		int i;
		for (i = 0; i < x_len; i++) {
			if (x[i] != y[i]) {
				return 0;
			}
		}
	}
	return 1;

	
}

int get_length_string(char* s) {
	int cnt = 0;
	while (s[cnt] != '\0') {
		cnt++;
	}
	cnt++;
	return cnt;
}

void Search_by_title_or_author(book** books, int*  books_count) {
	if (*books_count == 0) {
		printf("The library is currently empty. Please add books first.\n\n");
		return;
	}
	char* search = enter_name("Please enter the title of book or author's name: ");
	int i = 0;
	book* target = (book*)malloc(*books_count * sizeof(book));
	if (target == NULL)
	{
		printf("Searching books can't be allocated");
		free(search);
		return;
	}
	int j = 0;
	for (i = 0; i < *books_count; i++) {
		if (string_compare((*books)[i].author, search) || string_compare((*books)[i].title, search)) {
			target[j++] = (*books)[i];
		}
	}
	if (!j) {
		printf("\n[NOT FOUND] No books matched \"%s\"\n\n", search);
		free(search);
		free(target);
		return;
	}
	printf("\n[FOUND] %i Result", j);
	j > 1 ? printf("s :\n") : printf(" :\n");
	printf("----------------------------------\n");
	for (i = 0; i < j; i++) {
		print_book(target + i);
		printf("----------------------------------\n");
	}
	printf("\n\n");
	free(search);
	free(target);
}

void print_book(book* book) {
	printf("Title      : %s\n", (*book).title);
	printf("Author     : %s\n", (*book).author);
	printf("Price      : %.2f $\n", (*book).price);
	printf("Category   : %s\n", return_category_string((*book).category));
	printf("Status     : %s\n", return_status_string((*book).availability));
}

char* return_category_string(book_category x) {
	switch (x) {
	case 0:
		return "Fiction";
	case 1:
		return "Science";
	case 2:
		return "Computer Science";
	case 3:
		return "History";
	default:
		return "Novel";
	}

}

char* return_status_string(book_status x) {
	switch (x) {
	case 0:
		return "Return (Available)";
	case 1:
		return "Issue (Borrowed)";
	case 2:
		return "Reserved";
	default:
		return "Lost";
	}
}

void Change_Status(book** books, int* books_count) {
	if (*books_count == 0) {
		printf("The library is currently empty. Please add books first.\n\n");
		return;
	}
	char* search = enter_name("Please enter the title of book: ");
	int i = 0;
	int index = -1;
	for (i = 0; i < *books_count; i++) {
		if (string_compare((*books)[i].title, search)) {
			index = i;
			break;
		}
	}
	if (index==-1) {
		printf("\n[NOT FOUND] No books matched \"%s\"\n\n", search);
		free(search);
		return;
	}
	printf("\n\nCurrent Status : %s\n\n", return_status_string((*books)[index].availability));
	(*books)[index].availability = menu_Status();
	printf("Status updated successfully to [%s]!\n\n", return_status_string((*books)[index].availability));
	free(search);
}

book_status menu_Status()
{
	int choice;
	do
	{
		printf("\n======= Choose New Status =======\n\n");
		printf("1. Return (Available)\n");
		printf("2. Issue (Borrowed)\n");
		printf("3. Reserved\n");
		printf("4. Lost\n");
		printf("Enter your choice: ");
		Define_Integer(&choice, "");
		if (choice > 4 || choice < 1) {
			printf("Please enter a choice in the valid range (1~4)\n\n");
		}
	} while (choice > 4 || choice < 1);
	switch (choice) {
	case 1:
		return Return;
	case 2:
		return Issue;
	case 3:
		return Reserved;
	default:
		return Lost;
	}
}

void Category_Count_Books(book** books, int* books_count)
{
	if (*books_count == 0) {
		printf("The library is currently empty. Please add books first.\n\n");
		return;
	}
	int freq_arr[Category_Count] = { 0 };
	int i;
	for (i = 0; i < *books_count; i++)
	{
		freq_arr[(*books)[i].category]++;
	}
	printf("======= Books Count by Category =======\n\n");
	for (i = 0; i < Category_Count; i++) {
		switch (i) {
		case 0:
			printf("Fiction          : %i\n", freq_arr[i]);
			break;
		case 1:
			printf("Science          : %i\n", freq_arr[i]);
			break;
		case 2:
			printf("Computer Science : %i\n", freq_arr[i]);
			break;
		case 3:
			printf("History          : %i\n", freq_arr[i]);
			break;
		case 4 :
			printf("Novel            : %i\n\n", freq_arr[i]);
			break;
		}
	}
}