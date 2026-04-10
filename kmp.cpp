#include "process.h"

vector<int> buildF(const string& p) {
    int m = p.size();
    vector<int> F(m, 0);
    int k = 0;
    for (int i = 1; i < m; i++) {
        while (k > 0 && p[k] != p[i]) k = F[k-1];
        if (p[k] == p[i]) k++;
        F[i] = k;
    }
    return F;
}

vector<int> kmp1D(const string& text, const string& p, const vector<int>& F, long long& cmp) {
    vector<int> pos;
    int k = 0;
    for (int i = 0; i < (int)text.size(); i++) {
        while (k > 0) {
            cmp++;
            if(p[k] != text[i]) {
                k = F[k-1];
            }
            else break;
        }
        cmp++;
        if (p[k] == text[i]) k++;
        if (k == (int)p.size()) {
            pos.push_back(i - k + 1);
            k = F[k-1];
        }
    }
    return pos;
}

vector<vector<result>> KMP(vector<string> text, vector<string> pattern, long long& count_comparison) {
    int R = text.size();
    int C = text[0].size();
    int K = pattern.size();

    vector<vector<result>> ans(K);

    for (int i = 0; i < K; i++) {
        string word = pattern[i];
        int m = word.size();
        if (m == 0 || (int)m > max(R, C)) continue;

        auto F = buildF(word);

        // Tìm ngang
        for (int r = 0; r < R; r++) {
            for (int c : kmp1D(text[r], word, F, count_comparison)) {
                ans[i].push_back({r, c, r, c + m - 1});
            }
        }

        // Tìm dọc
        for (int c = 0; c < C; c++) {
            string col = "";
            for (int r = 0; r < R; r++) col += text[r][c];
            for (int r2 : kmp1D(col, word, F, count_comparison)) {
                ans[i].push_back({r2, c, r2 + m - 1, c});
            }
        }
    }

    return ans;
}