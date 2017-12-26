#include<stdio.h>
int num;


//after1: 是否在1后面
int get_num(int n, bool after1)
{
    int result;
    if(after1){
        if(n == 1) result = 0;
        if(n == 2) result = 1;
        if(n == 3) {num ++; result = 2;}
        if(n > 3) result = get_num(n-2, false) + get_num(n-3, false);
        num += result;
    } else{
        if(n == 1){num ++; result = 1;}
        if(n == 2) result = 1;
        if(n == 3){num += 2; result = 3;}
        if(n > 3) result = get_num(n-1, true) + get_num(n-2, false) + get_num(n-3, false);
    }
    return result;
}
int main()
{
    num = 0;
    int n;
    scanf("%d", &n);
    printf("%d\n", get_num(n, false));
    printf("%d\n", num);
    return 0;
}