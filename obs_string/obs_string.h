#ifndef OBS_STRING_LIB_H
#define OBS_STRING_LIB_H

#include <stddef.h>
#include <stdio.h> 

define ENOENT 2   
define EACCES 13 
define EINVAL 22   
define EPERM 1    
define EIO 5     

char obs_tolower(char c);
int obs_strlen(char *string);
char* obs_strcpy(char* dest, char* source);
int obs_strcmp(char* str1, char* str2);
char* obs_strncat(char* dest, char* src, int n);
char* obs_strcat(char* dest, char* src);
char* obs_memchr(char* dest, char ch, int n);
char* obs_memcpy(char* src, char* dest, int n);
int obs_memcmp(char* str_1, char* str_2, int n);
int obs_strcspn(char* src, char x);
char* obs_strpbrk(char* str, char* chk);
char* obs_strchr(const char* str, char ch);
char* obs_memmove(char* dest, const char* src, int n);
char* obs_strrchr(const char* str, int c);
int obs_strcoll(const char* str1, const char* str2);
void* obs_memset(void* ptr, int value, size_t num);
char* obs_strstr(const char* haystack, const char* needle);
char* obs_strtok(char* str, const char* delim);
size_t obs_strspn(const char* str, const char* accept);
const char* obs_strerror(int errnum);
int obs_strncmp(const char* str1, const char* str2, size_t n);

#endif // OBS_STRING_LIB_H
