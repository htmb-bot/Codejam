#include <bits/stdc++.h>
using namespace std;


int main(){

  int t;
  int N;
  cin >> t;
  N = t;

while(t--){

long long r,l,n;

cin >> l >> r;

long long i=1;
while (i<=l || i<=r){
    if (r>l) r -= i;
    else l-=i;
  i++;
}
cout << "Case #" << N-t << ": " << i-1 << " " << l << " " << r << endl;
}

}