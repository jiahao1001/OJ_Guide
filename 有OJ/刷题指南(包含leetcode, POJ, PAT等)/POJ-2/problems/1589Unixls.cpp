#include<iostream>
#include<string>
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int n;
vector<string> fs;
void output(int i,int len){
    int p;
    if(i>=n) p = len;
    else{
        p = len-fs[i].size();
        cout<<fs[i];
    }
    cout<<string(p,' ');
}
int main()
{
    while(scanf("%d",&n)!=EOF){
        int len = 0;
        fs.resize(n);
        for(int i=0;i<n;i++)
            cin>>fs[i], len = max(len,(int)fs[i].size());
        sort(fs.begin(),fs.end());
        int C = 1;
        while(true){
            if(C*len+(C-1)*2>60) break;
            C++;
        }
        C--;
        int p = 60-(C*len+(C-1)*2);
        //C columns
        int R = 1;
        if(n>=C){
            while(true){
                if(R*C-R<n && n<=R*C) break;
                R++;
            }
        }
        //printf("%d %d\n",R,C);
        cout<<string(60,'-')<<endl;
        
        for(int i=0;i<R;i++)
            for(int j=0;j<C;j++){
                if(j)cout<<"  ";
                output(j*R+i,len);
                if(j==C-1)cout<<string(p,' ')<<endl;
            }
    }
    return 0;
}
