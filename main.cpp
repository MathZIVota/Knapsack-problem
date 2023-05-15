/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
/*
#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int N; cout << "N:"; cin >> N;
    vector<pair<pair<int,int>,int>> vec(N);
    int i=1;
    for(auto &v: vec) {v.first.first = i*i; v.first.second = -i*i; v.second = i; i++;}
    for(auto &v: vec) cout << v.second << ":" << v.first.first << " " << v.first.second << endl;
    return 0;
}
*/
#include<vector>
#include<iostream>
#include <bits/stdc++.h>
using namespace std;

void Input(vector<pair<pair<int, int>,int>> &B,int N){
    int i=0;
  for(auto &p:B){
    cin >> p.first.first >> p.first.second;
    p.second = i;
    i++;
  }
  
}
bool cmp(pair<pair<int,int>,int> a, pair<pair<int,int>,int> b){
  return ((a.first.first)/(a.first.second) < (b.first.first)/(b.first.second));
}

int main()
{
  int n, W;  cin >> n >> W;
  vector<pair<pair<int, int>,int>> Bag(n); //first - value, second - weight
  cout << "Size Bag: " << Bag.size() << endl;
  Input(Bag, n);
  
  std::sort(Bag.begin(), Bag.end(),cmp);
  
  cout << "n:" << n << endl;
  cout << "W:" << W << endl;
  cout << "-------\n";
  for(auto p: Bag)  cout << p.second << ":"<< p.first.first << " " << p.first.second << endl;
   cout << "-------\n";
   
  int weight_tmp = W;
  int sum_value = 0;
  vector<int> flag(n);
  
  for(auto p: Bag){
    if(p.first.second <= weight_tmp){
      sum_value += p.first.first; 
      weight_tmp -= p.first.second;
      flag[p.second] = 1;
      
    } 
  }
  for(auto x: flag) cout << x << " ";
  cout << endl;
  cout << "------\nVALUE: " << sum_value << endl;
  for(auto p: Bag)  cout << p.second << ":" << p.first.first << " " << p.first.second << endl;
  return 0;
}