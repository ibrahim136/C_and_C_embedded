void* memchr(void* ptr, int value, unsigned int distance); //1
int memcmp(void* ptr1, void* ptr2, unsigned int distance); //2
void* memcpy(void* ptr1, void* ptr2, unsigned int distance); //3
void* memmove(void* ptr1, void* ptr2, unsigned int distance); //4
void * memset(void* ptr1, int value, unsigned int distance); //5
char* strcat(char* dest, char* src); //6
char* strchr(char* str, int value); //7
int strcmp(char* str1, char* str2); //8

char* strcpy(char* dest, char* src); //10
unsigned int strcspn(char* str1, char* str2); //11

unsigned int strlen(char* str); //13
char* strncat(char* dest, char* src, unsigned int n); //14
int strncmp(char* str1, char* str2, unsigned int n); //15
char* strncpy(char* dest, char* src, unsigned int n); //16
char* strpbrk(char* str1, char* str2); //17
char* strrchr(char* str, int value); //18
unsigned int strspn(char* str1, char* str2); //19
char* strstr(char* str1, char* str2); //20
char* strtok(char* str, char* delim); //21

