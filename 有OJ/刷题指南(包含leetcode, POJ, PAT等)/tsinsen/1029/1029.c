#include <iostream>
using namespace std;
int maxmin_0(int a,int b,int c,int *max,int *min)
{
    *max=(a>b?a:b)>c?(a>b?a:b):c;
    *min=(a<b?a:b)<c?(a<b?a:b):c;
}
int maxmin_1(int a,int b,int c,int &max,int &min)
{
    max=(a>b?a:b)>c?(a>b?a:b):c;
    min=(a<b?a:b)<c?(a<b?a:b):c;
}