#include "process.h"

vector<int> zFunc(const string& s, long long& cmp) {
    int n = s.size();
    vector<int> z(n, 0);
    int l = 0, rv = 0;
    for (int i = 1; i < n; i++) {
        if (i <= rv) z[i] = min(rv-i+1, z[i-l]);
        while (i+z[i] < n) { cmp++; if (s[z[i]] == s[i+z[i]]) z[i]++; else break; }
        if (i+z[i]-1 > rv) { l = i; rv = i+z[i]-1; }
    }
    return z;
}

vector<int> searchZ(const string& txt, const string& pat, long long& cmp) {
    vector<int> ans;
    int m = pat.size(), n = txt.size();
    if (m > n) return ans;
    string s = pat + "$" + txt;
    vector<int> z = zFunc(s, cmp);
    for (int i = m+1; i < (int)z.size(); i++)
        if (z[i] == m) ans.push_back(i-m-1);
    return ans;
}

vector<vector<result>> ZAlgorithm(vector<string> text, vector<string> pattern, long long& cmp) {
    int R = text.size(), C = text[0].size(), K = pattern.size();
    vector<vector<result>> res(K);
    for (int i = 0; i < K; i++) {
        string pat = pattern[i];
        int m = pat.size();
        if (m == 0 || (int)m > max(R, C)) continue;
        for (int row = 0; row < R; row++)
            for (int c : searchZ(text[row], pat, cmp))
                res[i].push_back({row, c, row, c+m-1});
        for (int col = 0; col < C; col++) {
            string s = "";
            for (int row = 0; row < R; row++) s += text[row][col];
            for (int r2 : searchZ(s, pat, cmp))
                res[i].push_back({r2, col, r2+m-1, col});
        }
    }
    return res;
}