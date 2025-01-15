#define ENOENT 2    
#define EACCES 13   		     
#define EINVAL 22    
#define EPERM 1      
#define EIO 5       
char obs_tolower(char c) {
    static char lookup[256] = {0};

    if (lookup['A'] == 0) {
        for (char i = 'A'; i <= 'Z'; i++) {
            lookup[i] = i + 32;  
        }
    }

    if (c >= 'A' && c <= 'Z') {
        return lookup[(unsigned char)c];
    }

    return c;
}
int obs_strlen(char *string){
	
	int len = 0;
	while(string[len] != '\0'){
		len++;
		} 
	return len;
}

char* obs_strcpy(char* dest, char* source) {
    char* originalDest = dest;    
    
    while ((*dest++ = *source++) != '\0');
    return originalDest; 
}

int obs_strcmp(char* str1,char* str2){
	
	while(*str1 && *str2){
		if(*str1 != *str2){
			return *str1 -*str2;
		}
	str1++;
	str2++;
	}
	return *str1-*str2;
}
char* obs_strncat(char* dest,char* src,int n){
	char*originalDest  = dest;

	while(*dest != '\0'){
		dest++;
	}
	while(n>0 && *src != '\0'){
		*dest = *src;
		dest++;
		src++;
		n--;
	}
	*dest = '\0';
		return originalDest; 
}

char* obs_strcat(char* dest, char* src){
	char* originalDest = dest;
	
	while(*dest != '\0'){
		dest++;
	}

	while(*src != '\0'){
		*dest = *src;
		
		dest++;
		src++;
	}
	*dest = '\0';

	return originalDest;
}

char* obs_memchr(char* dest, char ch, int n){
	
	char* originalDest = dest;
	while(n > 0){
		if(*originalDest == ch){
			return originalDest;
		 }	
		originalDest++;	
		n--;
	}

	return NULL;

}
char* obs_memcpy(char* src, char* dest, int n){
	
	char* originalDest = dest;
	while(n > 0){
		*dest = *src;
		 dest++;
		 src++;
		 n--;
	}	
	return originalDest;
}
int obs_memcmp(char* str_1, char* str_2, int n){
	
	while((*str_1 && *str_2) && n > 0){
		
		if(*str_1 != *str_2){
		       return *str_1 - *str_2;	
		}
		n--;
		str_1++;
		str_2++;
	}
		return 0;
}
int obs_strcspn(char* src, char x){
	int len;
	while((*src != x)&& *src != '\0'){
		len++;
		src++;
	}
	return len;
}

char* obs_strpbrk(char* str, char* chk){

	while(*str){
		const char* a = chk;
		while(*a){
			if(*str == *a){
				return str;
			}
			a++;
		} 
		str++;
	}
	return NULL;

}
char *obs_strchr(const char *str, char ch) {
    while (*str) {
        if (*str == ch) {
            return (char *)str; 
        }
        str++;
    }

    if (ch == '\0') {
        return (char *)str;    }

    return NULL; }

char* obs_memmove(char* dest, const char* src, int n) {
    char* orgDest = dest;  
    if (dest < src || dest >= src + n) {
        while (n--) {
            *dest++ = *src++;
        }
    } else {
        dest += n - 1;
        src += n - 1;
        while (n--) {
            *dest-- = *src--;
        }
    }

    return orgDest;  
}

char *obs_strrchr(const char *str, int c) {
    const char *last_occurrence = NULL;

    while (*str) {
        if (*str == (char)c) {
            last_occurrence = str;
        }
        str++;
    }

    return last_occurrence;
}

int obs_strcoll(const char *str1, const char *str2) {
    while (*str1 != '\0' && *str2 != '\0') {
        if (*str1 != *str2) {
            char c1 = my_tolower((unsigned char)*str1);
            char c2 = my_tolower((unsigned char)*str2);

            if (c1 < c2) {
                return -1; 
            } else if (c1 > c2) {
                return 1;              }
        }

        str1++;
        str2++;
    }

    if (*str1 == '\0' && *str2 == '\0') {
        return 0; 
    } else if (*str1 == '\0') {
        return -1; 
    } else {
        return 1; 
    }
}

void *obs_memset(void *ptr, int value, size_t num) {
    unsigned char *p = ptr;
    unsigned char val = (unsigned char)value;

    for (size_t i = 0; i < num; i++) {
        p[i] = val;
    }

    return ptr; 
}


char *obs_strstr(const char *haystack, const char *needle) {
    if (*needle == '\0') {
        return (char *)haystack;
    }

    for (const char *h = haystack; *h != '\0'; h++) {
        if (*h == *needle) {
            const char *h_temp = h;
            const char *n_temp = needle;

            while (*h_temp != '\0' && *n_temp != '\0' && *h_temp == *n_temp) {
                h_temp++;
                n_temp++;
            }

            if (*n_temp == '\0') {
                return (char *)h;
            }
        }
    }

    return NULL;
}


char *obs_strtok(char *str, const char *delim) {
    static char *last = NULL;  
    if (str == NULL) {
        str = last;
    }

    while (*str && my_strchr(delim, *str)) {
        str++;
    }

    if (*str == '\0') {
        return NULL;
    }

    char *token_start = str;
    while (*str && !my_strchr(delim, *str)) {
        str++;
    }

    if (*str) {
        *str = '\0';
        last = str + 1;      } else {
        last = NULL;      }

    return token_start;
}
size_t obs_strspn(const char *str, const char *accept) {
    size_t count = 0;

    while (*str) {
        const char *a = accept;
        int found = 0;
        while (*a) {
            if (*str == *a) {
                found = 1;
                break;
            }
            a++;
        }

        if (!found) {
            break;
        }

        count++;
        str++;
    }

    return count;
}
const char *obs_strerror(int errnum) {
    switch (errnum) {
        case EINVAL:
            return "Invalid argument";
        case ENOENT:
            return "No such file or directory";
        case EIO:
            return "Input/output error";
        case EPERM:
            return "Operation not permitted";
        case EACCES:
            return "Permission denied";
        default:
            return "Unknown error";
    }
}
int obs_strncmp(const char *str1, const char *str2, size_t n) {
    for (size_t i = 0; i < n; i++) {
        if (str1[i] != str2[i]) {
            return (unsigned char)str1[i] - (unsigned char)str2[i];
        }

        if (str1[i] == '\0' || str2[i] == '\0') {
            break;
        }
    }

    return 0;
}
int main() {
    char input[] = "Hello, world! This is a test.";
    const char *delim = " ,.!";  // Delimiters: space, comma, period, exclamation mark

    char *token = my_strtok(input, delim);
    while (token != NULL) {
        printf("Token: %s\n", token);
        token = my_strtok(NULL, delim);  // Continue tokenizing the same string
    }

    return 0;
}
