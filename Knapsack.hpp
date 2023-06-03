#pragma once
#include<vector>
#include<iostream>
#include<algorithm> 
#include<fstream>
using namespace std;

int Input(vector<pair<pair<int, int>, int>>&, int&, string,vector<int>&);
bool cmp(pair<pair<int, int>, int>, pair<pair<int, int>, int>);
int Solver(int&, int&, vector<pair<pair<int,int>,int>>&, string, vector<int>&,int&);