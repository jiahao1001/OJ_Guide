#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<map>
#include<set>
#include<string.h>
#include<queue>
#include<string>
#include<stdlib.h>
#include<vector>
using namespace std;
string pt="23456789TJQKA";
string cl="CDSH";
string dr="NESW";
string name[4]={"North","East","South","West"};
string deal;
string w;
struct Card{
    char p,c;
};
bool operator<(const Card& c1,const Card &c2){
    if(cl.find(c1.c)==cl.find(c2.c))
        return pt.find(c1.p)<pt.find(c2.p);
    return cl.find(c1.c)<cl.find(c2.c);
}
vector<Card> hand[4];

int main(){
    while(cin>>w,w[0]!='#'){
        for(int i=0;i<4;i++) hand[i].clear();
        int d = dr.find(w[0]);
        d = (d+1)%4;
        int t=2;
        while(t--){
            cin>>deal;
            for(int i=0;i<deal.size();i+=2){
                Card card;
                card.c = deal[i];
                card.p = deal[i+1];
                hand[d].push_back(card);
                d=(d+1)%4;
            }
        }
        for(int k=0;k<4;k++){
            int i = (k+2)%4;
            sort(hand[i].begin(),hand[i].end());
            cout<<name[i]<<" player:"<<endl;
            cout<<"+";
            for(int j=0;j<hand[i].size();j++) cout<<"---+";
            cout<<endl;
            cout<<"|";
            for(int j=0;j<hand[i].size();j++) cout<<hand[i][j].p<<" "<<hand[i][j].p<<"|";
            cout<<endl;
            
            cout<<"|";
            for(int j=0;j<hand[i].size();j++) cout<<" "<<hand[i][j].c<<" |";
            cout<<endl;
            
            cout<<"|";
            for(int j=0;j<hand[i].size();j++) cout<<hand[i][j].p<<" "<<hand[i][j].p<<"|";
            cout<<endl;
            cout<<"+";
            for(int j=0;j<hand[i].size();j++) cout<<"---+";
            cout<<endl;
        }
        cout<<endl;
    }
    return 0;
}
