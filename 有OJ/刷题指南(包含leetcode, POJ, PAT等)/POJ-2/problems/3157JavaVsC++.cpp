#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <string.h>
#include <ctime>
#include <ctype.h>
#include <climits>
using namespace std;
string id;
int main()
{
    cin>>id;
    bool has_underscore = false;
    bool has_upper = false;
    for(int i = 0;i<id.size();i++){
        if(id[i]=='_') has_underscore = true;
        if(isupper(id[i])) has_upper = true;
    }
    if(!has_underscore && !has_upper){
        cout<<id<<endl;
        return 0;
    }
    if((has_underscore && has_upper)|| id[id.size()-1]=='_' || id[0]=='_'){
        cout<<"Error!"<<endl;
        return 0;
    }
    if(has_upper && isupper(id[0])){
        cout<<"Error!"<<endl;
        return 0;
    }
    if(has_upper){
        //Java
        string c_id="";
        for(int i=0;i<id.size();i++){
            if(isupper(id[i])) c_id+="_"+string(1,tolower(id[i]));
            else c_id+=string(1,id[i]);
        }
        cout<<c_id<<endl;
        return 0;
    }
    if(has_underscore){
        //C++
        string j_id = "";
        bool up = false;
        for(int i=0;i<id.size();i++){
            if(up){
                if(id[i]=='_'){
                    cout<<"Error!"<<endl;
                    return 0;
                }else{
                    j_id+=string(1,toupper(id[i]));
                    up = false;
                }
            }else{
                if(id[i]=='_') up = true;
                else j_id+=string(1,id[i]);
            }
        }
        cout<<j_id<<endl;
        return 0;
    }
    return 0;
}
