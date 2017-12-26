#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
vector<string> lst;
void print(int cur,int ed,int iii){
    //print dir in ind level (recursive)
    //and collection all the files, sort them
    //printf("print %d %d \n",cur,ed);
    vector<string> files;
    int level = 0;
    int a,b;
    for(int i=cur;i<ed;i++){
        if(level==0 && lst[i][0]=='f') files.push_back(lst[i]);
        else if(lst[i][0]=='d') {
            level++;
            if(level==1){
                for(int j=0;j<iii+1;j++)
                    cout<<"|     ";
                cout<<lst[i]<<endl;
                a = i+1;
            }
        }
        else if(lst[i][0]==']') {
            level--;
            if(level==0){
                b = i;
                print(a,b,iii+1);
            }
        }
    }
    sort(files.begin(),files.end());
    for(int i=0;i<files.size();i++)
    {
        for(int j=0;j<iii;j++)
            cout<<"|     ";
        cout<<files[i]<<endl;
    }
}
int main()
{
    int q=1;
    string name;
    while(cin>>name,name!="#"){
        
        cout<<"DATA SET "<<q++<<":\n";
        lst.clear();
        //lst.push_back("ROOT");
        lst.push_back(name);
        while(cin>>name,name!="*") lst.push_back(name);
        //lst.push_back("]");
        cout<<"ROOT"<<endl;
        print(0,lst.size(),0);
        cout<<endl;
    }
    return 0;
}
