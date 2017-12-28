#include <iostream>
using namespace std;
bool tt[9];
bool glitch(int &a,int &b,int &c,int &d,int &e,int &f,int &g,int &h,int &i)
{
    int j;for (j=0;j<9;++j) tt[j]=true;
    tt[a-1]=false;tt[b-1]=false;tt[c-1]=false;tt[d-1]=false;tt[e-1]=false;tt[f-1]=false;tt[g-1]=false;tt[h-1]=false;tt[i-1]=false;
    for (j=0;j<9;++j) if (tt[j]) return true;
    return false;
}
bool test(int x[][9])
{
    if (glitch(x[0][0],x[0][1],x[0][2],x[0][3],x[0][4],x[0][5],x[0][6],x[0][7],x[0][8])) return false;
    if (glitch(x[1][0],x[1][1],x[1][2],x[1][3],x[1][4],x[1][5],x[1][6],x[1][7],x[1][8])) return false;
    if (glitch(x[2][0],x[2][1],x[2][2],x[2][3],x[2][4],x[2][5],x[2][6],x[2][7],x[2][8])) return false;
    if (glitch(x[3][0],x[3][1],x[3][2],x[3][3],x[3][4],x[3][5],x[3][6],x[3][7],x[3][8])) return false;
    if (glitch(x[4][0],x[4][1],x[4][2],x[4][3],x[4][4],x[4][5],x[4][6],x[4][7],x[4][8])) return false;
    if (glitch(x[5][0],x[5][1],x[5][2],x[5][3],x[5][4],x[5][5],x[5][6],x[5][7],x[5][8])) return false;
    if (glitch(x[6][0],x[6][1],x[6][2],x[6][3],x[6][4],x[6][5],x[6][6],x[6][7],x[6][8])) return false;
    if (glitch(x[7][0],x[7][1],x[7][2],x[7][3],x[7][4],x[7][5],x[7][6],x[7][7],x[7][8])) return false;
    if (glitch(x[8][0],x[8][1],x[8][2],x[8][3],x[8][4],x[8][5],x[8][6],x[8][7],x[8][8])) return false;

    if (glitch(x[0][0],x[1][0],x[2][0],x[3][0],x[4][0],x[5][0],x[6][0],x[7][0],x[8][0])) return false;
    if (glitch(x[0][1],x[1][1],x[2][1],x[3][1],x[4][1],x[5][1],x[6][1],x[7][1],x[8][1])) return false;
    if (glitch(x[0][2],x[1][2],x[2][2],x[3][2],x[4][2],x[5][2],x[6][2],x[7][2],x[8][2])) return false;
    if (glitch(x[0][3],x[1][3],x[2][3],x[3][3],x[4][3],x[5][3],x[6][3],x[7][3],x[8][3])) return false;
    if (glitch(x[0][4],x[1][4],x[2][4],x[3][4],x[4][4],x[5][4],x[6][4],x[7][4],x[8][4])) return false;
    if (glitch(x[0][5],x[1][5],x[2][5],x[3][5],x[4][5],x[5][5],x[6][5],x[7][5],x[8][5])) return false;
    if (glitch(x[0][6],x[1][6],x[2][6],x[3][6],x[4][6],x[5][6],x[6][6],x[7][6],x[8][6])) return false;
    if (glitch(x[0][7],x[1][7],x[2][7],x[3][7],x[4][7],x[5][7],x[6][7],x[7][7],x[8][7])) return false;
    if (glitch(x[0][8],x[1][8],x[2][8],x[3][8],x[4][8],x[5][8],x[6][8],x[7][8],x[8][8])) return false;

    if (glitch(x[0][0],x[0][1],x[0][2],x[1][0],x[1][1],x[1][2],x[2][0],x[2][1],x[2][2])) return false;
    if (glitch(x[0][3],x[0][4],x[0][5],x[1][3],x[1][4],x[1][5],x[2][3],x[2][4],x[2][5])) return false;
    if (glitch(x[0][6],x[0][7],x[0][8],x[1][6],x[1][7],x[1][8],x[2][6],x[2][7],x[2][8])) return false;

    if (glitch(x[3][0],x[3][1],x[3][2],x[4][0],x[4][1],x[4][2],x[5][0],x[5][1],x[5][2])) return false;
    if (glitch(x[3][3],x[3][4],x[3][5],x[4][3],x[4][4],x[4][5],x[5][3],x[5][4],x[5][5])) return false;
    if (glitch(x[3][6],x[3][7],x[3][8],x[4][6],x[4][7],x[4][8],x[5][6],x[5][7],x[5][8])) return false;

    if (glitch(x[6][0],x[6][1],x[6][2],x[7][0],x[7][1],x[7][2],x[8][0],x[8][1],x[8][2])) return false;
    if (glitch(x[6][3],x[6][4],x[6][5],x[7][3],x[7][4],x[7][5],x[8][3],x[8][4],x[8][5])) return false;
    if (glitch(x[6][6],x[6][7],x[6][8],x[7][6],x[7][7],x[7][8],x[8][6],x[8][7],x[8][8])) return false;
    return true;
}
int main()
{
    int n,i,j,k;bool rec[20];
    cin>>n;
    int x[9][9];
    for (i=0;i<n;++i)
    {
        for (j=0;j<9;++j) for (k=0;k<9;++k) cin>>x[j][k];
        rec[i]=test(x);
    }
    for (i=0;i<n;++i)
    {
        if (rec[i]) cout<<"Right"<<endl;
        else cout<<"Wrong"<<endl;
    }
}
