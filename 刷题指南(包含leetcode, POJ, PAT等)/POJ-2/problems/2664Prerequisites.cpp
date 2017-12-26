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

string taken[100];
int k,m;
int r[100];
set<string> course[100];
string s;
int n;
bool check(){
    for(int i=0;i<m;i++){
        int cnt = 0;
        for(int j=0;j<k;j++){
            if(course[i].count(taken[j])) cnt++;
        }
        if(cnt<r[i]) return false;
    }
    return true;
}
int main()
{
    while(cin>>k,k){
        cin>>m;
        for(int i=0;i<k;i++)
            cin>>taken[i];
        for(int i=0;i<m;i++){
            cin>>n;
            cin>>r[i];
            course[i].clear();
            for(int j=0;j<n;j++){
                cin>>s;
                course[i].insert(s);
            }
        }
        if(check()) cout<<"yes"<<endl;
        else cout<<"no"<<endl;
        
    }
    return 0;
}
