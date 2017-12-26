#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<sstream>
using namespace std;
int n;
vector<string> dirs;
vector<vector<string> > dir_v;
void print_dir(vector<string> &v,int indent){
    for(int i=indent;i<v.size();i++)
        cout<<string(i,' ')<<v[i]<<endl;
}
int main()
{
    cin>>n;
    string dir;
    for(int i=0;i<n;i++){
        cin>>dir;
        for(int j=0;j<dir.size();j++)
            if(dir[j]=='\\') dir[j]=' ';
        dirs.push_back(dir);
    }
    sort(dirs.begin(),dirs.end());
    for(int i=0;i<n;i++){
        dir_v.push_back(vector<string>());
        istringstream is(dirs[i]);
        while(is>>dir) dir_v.back().push_back(dir);
    }
    int indent = 0;
    print_dir(dir_v[0],indent);
    for(int i=1;i<dir_v.size();i++){
        indent = 0;
        while(indent<dir_v[i-1].size() && indent<dir_v[i].size() && dir_v[i][indent]==dir_v[i-1][indent]) indent++;
        print_dir(dir_v[i],indent);
    }
    return 0;
}
