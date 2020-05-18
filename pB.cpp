#include <bits/stdc++.h>
using namespace std;


int main(){

  int t;
  int N;
  cin >> t;
  N = t;

while(t--){

int C,D;
cin >> C >> D;

vector<pair<int,int> > arr;
int arra[C];
int Xi;

arra[0] = 0;

for (int i=1; i<C; i++){
  cin >> Xi;
  arra[i] = -Xi;  
  arr.push_back(make_pair(-Xi,i));
}
vector<pair<pair<int,int>,int > > list;
vector<int> graph[C];
int u,v;
for (int i=0; i<D;i++){
  cin >> u >> v;
  u--;
  v--;
  graph[u].push_back(v);
  graph[v].push_back(u);
  list.push_back(make_pair(make_pair(u,v),1000000));
}

sort(arr.begin(),arr.end());

int ind = 0;

while (ind < C-1){
  int c,d;
  int w;
  int good;
  c = arr[ind].second;
  d = arr[ind].first;
  for (int j=0;j<(int) graph[c].size();j++){
   // cout << "testing " << c+1 << "--" << 1+graph[c][j] << endl; 
    if (arra[graph[c][j]] < d){
      good = graph[c][j];
      w = d - arra[graph[c][j]];
    }
  }
  for (int i=0; i<(int) list.size(); i++){
    if((list[i].first.first == c && list[i].first.second == good)||(list[i].first.first == good && list[i].first.second == c)){
      list[i].second = w;
    }
  }
  ind++;
}




  cout << "Case #" << N-t << ": ";
  
  for (int i=0; i< (int) list.size();i++){
    cout << " " << list[i].second;
  }  
  cout << endl;
}

}