#include "process.h"

vector<int> searchBF(const string& txt, const string& pat, long long& cmp) {
    vector<int> ans;
    int n = txt.size(), m = pat.size();
    for (int i = 0; i <= n - m; i++) {
        int j = 0;
        while (j < m) { cmp++; if (txt[i+j] != pat[j]) break; j++; }
        if (j == m) ans.push_back(i);
    }
    return ans;
}

vector<vector<result>> BruteForce(vector<string> text, vector<string> pattern, long long& cmp) {
    int R = text.size(), C = text[0].size(), K = pattern.size();
    vector<vector<result>> res(K);
    for (int i = 0; i < K; i++) {
        string pat = pattern[i];
        int m = pat.size();
        if (m == 0 || (int)m > max(R, C)) continue;
        for (int row = 0; row < R; row++)
            for (int c : searchBF(text[row], pat, cmp))
                res[i].push_back({row, c, row, c+m-1});
        for (int col = 0; col < C; col++) {
            string s = "";
            for (int row = 0; row < R; row++) s += text[row][col];
            for (int r2 : searchBF(s, pat, cmp))
                res[i].push_back({r2, col, r2+m-1, col});
        }
    }
    return res;
}