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
#include<string>
using namespace std;
int main()
{
    string word;
    int cnt = 0;
    bool first = true;
    while(cin>>word)
    {
        if(word=="<br>"){
            cout<<endl;
            cnt =0 ,first = true;
            continue;
        }
        if(word=="<hr>"){
            if(cnt) cout<<endl;
            for(int i=0;i<80;i++) cout<<"-";
            cout<<endl;
            cnt = 0, first = true;
            continue;
        }
        
        
        if(first){
            cout<<word;
            cnt += word.size();
            first = false;
        }else{
            if(cnt+1+word.size()<=80){
                cout<<" "<<word;
                cnt += 1+word.size();
            }else{
                cout<<endl;
                cout<<word;
                cnt = word.size();//first = true;
            }
        }
    }
    
    cout<<endl;
    return 0;
}
