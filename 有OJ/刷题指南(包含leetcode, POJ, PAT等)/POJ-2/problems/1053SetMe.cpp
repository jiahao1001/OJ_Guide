#include<iostream>
#include<stdio.h>
#include<string>
#include<vector>
using namespace std;
inline bool same(char c1,char c2,char c3){
    return c1==c2 && c1==c3;
}
inline bool diff(char c1,char c2,char c3){
    return c1!=c2 && c1!=c3 && c2!=c3;
}
inline bool check(string c1,string c2,string c3){
    int good = 0;
    for(int i=0;i<4;i++)
        if(same(c1[i],c2[i],c3[i]) || diff(c1[i],c2[i],c3[i])) good++;
    return good==4;
}
int main()
{
    string card;
    while(true){
        bool has = false;
        vector<string> cards;
        while(getline(cin,card)){
            has = true;
            if(card=="")break;
            cards.push_back(card);
        }
        if(!has) break;
        cout<<"CARDS: ";
        for(int i=0;i<cards.size();i++)
            cout<<" "<<cards[i];
        cout<<endl;
        cout<<"SETS:   ";
        int cnt = 0;
        for(int i=0;i<cards.size();i++)
            for(int j=i+1;j<cards.size();j++)
                for(int k=j+1;k<cards.size();k++){
                    if(check(cards[i],cards[j],cards[k])){
                        cnt++;
                        if(cnt>1)printf("        ");
                        printf("%d.  %s %s %s\n",cnt,cards[i].c_str(),cards[j].c_str(),cards[k].c_str());
                    }
                }
        if(!cnt) printf("*** None Found ***\n");
        printf("\n");
        
    }
    return 0;
}
