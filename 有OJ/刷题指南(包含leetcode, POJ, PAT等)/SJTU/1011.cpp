#include <iostream>
using namespace std;
class MyComplex
{
private:
    double x,y;
public:
    friend istream& operator>>(istream& in,MyComplex& c);
    friend ostream& operator<<(ostream& out,const MyComplex& c);
    friend MyComplex operator+(const MyComplex& z1,const MyComplex& z2);
    friend MyComplex operator-(const MyComplex& z1,const MyComplex& z2);
    friend MyComplex operator*(const MyComplex& z1,const MyComplex& z2);
    friend MyComplex operator/(const MyComplex& z1,const MyComplex& z2);
    friend MyComplex& operator+=(MyComplex& z1,MyComplex& z2);
    friend MyComplex& operator-=(MyComplex& z1,MyComplex& z2);
    friend MyComplex& operator*=(MyComplex& z1,MyComplex& z2);
    friend MyComplex& operator/=(MyComplex& z1,MyComplex& z2);
};
istream& operator>>(istream& in,MyComplex& c)
{
    in>>c.x>>c.y;
    return in;
}
ostream& operator<<(ostream& out,const MyComplex& c)
{
    out<<c.x<<' '<<c.y;
    return out;
}
MyComplex operator+(const MyComplex& z1,const MyComplex& z2)
{
    MyComplex tmp;
    tmp.x=z1.x+z2.x;
    tmp.y=z1.y+z2.y;
    return tmp;
}
MyComplex operator-(const MyComplex& z1,const MyComplex& z2)
{
    MyComplex tmp;
    tmp.x=z1.x-z2.x;
    tmp.y=z1.y-z2.y;
    return tmp;
}
MyComplex operator*(const MyComplex& z1,const MyComplex& z2)
{
    MyComplex tmp;
    tmp.x=z1.x*z2.x-z1.y*z2.y;
    tmp.y=z1.x*z2.y+z1.y*z2.x;
    return tmp;
}
MyComplex operator/(const MyComplex& z1,const MyComplex& z2)
{
    MyComplex tmp;
    double r=z2.x*z2.x+z2.y*z2.y;
    tmp.x=(z1.x*z2.x+z1.y*z2.y)/r;
    tmp.y=(-z1.x*z2.y+z1.y*z2.x)/r;
    return tmp;
}
MyComplex& operator+=(MyComplex& z1,MyComplex& z2)
{
    z1=z1+z2;
    return z1;
}
MyComplex& operator-=(MyComplex& z1,MyComplex& z2)
{
    z1=z1-z2;
    return z1;
}
MyComplex& operator*=(MyComplex& z1,MyComplex& z2)
{
    z1=z1*z2;
    return z1;
}
MyComplex& operator/=(MyComplex& z1,MyComplex& z2)
{
    z1=z1/z2;
    return z1;
}
int main()
{
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    MyComplex z1;
    MyComplex z2;
    cin>>z1>>z2;
    cout<<z1+z2<<endl;
    cout<<z1-z2<<endl;
    cout<<z1*z2<<endl;
    cout<<z1/z2<<endl;
    cout<<(z1+=z2)<<endl;
    cout<<(z1-=z2)<<endl;
    cout<<(z1*=z2)<<endl;
    cout<<(z1/=z2)<<endl;
    return 0;
}
