#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
//没有这条sotr不能用
struct Student
{
	char name[101];
	int age;
	int grade;
};
bool cmp(Student A,Student B)
{	//这个不行，要写！=,因为除了<还有>=，自己改吧，参考另一个
	if(A.grade<B.grade)
		return true;
	else if(strcmp(A.name,B.name)<0)
		return true;
	else if(A.age<B.age)
		return true;
	else 
		return false;
}
int main()
{
	int n;
	int i;
	Student s[1000];
	while(scanf("%d",&n)!=EOF)
	{	
		for(i=0;i<n;i++)
			scanf("%s%d%d",s[i].name,&s[i].age,&s[i].grade);
		sort(s,s+n,cmp);
		for(i=0;i<n;i++)
			printf("%s %d %d\n",s[i].name,s[i].age,s[i].grade);
	}
	printf("\n");
	return 0;
}
