#include <stdio.h>
#include "my_string.h"

//1
void* memchr(void* ptr, int value, unsigned int distance) 
{
	for (int i = 0; i < distance; i++)
	{
		if (*((unsigned char*)ptr + i) == value) {
			return ((unsigned char*)ptr + i);
		}
	}
	return NULL;
} 
//2
int memcmp(void* ptr1, void* ptr2, unsigned int distance)
{
	for (int i = 0; i < distance; i++)
	{
		if (*((unsigned char*)ptr1 + i) > *((unsigned char*)ptr2 + i))
		{
			return 1;
		}
		else if (*((unsigned char*)ptr1 + i) < *((unsigned char*)ptr2 + i))
		{
			return -1;
		}
	}
	return 0;
}
//3
void* memcpy(void* ptr1, void* ptr2, unsigned int distance)
{
	for (int i = 0; i < distance; i++)
	{
		*((unsigned char*)ptr1 + i) = *((unsigned char*)ptr2 + i);
	}
	return ptr1;
}
//4
void* memmove(void* ptr1, void* ptr2, unsigned int distance)
{
	if (ptr1 > ptr2) {
		for (int i = distance-1; i >= 0; i--) {
			*((unsigned char*)ptr1 + i) = *((unsigned char*)ptr2 + i);
		}
		return ptr1;
	}
	else {
		return memcpy(ptr1, ptr2, distance);
	}
}
//5
void* memset(void* ptr,int value, unsigned int distance)
{
	for (int i = 0; i < distance; i++)
	{
		*((unsigned char*)ptr+i) = value;
	}
	return ptr;
}
//6
char* strcat(char* dest, char* src)
{
	unsigned int dest_len = strlen(dest);
	int i = 0;
	while (src[i]) {
		dest[dest_len++] = src[i++];
	}
	dest[dest_len] = '\0';
	return dest;
}
//7
char* strchr(char* str, int value)
{
	int i = 0;
	while (str[i]) {
		if (str[i] == value) {
			return str + i;
		}
		i++;
	}
	if (value == '\0') {
		return str + i;
	}
	return NULL;
}
//8
int strcmp(char* str1, char* str2)
{
	unsigned int str1len = strlen(str1);
	unsigned int str2len = strlen(str2);
	unsigned int min = str1len < str2len ? str1len : str2len;
	for (int i = 0; i < min; i++) {
		if (str1[i] > str2[i]) {
			return 1;
		}
		else if (str1[i] < str2[i]) {
			return -1;
		}
	}
	if (str1len > str2len) {
		return 1;
	}
	else if (str1len < str2len) {
		return -1;
	}
	return 0;
}
//9

//10
char* strcpy(char* dest, char* src)
{
	int i = 0;
	while (src[i] != '\0') {
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return dest;
}
//11
unsigned int strcspn(char* str1, char* str2)
{
	unsigned int cnt = 0, i = 0, j = 0;
	while (str1[i]) {
		char flag_stop = 0;
		while (str2[j]) {
			if (str1[i] == str2[j]) {
				flag_stop = 1;
				break;
			}
			j++;
		}
		if (flag_stop) {
			break;
		}
		j = 0;
		i++;
		cnt++;
	}
	return cnt;
}
//12

//13
unsigned int strlen(char* str) {
	int i = 0;
	while (str[i] != '\0') {
		i++;
	}
	return i;
}
//14
char* strncat(char* dest, char* src, unsigned int n)
{
	if (n == 0) {
		return dest;
	}
	unsigned int dest_len = strlen(dest);
	int i = 0;
	while (src[i]) {
		dest[dest_len++] = src[i++];
		n--;
		if (n == 0) {
			break;
		}
	}
	dest[dest_len] = '\0';
	return dest;
}
//15
int strncmp(char* str1, char* str2,unsigned int n)
{
	for (int i = 0; i < n ; i++) {
		if (str1[i] > str2[i]) {
			return 1;
		}
		else if (str1[i] < str2[i]) {
			return -1;
		}

		if (str1[i] == '\0') {
			return 0;
		}
	}
	return 0;
}
//16
char* strncpy(char* dest, char* src, unsigned int n)
{
	unsigned int i = 0;
	for (i = 0; i < n && src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}
	for (; i < n; i++) {
		dest[i] = '\0';
	}
	return dest;
}
//17
char* strpbrk(char* str1, char* str2)
{
	int i = 0, j = 0;
	while (str1[i]) {
		while (str2[j]) {
			if (str1[i] == str2[j]) {
				return str1 + i;
			}
			j++;
		}
		j = 0;
		i++;
	}
	return NULL;
}
//18
char* strrchr(char* str, int value)
{
	for (int i = strlen(str); i >= 0; i--) {
		if (str[i] == value) {
			return str + i;
		}
	}
	return NULL;
}
//19
unsigned int strspn(char* str1, char* str2)
{
	unsigned int cnt = 0, i = 0, j = 0;
	while (str1[i]) {
		char flag_stop = 1;
		while (str2[j]) {
			if (str1[i] == str2[j]) {
				cnt++;
				flag_stop = 0;
				break;
			}
			j++;
		}
		if (flag_stop) {
			break;
		}
		j = 0;
		i++;
	}
	return cnt;
}
//20
char* strstr(char* str1, char* str2)
{
	unsigned int str1len = strlen(str1);
	unsigned int str2len = strlen(str2);
	if (str1len < str2len) {
		return NULL;
	}
	for (int i = 0; i < str1len - str2len + 1; i++)
	{
		for (int j = 0; j < str2len; j++)
		{
			if (str1[i + j] != str2[j]) {
				break;
			}
			else if (j == str2len - 1)
			{
				return str1 + i;
			}
		}
	}
	return NULL;
}
//21
char* strtok(char* str, char* delim)
{
	static char* ptr = NULL;
	if (str == NULL) {
		str = ptr;
	}
	if (str == NULL) {
		return NULL;
	}
	int i = 0;
	while (str[i]) {
		int j = 0;
		while (delim[j]) {
			if (str[i] == delim[j]) {
				str[i] = '\0';
				ptr = str + i + 1;
				return str;
			}
			j++;
		}
		i++;
	}
	ptr = NULL;
	return str;
}