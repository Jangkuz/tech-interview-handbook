#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    char x = 'A';
    char y = (char)tolower(x);
    printf("%c\n", y);
    return 0;
}
