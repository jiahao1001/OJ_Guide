#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
  double x1,x2,x3,x4,y1,y2,y3,y4;
  cin >> x1 >> y1 >> x2 >> y2;
  cin >> x3 >> y3 >> x4 >> y4;
  if( x1 > x2 ) swap( x1,x2);
  if( y1 > y2 ) swap( y1,y2);    
  if( x3 > x4 ) swap( x3,x4);  
  if( y3 > y4 ) swap( y3,y4);  
  double x = min(x2,x4) - max(x1,x3);
  x = x<0? 0.0:x;
  double y = min(y2,y4) - max(y1,y3);
  y = y<0? 0.0:y;
  cout.precision(2); 
  cout << fixed << x*y << endl;
}