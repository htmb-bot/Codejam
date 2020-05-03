#include <bits/stdc++.h>
using namespace std;


int main(){

  int t;
  int N;
  cin >> t;
  N = t;

while(t--){

int X,Y,M;
cin >> X >> Y;

int dist = abs(X)+abs(Y);
int time = -1;

vector<pair<int,int> > traj;

string s;
cin >> s;
M = (int) s.length();
char dir;

traj.push_back(make_pair(X,Y));

for (int i=0;i<M;i++){

  dir = s[i];
  if (dir == 'S')
    Y --;
  else if (dir == 'N')
    Y++;
  else if (dir == 'E')
    X++;
  else if (dir == 'W')
    X--;
  traj.push_back(make_pair(X,Y));
}

for (int i=0; i<M+1; i++){
  //cout << traj[i].first << " " << traj[i].second << " " << i << endl;
  if (abs(traj[i].first)+abs(traj[i].second) <= i){
    time = i;
    break;
  }
}

if (time == -1)
  cout << "Case #" << N-t << ": " << "IMPOSSIBLE" << endl;
else
  cout << "Case #" << N-t << ": " << time << endl;  
}

}