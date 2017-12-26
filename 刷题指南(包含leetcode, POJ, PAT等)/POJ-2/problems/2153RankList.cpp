#include<iostream>
#include<stdio.h>
#include<string.h>
#include<vector>
#include<utility>
#include<queue>
#include<limits.h>
#include<map>
#include<string>
using namespace std;
const int N = 10000;
struct Student{
    string name;
    int score;
} students[N];
bool operator<(const Student &s1, const Student &s2){
    if(s1.score == s2.score) return s1.name=="Li Ming";
    return s1.score>s2.score;
}
int n,m;
map<string,int> rk;
int main()
{
    string name;
    int score;
    cin>>n;
    getline(cin,name);
    for(int i=0;i<n;i++) getline(cin,name),students[i].name = name, students[i].score = 0,rk[name] = i+1;
    cin>>m;
    while(m--){
        for(int i=0;i<n;i++){
            cin>>score;
            getline(cin,name);
            name = name.substr(1);
            students[rk[name]-1].score+=score;
        }
        sort(students,students+n);
        //for(int i=0;i<n;i++){
        //  cout<<students[i].name<<" "<<students[i].score<<endl;
        //}
        for(int i=0;i<n;i++) rk[students[i].name] = i+1;
        cout<<rk["Li Ming"]<<endl;
    }
    return 0;
}
