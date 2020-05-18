#include <bits/stdc++.h>
using namespace std;

struct point{

long long x;
long long y;
int ind;

point(){
  x = 0;
  y = 0;
  ind = 0;
}

point(long long _x, long long _y, int _i){
  x = _x;
  y = _y;
  ind = _i;
}

};



struct segment{

point A;
point B;
double angle;
double origin;
segment(){
A = point();
B = point();
angle = 0;
origin = 0;
}
segment(point _A, point _B){
  A = _A;
  B = _B;
  angle = (double) (A.x-B.x)/((double)(A.y-B.y));
  origin = (double) (B.x*A.y-A.x*B.y)/(B.x-A.x);
}



};
int main(){

point p1,p2;
segment s;

p1 = point(0,0,0);
p2 = point(5,1,1);
s = segment(p1,p2);

cout << s.angle << s.A.x << s.A.y << s.B.x << s.B.y << endl;
}