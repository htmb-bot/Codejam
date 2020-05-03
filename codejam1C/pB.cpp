#include <bits/stdc++.h>
#include <iostream> 
#include <set> 
using namespace std;

bool comp(pair<char,long long> a, pair<char,long long> b){
  return a.second < b.second;
}

int main(){

  long long t;
  long long N;
  cin >> t;
  N = t;

while(t--){

  long long u;
  cin >> u;
  set <char> letters;
  vector<char> firsts;
  pair<char,long long> num[10];
  long long nletters = 0;
   
  for (long long i=0; i< 10000;i++){
    long long Q;
    cin >> Q;
    string s;
    cin >> s;
    firsts.push_back(s[0]);
    if (nletters < 10){
      for (long long j = 0; j< (long long) s.size(); j++){
        letters.insert(s[j]);
      }
      nletters = letters.size();
    }
  }

    long long i = 0;
    for (set<char>::iterator it=letters.begin(); it != letters.end(); ++it) 
    { 
    num[i] = make_pair(*it,0);
    i++;
    } 

for (long long i=0; i< (long long) firsts.size();i++){
  for (int j=0; j<10;j++){
    if (num[j].first == firsts[i]){
      num[j].second ++;
    }
  }
}

sort(num,num+10,comp);

string st = ""; 
st += num[0].first;
for (int i=9; i>0;i--)
  st += num[i].first;

cout << "Case #" << N-t << ": " << st << endl;

}

}