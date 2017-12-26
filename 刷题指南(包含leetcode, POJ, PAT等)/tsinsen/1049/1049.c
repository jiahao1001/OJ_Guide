#include <stdio.h>


void assign(int P[], int n, int k)
{
    int i;
    for (i = 0; i < n; i++)
    {
        P[i] = k & 1;
        k = k >> 1;
    }
}
int logcalc(int exp1, char op, int exp2)
{
    if (op == '~')
        return !exp2;
    else if (op == '>')
        return !exp1 || exp2;
    else if (op == '^')
        return exp1 && exp2;
    else if (op == 'v')
        return exp1 || exp2;
    return 0;
}

int main(){
    int p[4];
    char temp[4], sig1[10],sig2[10];
    int a[10], index1[10], index2[10];
    char  opera[10];

    int n,m,i,j,k,x,y;
    scanf("%d %d",&n,&m);

    for(i=0;i<m;i++){
        scanf("%s %c%d %c %c%d", temp, &sig1[i], &index1[i], &opera[i], &sig2[i], &index2[i]);
    }

    k=1<<n; // n个变元时的真值表的可能组合个数
    int flag0=1;int flag1=1;
    for(i=0;i<k;i++){
        assign(p, 4, i);
        for(j=0;j<m;j++){
            if(sig1[j]=='A')
                x=a[index1[j]];
            else if(sig1[j]=='P')
                x=p[index1[j]];
            else x=0;

            if(sig2[j]=='A')
                y=a[index2[j]];
            else if(sig2[j]=='P')
                y=p[index2[j]];
            else y=0;

            a[j]=logcalc(x, opera[j], y);
        }
        flag0=flag0&&a[m-1];
        flag1=flag1&&!a[m-1];
    }


    if (flag0 == 1)
        printf("1\n");
    else if (flag1 == 1)
        printf("-1\n");
    else
        printf("0\n");
    
    return 0;
}

