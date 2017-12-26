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
    int i,cha,quan,a,b;
    int ok;
    while (scanf("%s",s),strcmp (s,"end")!= 0)
    {
        cha=quan=0;
        ok=0;
        for (i=0;i<9;i++)
        {
            if (s[i]=='X') cha++;
            if (s[i]=='O') quan++;
        }
		if (cha==quan || cha==quan+1)
		{
			a=find('X');
			b=find('O');
			if (cha==quan && a==0 && b==1) ok=1;
			else if (cha==quan+1 && a==1 && b==0) ok=1;
			else if (cha+quan==9 && b==0) ok=1;
		}
		if (ok) printf("valid\n");
        else printf("invalid\n");
    }
    return 0;
}
