#include <stdio.h>

int main (int argc, const char * argv[])
{
    int i;
    char str[2000];
    while (gets(str) != NULL) {
        for (i=0; str[i]!='\0'; i++)
        {
            if (str[i] == 'y' && str[i+1] == 'o' && str[i+2] == 'u')
            {
                putchar('w');
                putchar('e');
                i+=2;
            }
            else putchar(str[i]);
        }
        putchar('\n');
    }
    return 0;
}
