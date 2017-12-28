#include <stdio.h>


char read[25][10]={"zero", "one", "two", "three", "four", 
    "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve",
    "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", 
    "nineteen"};
char readten[5][10]={"ten","twenty","thirty","forty","fifty"};

void rd(int n)
{
    if(n<19)printf("%s",read[n]);
    else if(n%10==0)printf("%s",readten[n/10-1]);
    else
    {
        int a,b;
        b=n%10;
        a=n/10;
        printf("%s %s",readten[a-1],read[b]);
    }
}

int main()
{
    int h,m;
    scanf("%d %d",&h,&m);
    if(m==0)
    {
        rd(h);
        printf(" o'clock");
    }

    else
    {
        rd(h);
        printf(" ");
        rd(m);
    }

    return 0;

}