#include <stdio.h>


int main(){
	char a[102];
	scanf("%s",a);

	int i,j,t=0,sum=0;
	char sign='+';

	for(i=0;a[i]!='=';i++){
		if(a[i]=='+'||a[i]=='-'){
			if(sign=='+')
				sum+=t;
			else sum-=t;
			sign=a[i];
			t=0;
		}
		t*=10;
		t+=a[i]-'0';
	}

	printf("%d",sum);


	return 0;
}