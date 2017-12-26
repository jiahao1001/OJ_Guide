#include <iostream>

using namespace std;


struct info
{
    string name;
    int score;
    int jingsheng;
    int jinqiu;
    
};

int compare(struct info a, struct info b){

    //diff score
    if(a.score>b.score)return 1;
    if(a.score<b.score)return -1;

    //same score
    //diff jingsheng
    if(a.jingsheng>b.jingsheng)return 1;
    if(a.jingsheng<b.jingsheng)return -1;

    //same jingsheng
    //diff jinqiu
    if(a.jinqiu>b.jinqiu)return 1;
    if(a.jinqiu<b.jinqiu)return -1;

    //same jinqiu
    //diff name
    int i=0;
    while(a.name[i]==b.name[i])
        i++;
    if(a.name[i]>b.name[i])return -1;
    else return 1;
}

int main(){
    int n,i,j;
    cin>>n;
    struct info teams[10];
    struct info temp;

    for(i=0;i<n;i++){
        cin>>teams[i].name;
        cin>>teams[i].score;
        cin>>teams[i].jingsheng;
        cin>>teams[i].jinqiu;
    }

    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++){
            if(-1==compare(teams[j],teams[j+1])){
                temp=teams[j];
                teams[j]=teams[j+1];
                teams[j+1]=temp;
            }
        }
    }

    for(i=0;i<n;i++){
        cout<<teams[i].name<<endl;
    }



    return 0;
}