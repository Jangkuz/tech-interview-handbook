#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
int getStrSize(char *s){
    char *ptr = s;
    int i = 0;
    while(*(ptr) != '\0'){
    ptr++;
	i++;
    }
    return i;
}
char *lTrim(char s[])
{
    int i = 0;
    while (s[i] == 32)
        i++;
    {
        if (i > 0)
        {
            strcpy(&s[0], &s[i]);
        }
    }
    return s;
}

char *rTrim(char *s)
{

    char *ptr = s;
    ptr = ptr + getStrSize(s) - 1;
    while (*ptr == 32 && ptr >= s)
        ptr--;
    {
        *(ptr + 1) = '\0'; // NULL
    }

    return s;
}

char *trimAllBlank(char s[])
{
    lTrim(s);
    rTrim(s);
    char *ptr = strstr(s, " ");
    while (ptr != NULL)
    {
        strcpy(ptr, ptr + 1);
        ptr = strstr(s, " ");
    }
    return s;
}

char *trimNonAlphanumerical(char *s)
{
    trimAllBlank(s);
    // int i = 0;
    char *ptr = s;
    while (*(ptr) != '\0')
    {
    	*ptr = (char)tolower(*ptr);
        if (!((48 <= *ptr && *ptr <= 57) || (97 <= *ptr && *ptr <= 122)))
        {
        	

                strcpy(ptr, ptr + 1);
            
        } else {
        	ptr++;
		}
        
    }
    return s;
}
 bool isPalindrome(char *s)
 {
     trimNonAlphanumerical(s);
     if (strcmp(s, "") == 0){
     	return true;
	 }
	 
     bool flag = true;
	
	char *ptr = s;
    char *endPtr = ptr + getStrSize(s) - 1;
	while(ptr < endPtr){
		if(*ptr != *endPtr){
			flag = false;
		}
		ptr++;
		endPtr--;
	}
	
	
     return flag;
 }

int main()
{
    char s[] = "asadsa";
//    printf("\"%s\"\n", trimNonAlphanumerical(s));
	printf("%d\n", isPalindrome(s));
    return 0;
}
