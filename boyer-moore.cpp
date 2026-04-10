#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <time.h>
#include <chrono>
using namespace std;
using namespace std::chrono;

struct result{
    int x1,y1,x2,y2;
};

void badCharRule(string s, vector<vector<int>> &badchar) {
    for (int i=1; i <= s.size(); i++) {
        for (int j=0; j<256; j++) badchar[j][i] = badchar[j][i-1];
        badchar[(int)s[i-1]][i] = i-1;
    }
}

void goodSuffixRule(string s, vector<int> &shift) {
    vector<int> bpos(s.size()+1, 0);
    int i = s.size(), j = s.size()+1;
    bpos[i] = j;

    //case 1
    while (i > 0) {
        while (j <= s.size() && s[i-1] != s[j-1]) {
            if (shift[j] == 0) shift[j] = j-i;
            j = bpos[j];
        }

        i--; j--; bpos[i] = j;
    }

    //case 2
    j = bpos[0];
    for (int i=0; i<=s.size(); i++) {
        if (shift[i] == 0) shift[i] = j-i;
        if (i == j) j = bpos[j];
    }
}

vector<int> search(string txt, string pat, const vector<vector<int>> &badchar, const vector<int> &shift, long long &cmp) {
    vector<int> ans;
    if (pat.size() > txt.size()) return ans;

    int m = pat.size();
    int n = txt.size();

    int s = 0;
    while (s <= n-m) {
        int j = m-1;
        while (j >= 0 && ++cmp && pat[j] == txt[s + j]) j--;
        if (j < 0) {
            ans.push_back(s);
            // mismatch at txt[s+m]
            s += max((s + m < n) ? m - badchar[txt[s + m]][m] : 1, shift[0]); 
        }
        else { //mismatch at txt[s+j]
            s += max(j - badchar[txt[s + j]][j], shift[j+1]);
        }
    }
    return ans;
}


vector<vector<result>> BoyerMoore(vector<string> text, vector<string> pattern, long long& count_comparision) {
    vector<vector<result>> res;
    
    for (string pat : pattern) {
        int m = pat.size();
        vector<vector<int>> badchar(256, vector<int>(m+1, -1));
        badCharRule(pat, badchar);
    
        vector<int> shift(m+1, 0);
        goodSuffixRule(pat, shift);
        
        vector<result> ans;
        int row = 0;
        for (string txt : text) {
            vector<int> cur = search(txt, pat, badchar, shift, count_comparision);
            for (int i : cur) {
                result r{row, i, row, i+(int)pat.size()-1};
                ans.push_back(r);
            }
            row++;
        }
        for (int col=0; pat.size()>1 && col<text[0].size(); col++) {
            string txt="";
            for (int row=0; row<text.size(); row++) txt+=text[row][col];
            vector<int> cur = search(txt, pat, badchar, shift, count_comparision);
            for (int i : cur) {
                result r = {i, col, i+(int)pat.size()-1, col};
                ans.push_back(r);
            }
        }
        res.push_back(ans);
    }
    return res;
}
void output(vector<vector<result>> res, vector<string> pattern, long long cmp, double time) {
    // for (int q=0; q < pattern.size(); q++) {
    //     cout << pattern[q]<<": ";
    //     for (result tmp : res[q]) cout << "("<<tmp.x1<<", "<<tmp.y1<<") -> ("<<tmp.x2<<", "<<tmp.y2<<"); ";
    //     if (res[q].empty()) cout<<"not found";
    //     cout<<'\n';
    // }
    
    cout<<"\n-------------------------------\nAlgorithm: Boyer-Moore\n";
    cout<<"Comparisons: "<<cmp<<'\n';
    cout<<"Execution Time: "<<time<<" ms\n";
}
