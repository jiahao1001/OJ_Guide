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
#include<ctype.h>
using namespace std;
struct Project{
    string name;
    int cnt;
}project[100];
bool operator<(const Project &p1, const Project &p2)
{
    if(p1.cnt==p2.cnt) return p1.name<p2.name;
    return p1.cnt>p2.cnt;
}
int main(){

    string name;
    int n;
    while(true){
        getline(cin,name);
        map<string,int> cnt;
        map<string,string> signup;
        map<string,int> student; // 0 unsigned, 1 signed, 2, signed and dup
        if(name=="0") break;
        string prj;
        while(true){
            if(isupper(name[0])) prj = name,cnt[prj]=0;
            else{
                if(signup.count(name)){
                    //already signed
                    if(signup[name]==prj) {}//same project
                    else{
                        if(student[name]==1){
                            cnt[signup[name]] --;
                            student[name] = 2;
                        }
                    }
                    
                }else{
                    cnt[prj]++;
                    signup[name] = prj;
                    student[name] =1;
                }
            }
            getline(cin,name);
            if(name=="1") break;
        }
        n = 0;
        for(map<string,int>::iterator it=cnt.begin();it!=cnt.end();it++){
            project[n].name = it->first;
            project[n].cnt = it->second;
            n++;
        }
        
        sort(project,project+n);
        for(int i=0;i<n;i++)
            cout<<project[i].name<<" "<<project[i].cnt<<endl;
                
    }
}
