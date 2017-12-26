#include <stdio.h>


int gcd(int a, int b)
{
    if(b == 0)
        return a;
    return gcd(b, a % b);
}

int main(){

    int x,y,z;
    scanf("%d %d %d",&x,&y,&z);

    switch(z){
        case 1:
            printf("%d\n",x+y );
            break;
        case 2:
            printf("%d\n",x-y );
            break;
        case 3:
            printf("%d\n",x*y );
            break;
        case 4:
            printf("%d\n",x/y );
            break;
        case 5:
            printf("%d\n",x%y );
            break;
        case 6:
            printf("%d\n",gcd(x,y) );
            break;
        case 7:
            printf("%d\n",(x/gcd(x,y))* (y/gcd(x,y))*gcd(x,y));
            break;
    }

    return 0;
}