#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <fstream>
using namespace std;

struct result{
    int x1,y1,x2,y2;
};
typedef vector<vector<result>> (*StringMatchingFunction)(vector<string> text, vector<string> pattern,  long long &  count_comparison);


string getAlgoName(const string& algorithm);
StringMatchingFunction StringAlgorithm(const string& algorithm);
pair<double,long long> measureTimeCompare(const string algorithm, vector<string>& text, vector<string> pattern,vector<vector<result>> &res);
void ReadFile(string filename,vector<string> & text, vector<string> & pattern);
void WriteFile(const string filename,string algorithm ,vector<vector<result>> ans, vector<string> &pattern, pair<double,long long> TimeCmp);
void RunCommand(string algorithm, string inputfile, string outputfile);