#include"Knapsack.hpp"

//Comparator for sorting
bool cmp(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
    return ((double)a.first.first / a.first.second < (double)b.first.first / b.first.second);
}

int Solver(int& n, int&W, vector<pair<pair<int,int>,int>> &Bag, string File_name, vector<int>&Bag_index,int& weight){ 
  //index - список входящих элементов, weight - занятый объём
  n = Input(Bag, W, File_name,Bag_index);
  
  sort(Bag.begin(), Bag.end(), cmp);

  weight = W;
  int value = 0;
  
  for (auto item: Bag) {
    if (item.first.second <= weight) {
      value += item.first.first;
      weight -= item.first.second;
      Bag_index[item.second] = 1;
    }
  }
  return value;
}