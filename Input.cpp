#include"Knapsack.hpp"

//Data entry (from the keyboard)
int Input(vector<pair<pair<int, int>, int>>& B, int&W, string filename,vector<int>&Bag_index) {
    int i = 0, n = 0;
    ifstream input_file(filename);
    
    if (input_file.is_open()) {
        input_file >> n >> W;
        B.resize(n);
        for (auto& p : B) {
            p.second = 0;
            p.first.first = 0;
            p.first.second = 0;
        }
        for (auto& p : B) {
            input_file >> p.first.first >> p.first.second;
            p.second = i;
            i++;
        }
        Bag_index.resize(n);
        for (auto& x: Bag_index) x=0;
    }
    input_file.close();
    return n;
}
