#include "process.h"

vector<vector<result>> BruteForce(vector<string>, vector<string>, long long&);
vector<vector<result>> KMP(vector<string> text, vector<string> pattern, long long& count_comparison);
vector<vector<result>> RapinKarp(vector<string> text, vector<string> pattern, long long& count_comparison);
vector<vector<result>> BoyerMoore(vector<string> text, vector<string> pattern, long long& count_comparision);
vector<vector<result>> ZAlgorithm(vector<string>, vector<string>, long long&);

string getAlgoName(const string& algorithm) {
    if(algorithm == "bf") return "Brute Force";
    if(algorithm == "rk") return "Rapin-Karp";
    if(algorithm == "kmp") return "KMP";
    if(algorithm == "bm") return "Boyer-Moore";
    if(algorithm == "z") return "Z-Algorithm";
    return algorithm;
}

StringMatchingFunction StringAlgorithm(const string& algorithm){
    if(algorithm == "bf") return BruteForce;
    if(algorithm == "rk") return RapinKarp;
    if(algorithm == "kmp") return KMP;
    if(algorithm == "bm") return BoyerMoore;
    if(algorithm == "z") return ZAlgorithm;
    return nullptr;
}

pair<double,long long> measureTimeCompare(const string algorithm, vector<string>& text, vector<string> pattern,vector<vector<result>> &res) {
    pair<double,long long> ans;
    long long cnt = 0;
    auto start = std::chrono::high_resolution_clock::now();

    StringMatchingFunction StringMatchingFunc = StringAlgorithm(algorithm);
    if (!StringMatchingFunc) {
        cout << "Algorithm not implemented: " << algorithm << endl;
        return {0, 0};
    }

    res = StringMatchingFunc(text,pattern,cnt);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration = end - start;
    ans.first = duration.count();
    ans.second = cnt;
    return ans;
}

void ReadFile(string filename,vector<string> & text, vector<string> & pattern){
    ifstream f(filename);
    if(!f) cout<<"File error"<<endl;
    else{
        int n,m;
        f>>n>>m;
        for(int i = 0;i < n;i++){
            string s = "";
            for(int j = 0 ; j < m;j++){
                char c;
                f >> c;
                s+=c;
            }
            text.push_back(s);
        }
        f>>n;
        for(int i = 0;i < n;i++){
            string s;
            f>>s;
            pattern.push_back(s);
        }
    }
    f.close();
}

void WriteFile(const string filename,string algorithm ,vector<vector<result>> ans, vector<string> &pattern, pair<double,long long> TimeCmp){
    ofstream f(filename);
    if(!f) cout<<"File error"<<endl;
    int n = pattern.size();
    for(int i =0;i < n;i++){
        f<<pattern[i]<<": ";
        if(ans[i].empty()){
            f<<"not found";
        } else{
            if(pattern[i].size() == 1){
                for(int j = 0 ; j < ans[i].size()/2;j++){
                    f<<"("<<ans[i][j].x1<<", "<<ans[i][j].y1<<") -> ("<<ans[i][j].x2<<", "<<ans[i][j].y2<<"); ";
                }
            }
            else for(result x : ans[i]){
                f<<"("<<x.x1<<", "<<x.y1<<") -> ("<<x.x2<<", "<<x.y2<<"); ";
            }
        }
        f<<endl;
    }
    f<<endl;
    f<<"---------------------------------"<<endl;
    f<<"Algorithm: "<<algorithm<<endl;
    f<<"Comparisons: "<<TimeCmp.second<<endl;
    f<<"Execution Time: "<<fixed<<setprecision(3)<<TimeCmp.first<<" ms"<<endl;
    f.close();
}

void RunCommand(string algorithm, string inputfile, string outputfile){
    vector<string> text;
    vector<string> pattern;
    ReadFile(inputfile,text,pattern);
    vector<vector<result>> ans;
    auto TimeCmp = measureTimeCompare(algorithm,text,pattern,ans);
    WriteFile(outputfile,getAlgoName(algorithm),ans,pattern,TimeCmp);
}