#include<vector>
#include<iostream>
#include <algorithm> //sort
using namespace std;

//Data entry (from the keyboard)
void Input(vector<pair<pair<int, int>,int>> &B,int N){
    int i=0;
  for(auto &p:B){
    cin >> p.first.first >> p.first.second;
    p.second = i;
    i++;
  }
}
//Comparator for sorting
bool cmp(pair<pair<int,int>,int> a, pair<pair<int,int>,int> b){
  return (a.first.first/a.first.second < b.first.first/b.first.second);
}

int main()
{
  int n, W;  cin >> n >> W;
  vector<pair<pair<int, int>,int>> Bag(n); //first - value, second - weight
  Input(Bag, n);
  
  std::sort(Bag.begin(), Bag.end(),cmp);
  
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
  cout << sum_value << endl;
  for(auto x: flag) cout << x << " ";
  cout << endl;
  
 // for(auto p: Bag)  cout << p.second << ":" << p.first.first << " " << p.first.second << endl;
  return 0;
}