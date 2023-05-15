#include<vector>
#include<iostream>
#include <bits/stdc++.h>
using namespace std;

void Input(vector<pair <int, int>> &B,int N){
  int v,w;
  for(int i=0;i<N;i++){
    v = i+1;
    w = i*i+1;
    B.push_back(pair<int, int>(v,w));
  }
}
bool cmp(pair<int,int> a, pair<int,int> b){
  return a.first/a.second < b.first/b.second;
}
int main()
{
  vector<pair <int, int>> Bag_Start; //first - value, second - weight
  int n; cout << "n: "; cin >> n;
  
  Input(Bag_Start, n);
   cout << "------\n";
  for(auto p: Bag_Start)  cout << p.first << " " << p.second << endl;
  
  std::sort(Bag_Start.begin(), Bag_Start.end(),cmp);
   cout << "------\n";
  for(auto p: Bag_Start)  cout << p.first << " " << p.second << endl;
  cout << "------\n";
  
  vector<pair <int, int>> Bag;
  int W; cout << "W: "; cin >> W;
  int weight_tmp = W;
  int sum_value = 0;
  
  for(auto p: Bag_Start){
    if(p.second < weight_tmp){
      sum_value += p.first; 
      weight_tmp -= p.second;
      Bag.push_back(p);
      cout << p.first << " " << p.second << endl;
      cout<< sum_value << endl;
      
    } 
  }
  cout << "------\nVALUE: " << sum_value << endl;
  for(auto p: Bag)  cout << p.first << " " << p.second << endl;
    return 0;
}