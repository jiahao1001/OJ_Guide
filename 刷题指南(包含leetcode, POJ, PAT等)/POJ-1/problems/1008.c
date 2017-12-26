#include<stdio.h>
#include<string.h>
int main()
{
	int n,i,j,k,d,y,p;
	char m[19][7]={"pop","no","zip","zotz","tzec","xul","yoxkin","mol","chen","yax","zac","ceh","mac","kankin","muan","pax","koyab","cumhu","uayet"},s[7];
	char a[20][9]={"imix","ik","akbal","kan","chicchan","cimi","manik","lamat","muluk","ok","chuen","eb","ben","ix","mem","cib","caban","eznab","canac","ahau"};
	scanf("%d",&n);
	printf("%d\n",n);
	for (i=0;i<n;i++)
	{
		scanf("%d. %s %d",&d,s,&y);
		for (j=0;j<19;j++)
		{
			if (strcmp(m[j],s)==0)
				break;
		}
		p=y*365+j*20+d;
		y=p/260;
		p-=y*260;
		j=p%20;
		d=p%13+1;
		printf("%d %s %d\n",d,a[j],y);
	}
	return 0;
}
