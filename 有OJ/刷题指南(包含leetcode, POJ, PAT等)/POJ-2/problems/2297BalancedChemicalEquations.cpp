#include<iostream>
#include<stdio.h>
#include<math.h>
#include<vector>
#include<string.h>
#include<stack>
#include<set>
#include<string>
#include<limits.h>
#include<algorithm>
using namespace std;
const int INF = INT_MAX/2;
const int DEBUG = 0;
string equation;

int n; //number of molecule, number of X (columns)
int m; //number of atoms, number of equations (rows)
int molecule_end[20];//upper bound
int M[20][20];
string atom[20];
inline void get_atom(){
    set<string> atom_set;
    for(int i=0;i<equation.size();i++){
        if(!isupper(equation[i])) continue;
        string a = string(1,equation[i]);
        if(i+1<equation.size() && islower(equation[i+1])) 
            a+=equation[i+1];
        atom_set.insert(a);        
    }
    m = 0;
    for(set<string>::iterator it=atom_set.begin();it!=atom_set.end();it++)
        atom[m++] = *it;
}
inline void get_molecule(){
    n = 0;
    for(int i=0;i<equation.size();i++){
        if(equation[i]=='+' || equation[i]=='=') molecule_end[n++]=i;
    }
    molecule_end[n++] = equation.size();
    
}
inline void initialize(){
    memset(M,0,sizeof(M));
    int r,c;
    int sign = 1;
    for(int i=0;i<equation.size();i++){
        if(equation[i]=='=') sign = -1;
        if(!isupper(equation[i])) continue;
        string a = string(1,equation[i]);
        int cnt = 1;
        if(i+1<equation.size()){
            if(isdigit(equation[i+1])) cnt = equation[i+1]-'0';
            else if(islower(equation[i+1])){
                a+=equation[i+1];
                if(i+2<equation.size() && isdigit(equation[i+2])) cnt = equation[i+2]-'0';
            }
        }
        r =  lower_bound(atom,atom+m,a)-atom;
        c = upper_bound(molecule_end,molecule_end+n,i)-molecule_end;
        M[r][c] += sign*cnt;
    }
    if(DEBUG)
    for(int i=0;i<m;i++){
        printf("%3s",atom[i].c_str());
        for(int j=0;j<n;j++) printf("%5d",M[i][j]);
        printf("\n");
    }
}
int x_free[20];//is Xi free?
inline void swap_row(int i,int j){
    if(i==j) return;
    swap(atom[i],atom[j]);
    for(int k=0;k<n+1;k++) swap(M[i][k],M[j][k]);
}
int gcd(int a,int b){
    if(!b) return a;
    return gcd(b,a%b);
}
int lcm(int x,int y){
    x=abs(x), y = abs(y);
    return x/gcd(x,y)*y;
}
inline void eliminate(int k,int i){
    int g = lcm(M[k][i],M[i][i]);
    int a = g/abs(M[k][i]), b = g/abs(M[i][i]);
    int sign;
    if(M[k][i]*M[i][i]>0) sign = -1;
    else sign = 1;
    for(int j=0;j<n+1;j++)
        M[k][j] = M[k][j]*a+sign*b*M[i][j];
}
void print_matrix(){
    if(DEBUG)
    for(int i=0;i<m;i++){
        printf("%3s",atom[i].c_str());
        for(int j=0;j<n+1;j++) printf("%3d",M[i][j]);
        printf("\n");
    }
}
inline int guass(){
    memset(x_free,0,sizeof(x_free));
    int rank = 0;
    int row=0;
    int n_free = 0;
    for(int i=0;row<m && i<n;){
        int pivot = INF, pivot_i = -1;
        for(int k=row;k<m;k++)
            if(M[k][i]!=0 && abs(M[k][i]<pivot)) pivot = abs(M[k][i]), pivot_i = k;
        if(pivot==INF) {
            x_free[i] = 1;
            i++;
            n_free ++;
            continue;
        }
        //printf("row %d i=%d\n",row,i);
        swap_row(row,pivot_i);
        rank++;
        print_matrix();
        //printf("-----\n");
        for(int k=0;k<m;k++) if(k!=row && M[k][i]!=0) eliminate(k,row);
        //printf("after eli\n");
        print_matrix();
        i++,row++;
    }
    print_matrix();
    //printf("rank %d\n",rank);
    for(int k=rank+n_free;k<n;k++) x_free[k] = 1;
    if(DEBUG){
        for(int i=0;i<n;i++)
            printf("%d ",x_free[i]);
        printf("\n");
    }
    for(int k=row;k<m;k++) if(M[k][n+1]!=0) return -1;
    
    return 0;
    
}
int best = INF;
int X[20];
void update(){
    if(DEBUG){
        
        for(int i=0;i<n;i++)
            printf("%d ",X[i]);
        printf("\n");
    }
    
    int tmp = 0;
    int rows = 0;
    int i=0;
    while(rows<n){
        if(x_free[rows]){
            tmp = tmp*10+X[rows];
        }else{
            int sum = 0;
            for(int k=rows+1;k<n;k++)
                if(x_free[k]) sum+=X[k]*M[i][k];
            if((M[i][n+1]-sum)%M[i][rows]) return;
            int d = (M[i][n+1]-sum)/M[i][rows];
            if(d<1 || d>9) return;
            tmp = tmp*10+d;
            i++;
        }
        if(DEBUG)
        printf("tmp %d\n",tmp);
        rows++;
    }
    best = min(best,tmp);
}
void dfs(int cur){
    if(cur==n){
        update();
        return;
    }
    if(x_free[cur]){
        for(int i=1;i<=9;i++)
            X[cur]=i,dfs(cur+1);
    }else dfs(cur+1);
}


void print_answer(int answer){
    int co[20],cnt=0;
    while(answer) co[cnt++]=answer%10, answer/=10;
    for(int i=cnt-1;i>=0;i--)
        if(!i)printf("%d",co[i]);
        else printf("%d ",co[i]);
    printf("\n");
    return;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>equation;
        //get molecule
        best = INF;
        get_atom();
        get_molecule();
        initialize();
        if(guass()==-1) {
            printf("IMPOSSIBLE\n");
            continue;
        }
        
        dfs(0);
        if(best==INF) printf("IMPOSSIBLE\n");
        else print_answer(best);
    }
}
