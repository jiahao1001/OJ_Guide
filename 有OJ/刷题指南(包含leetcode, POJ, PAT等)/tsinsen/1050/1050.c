#include <cstdio> 
#include <iostream> 
#include <cstdlib> 
#include <cstring> 
using namespace std; 

int main() 
{ 
char s[1001]; 
scanf("%s",s); 
int len,i,ans=0; 
len=strlen(s); 
for (i=0;i<len;i++) 
if (s[i]=='C'|| s[i]=='G') ans++; 
double a=double(ans)/double(len)*100; 
printf("%.0lf\n",a); 
return 0; 
}  



// //可以运行、十分精简但是会超时的代码
// #include <stdio.h>
// int main(){
//     char c;
//     int i=0,j=0;
//     while((c=getchar())!='\n'){
//         if(c=='G'||c=='C')i++;
//         j++;
//     }
//     printf("%.0f\n",(double)i/(double)j*100);
//     return 0;
// }