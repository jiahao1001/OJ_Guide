#include<iostream>
#include<stdio.h>
#include<string.h>
#include<utility>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<math.h>
#include<limits.h>
using namespace std;
int main()
{
    char s[40];
    int last = -1;
    double so_far = 0;
    int speed = 0;
    while(gets(s)){
        int len = strlen(s);
        int hh,mm,ss;
        if(len==8){
            sscanf(s,"%d:%d:%d",&hh,&mm,&ss);
            printf("%s %.2f km\n",s,so_far+speed*(hh*60*60+mm*60+ss-last)/3600.0);
        }else{
            int old = speed;
            sscanf(s,"%d:%d:%d %d",&hh,&mm,&ss,&speed);
            if(last!=-1)
                so_far += 1.0*old*(hh*3600+mm*60+ss-last)/3600.0;
            //cout<<"so_far "<<so_far<<endl;
            last = hh*60*60+mm*60+ss;
            //cout<<"last "<<last<<endl;
            
        }
        
    }
    return 0;
}
