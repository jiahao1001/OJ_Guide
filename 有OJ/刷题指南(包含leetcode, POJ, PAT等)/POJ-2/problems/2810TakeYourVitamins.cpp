#include<iostream>
#include<stdio.h>
#include<string>
#include<vector>
using namespace std;
vector<string> small;
int main(){
    double x,y;
    string u,name;
    while(cin>>x>>u>>y){
        getline(cin,name);
        name = name.substr(1);
        //cout<<name;
        if(x<0) break;
        if(x/y<0.01) small.push_back(name);
        else
        printf("%s %.1f %s %.0f%%\n",name.c_str(),x,u.c_str(),100.0*x/y);
    }
    printf("Provides no significant amount of:\n");
    for(int i=0;i<small.size();i++)
        cout<<small[i]<<endl;
    return 0;
}
