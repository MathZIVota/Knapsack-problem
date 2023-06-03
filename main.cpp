#include"Knapsack.hpp"
#include <iomanip>
#include <math.h>
int main()
{
  vector<pair<string, int>> Tests{ 
  //first - filename, second - значение теста, к которому стремимся
{"ks_4_0",19},
{"ks_19_0",11080},
{"ks_10000_0",993511},
{"ks_1000_0",99124},
{"ks_100_0",93045},
{"ks_100_1",1272176},
{"ks_100_2",9816},
{"ks_200_0",99090},
{"ks_200_1",1067697},
{"ks_300_0",1638698},
{"ks_30_0",99045},
{"ks_400_0",3879439},
{"ks_40_0",99090},
{"ks_45_0",20939},
{"ks_500_0",48984},
{"ks_50_0",132960},
{"ks_50_1",4630},
{"ks_60_0",99045}
};
  int n, W;  //n - number of elements, W - bag weight
  vector<pair<pair<int, int>, int>> Bag; 
  //first - value, second - weight, third - index
  int Bag_free_weight=0;// Недобор веса в готовой сумке 
  int Bag_value=0; // Суммарная ценность вещей в готовой сумке
  vector<int> Bag_index; // Массив входящих элементов (1- входит, 0 - нет)
  cout << endl;
  cout << "Do you want to check all the tests or just one?\n(Enter 0-all, 1-one):"; 
  int variant; cin >> variant; 
  
  if (variant) 
  {
    cout << "Enter the filename:";
    string filename; cin >> filename;
    Bag_value = Solver(n, W, Bag, filename, Bag_index, Bag_free_weight);
    cout << Bag_value << " " << Bag_free_weight << endl;
    ofstream output_file("Result_one");
    output_file << filename<< ": ";
    output_file << Bag_value << " | ";
    output_file << Bag_free_weight << endl;
    for (auto x : Bag_index) output_file << x << " ";
    cout << "Success! Received values in the file: 'Result_one'\n";
  }
  else 
  {
    ofstream output_file("Result_all");
    output_file <<  "\tФайл" << ": Ценность сумки | Остаток веса | Идеальная ценность | Процент (отличие от идеального)\n";
    for (auto p : Tests) 
    {
        cout << p.first << endl;
        Bag_value = Solver(n, W, Bag, p.first, Bag_index, Bag_free_weight);
      
     //   cout << Bag_value << " | " << W - Bag_free_weight << " | " << p.second << " | " << (double)abs(Bag_value - p.second) / p.second * 100 << "%" << endl;
      output_file.setf(ios::fixed);
      output_file << setw(11) << p.first << ": ";
      output_file << setw(10) << Bag_value << " |\t";
      output_file << setw(10) << Bag_free_weight << " |\t";
      output_file << setw(9) << p.second << " |\t";
      output_file << setw(3) << (int)round((double)abs(Bag_value - p.second) / (double)p.second * 100) << " %" << endl;
    }
    output_file.close();
    cout << "Success! Received values in the file: 'Result_all'\n";
  }
  
  return 0;
}
