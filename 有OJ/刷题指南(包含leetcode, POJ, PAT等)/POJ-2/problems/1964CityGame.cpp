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
class Solution {
public:
    
    int largestRectangleArea(vector<int> &height) {
        int n=height.size();
        vector<int> left(n),right(n);
        for(int i=0;i<n;i++) left[i]=right[i]=i;
        for(int i=1;i<n;i++){
            int l=left[i];
            while(l>0 && height[i]<=height[l-1]) l=left[l-1];
            left[i]=l;
        }
        for(int i=n-2;i>=0;i--){
            int r=right[i];
            while(r+1<n&&height[i]<=height[r+1]) r=right[r+1];
            right[i]=r;
        }
        /* for(int i=0;i<n;i++)
         printf("%d ",left[i]);
         cout<<endl;
         for(int i=0;i<n;i++) printf("%d ",right[i]);
         cout<<endl;*/
        int ans=0;
        for(int i=0;i<n;i++) ans=max(ans,(right[i]-left[i]+1)*height[i]);
        return ans;
    }
    
    
    
    int maximalRectangle(vector<vector<char> > &matrix) {
        if(!matrix.size()) return 0;
        vector<int> h(matrix[0].size(),0);
        int ans=0;
        int n=matrix[0].size();
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<n;j++)
                if(matrix[i][j]=='1') h[j]++;
                else h[j]=0;
            ans=max(ans,largestRectangleArea(h));
        }
        return ans;
    }
};
int main(){
    int t,n,m;
    char c;
    Solution solution;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        vector<vector<char> > M(n,vector<char>(m,'0'));
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++){
                scanf(" %c",&c);
                if(c=='F') M[i][j] = '1';
            }
        printf("%d\n",solution.maximalRectangle(M)*3);
    }
    return 0;
}
