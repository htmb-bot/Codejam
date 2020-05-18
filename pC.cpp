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
  angle = (double) (A.y-B.y)/((double)(A.x-B.x));
  origin = (double) (B.x*A.y-A.x*B.y)/(B.x-A.x);
}



};

int find(int tab[], int i){
  if (tab[i] == -1){
          cout << "NOTFOUND" << endl;
    return -1;
  }
  else if (tab[i] == i){
        cout << "FOUND" << endl;
    return i;
  }
  else{
          cout << "FINDING" << endl;
    return (find(tab,tab[i]));
  }
}


int main(){

  int t;
  int N;
  cin >> t;
  N = t;

while(t--){

int n;
cin >> n;

long long x;
long long y;

vector<point> cloud; 

for (int i=0; i<n;i++){
  cin >> x;
  cin >> y;
  cloud.push_back(point(2*x+1,2*y+1,i));
}

if (n<=3){

  cout << "Case #" << N-t << ": " << n << endl;  

}
else{

int maxpower = 4;

vector<segment> edges;

for (int i=0; i<n; i++){
  for (int j=i+1; j<n; j++){
    edges.push_back(segment(cloud[i],cloud[j]));
  }
}

double pente;
double eps = 0.00001;

for (int k=0; k< n*(n-1)/2;k++){
  pente =edges[k].angle;
  cout << "testpente="<< pente << endl;
  int clusters[n];
  int power = 0;
  for (int i=0; i<n; i++){
    clusters[i] = -1;
  }  
  clusters[edges[k].A.ind] = edges[k].A.ind;
  clusters[edges[k].B.ind] = edges[k].A.ind;  
  for (int i=0; i<n*(n-1)/2;i++){
    cout << "pente="<< edges[i].angle << endl;
    if (abs(edges[i].angle-pente)<eps){
      if (clusters[edges[i].A.ind] == -1){
        clusters[edges[i].A.ind] = edges[i].B.ind;
      }
      else{
        clusters[edges[i].B.ind] = edges[i].A.ind;
      }
    }
  } 
  
  int pow[n];
  for (int i=0; i<n;i++) pow[i] = 0;
  
  for(int i=0; i<n; i++){
    int f;
    f = find(clusters,i);
    if (f != -1){
      pow[f]++;
    }
  }
      cout << "HAAAAA" << endl;  
  int numlines = 0;
  int oneline;
  int odd = 0;
  
  for (int i=0; i<n;i++){
    if (pow[i] != 0) {
    numlines++;
    oneline = pow[i];
    }
    if (pow[i]%2 == 1){
      odd++;
    }
  }
  
  if (numlines==1){
    power = oneline;
    power = min(n,power+2-(power%2));
  }
  else {
    if (odd <= 1){
      for (int i=0; i<n;i++){
        power += pow[i];
      }
      if (odd == 0){
      power = min(n,power +1);
      power = min(n,power +1);
      }
      else{
        power = min(n,power +1);
      }
    }
    else {
      cout << "HAAAAA" << endl;
      int odd1 = 1;
      int odd2 = 1;
      for (int i=0; i<n;i++){
        if (pow[i]%2 ==0){
          power += pow[i];
        }
        else 
        {
          if (odd1<pow[i]){
            odd2 = odd1;
            odd1 = pow[i];
          }
          else if (odd2<pow[i]){
            odd2 = pow[i];
          }
        
        }
      }
      power += odd1 - 1;
      power += odd2;
    }
  
  
  }
  cout << "testpower="<< power << endl;
  if (power > maxpower){
    maxpower = power;
  }  
}


  cout << "Case #" << N-t << ": " << maxpower << endl;  
}
}
}