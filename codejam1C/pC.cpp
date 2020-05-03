#include <bits/stdc++.h>
#include <iostream> 
#include <set> 
using namespace std;

bool comp(pair<long long,int> a, pair<long long,int> b){
  if (a.second < b.second){
    return true;
  }
  else if (a.second > b.second)
    return false;
  else
    return a.first > b.first;
}

bool isdouble(vector<pair<long long, int> > num, int M){
  for (int i=0; i<M; i++){
    for (int j=0; j<M;j++){
      if (num[i].first == 2*num[j].first)
        return true;
    }
  }
  return false;
}

int main(){

  long long t;
  long long N;
  cin >> t;
  N = t;

while(t--){

int n,d;
cin >> n >> d;
long long tab[n];
set <long long> myset;
vector<pair<long long, int> > num;

for (int i=0; i<n;i++){
  cin >> tab[i];
  myset.insert(tab[i]);
}

    for (set<long long>::iterator it=myset.begin(); it != myset.end(); ++it) 
    { 
    num.push_back(make_pair(*it,0));
    } 

for (int i=0; i< n;i++){
  for (int j=0; j< (int) num.size();j++){
    if (num[j].first == tab[i]){
      num[j].second ++;
      continue;
    }
  }
}

sort(num.begin(),num.end(),comp);
int M = (int) num.size();
if (d == 2){
  if (num[M-1].second>1){
cout << "Case #" << N-t << ": " << 0 << endl;  
  }
  else {
cout << "Case #" << N-t << ": " << 1 << endl;    
  }
}
if (d == 3){
  if (num[M-1].second>2){
cout << "Case #" << N-t << ": " << 0 << endl;  
  }
  else {
  if (num[M-1].second == 2){
    bool b = false;
    for (int i=0; i<M-1;i++){
      if (num[i].first>num[M-1].first)
        b = true;
    }
    if (b){
cout << "Case #" << N-t << ": " << 1 << endl;        
    }
    else {
      if (isdouble(num,M)){
cout << "Case #" << N-t << ": " << 1 << endl;              
      }
      else {
cout << "Case #" << N-t << ": " << 2 << endl;                    
      }
    }
  }
  else {
  if (isdouble(num,M))
    cout << "Case #" << N-t << ": " << 1 << endl;              
  else
    cout << "Case #" << N-t << ": " << 2 << endl;              
  }
  
if (d>3){

if (num[M-1].second >= d){
    cout << "Case #" << N-t << ": " << 0 << endl;              
}






}  
  
  
  
  
  
  }
}



}
}