#include <stdio.h>
#include <string.h>
char s[20];
int find(char c)
{
	if (s[0]==c && s[1]==c && s[2]==c) return 1;
	if (s[3]==c && s[4]==c && s[5]==c) return 1;
	if (s[6]==c && s[7]==c && s[8]==c) return 1;
	if (s[0]==c && s[3]==c && s[6]==c) return 1;
	if (s[1]==c && s[4]==c && s[7]==c) return 1;
	if (s[2]==c && s[5]==c && s[8]==c) return 1;
	if (s[0]==c && s[4]==c && s[8]==c) return 1;
	if (s[2]==c && s[4]==c && s[6]==c) return 1;
	return 0;
}
int main()
{
    int i,j,cha,quan,a,b,t,T;
    int ok;
	char r[10];
	scanf("%d",&T);
	for (t=0;t<T;t++)
	{
		for (i=0;i<3;i++)
		{
			scanf("%s",r);
			for (j=0;j<3;j++)
				s[i*3+j]=r[j];
		}
        cha=quan=0;
        ok=1;
        for (i=0;i<9;i++)
        {
            if (s[i]=='X') cha++;
            else if (s[i]=='O') quan++;
        }
		if (cha==quan || cha==quan+1)
		{
			a=find('X');
			b=find('O');
			if (a==1 && b==1) ok=0;
			else if (a==1 && cha==quan) ok=0;
			else if (cha==quan+1 && a==0 && b==1) ok=0;
		}
		else ok=0;
		if (ok) printf("yes\n");
        else printf("no\n");
    }
    return 0;
}
