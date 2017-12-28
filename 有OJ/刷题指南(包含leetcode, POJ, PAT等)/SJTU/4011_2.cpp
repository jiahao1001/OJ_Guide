#include<iostream>
using namespace std;
class BigInt
{
private:
    int contain[100];
    int size;
public:
    BigInt(int n = 0)
    {
        size = 0;
        int temp;
        while((temp=n%10)!=0)
        {
            contain[size++] = temp;
            n/=10;
        }
    }
    BigInt & operator=(int n)
    {
        size = 0;
        int temp;
        while((temp=n%10)!=0)
        {
            contain[size++] = temp;
            n/=10;
        }
        return *this;
    }
    BigInt & operator=(const BigInt & b)
    {
        size = b.size;
        for(int i = 0; i < size; ++i)
        {
            contain[i] = b.contain[i];
        }
        return *this;
    }
    BigInt operator+(const BigInt & b)
    {
        int len1 = size;
        int len2 = b.size;
        int first_part = (len1>len2)?len2:len1;
        bool up = 0;
        int temp;
        BigInt res(0);
        res.size = 0;
        int i;
        for(i = 0; i < first_part;++i)
        {
            temp = contain[i]+b.contain[i]+up;
            res.contain[res.size++] = temp % 10;
            up = temp/10;
        }
        if(len1 > len2) for(;i < len1;++i)
        {
            temp = contain[i]+up;
            res.contain[res.size++] = temp % 10;
            up = temp/10;
        }else for(;i < len2;++i)
        {
            temp = b.contain[i]+up;
            res.contain[res.size++] = temp % 10;
            up = temp/10;
        }
        if(up)
        {
            res.contain[res.size++] = 1;
        }
        return res;
    }
    BigInt operator+(const int & x)
    {
        return *this+BigInt(x);
    }
    BigInt operator+=(const BigInt & b)
    {
        return *this = *this + b;
    }
    BigInt operator+=(const int & x)
    {
        return *this = *this + x;
    }
    friend ostream & operator<<(ostream & os, BigInt & b);
};
ostream & operator<<(ostream & os, BigInt & b)
{
    for(int i = b.size-1;i >= 0;--i)
    {
        os << b.contain[i];
    }
    return os;
}
int main()
{
    int k, h;
    cin >> k >> h;
    BigInt * n = new BigInt[k+1];
    BigInt * temp = new BigInt[k+1];
    BigInt * ptr;
    for(int i = 1; i <= k; ++i)
    {
        if(i==k) n[i]=1;
        else n[i] = 0;
    }
    for(int i = 1; i < h; ++i)
    {
        for(int j = 1; j <= k; ++j)
        {
            temp[j] = 0;
            for(int l = k; l > k-j; --l)
            {
                temp[j] += n[l];
            }
        }

        ptr = temp;
        temp = n;
        n = ptr;
    }
    BigInt res = 0;
    for(int i = 1; i <= k; ++i) res+=n[i];
    cout << res;
    return 0;
}
