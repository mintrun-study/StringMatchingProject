#include "process.h"

vector<vector<result>> RapinKarp(vector<string> text, vector<string> pattern, long long & count_comparison){
    int pattern_size = pattern.size();
    int d = 31;
    long long q = 1e9 + 7;
    vector<vector<result>> res(pattern_size);
    vector<int> m(pattern_size);
    int n = text.size();
    for(int i = 0;i < pattern_size;i++){
        m[i] = pattern[i].size();
    }
    vector<long long> h(pattern_size,1);
    vector<long long> t(pattern_size,0);
    vector<long long> p(pattern_size,0);
    for(int i = 0; i < pattern_size;i++){
        for(int j = 0; j < m[i] - 1;j++){
            h[i] = (h[i]*d)%q;
        }
    }

    
    for(int i = 0; i <pattern_size;i++){
            for(int j = 0; j < m[i];j++){
                p[i] = (d*p[i]+pattern[i][j])%q;
            }
        }
    //Duyệt Ngang trước;
    for(int row = 0;  row < n;row++){
        for(int i =0;i < pattern_size;i++){
            t[i] = 0;
            for(int j = 0;  j < m[i]; j++){
                t[i] = (d * t[i] + text[row][j]) % q;
            }
            for(int j = 0;  j <= n - m[i];j++){
                if(p[i] == t[i]){
                    bool match = true;
                    for(int x = 0;  x < m[i];x++){
                        if(++count_comparison && text[row][j+x] != pattern[i][x]){
                            match = false;
                            break;
                        }
                    }
                    if(match){
                        result ans = {row,j,row,j+m[i] - 1};
                        res[i].push_back(ans);
                    }
                }
                if(j < n - m[i]){
                    t[i] = (d * (t[i] - text[row][j] * h[i]) + text[row][j+m[i]]) % q;
                }
            }
        }
    }
    
    
    //Duyệt hàng dọc
     for(int col = 0; col < text[0].size();col++){
        for(int i =0;i < pattern_size;i++){
            t[i] = 0;
            for(int j = 0;  j < m[i]; j++){
                t[i] = (d * t[i] + text[j][col]) % q;
            }
            for(int j = 0; j <= text[0].size() - m[i];j++){
                if(p[i] == t[i]){
                    bool match = true;
                    for(int x = 0;x < m[i];x++){
                        if(++count_comparison && text[j+x][col] != pattern[i][x]){
                            match = false;
                            break;
                        }
                    }
                    if(match){
                        result ans = {j,col,j+m[i] - 1,col};
                        res[i].push_back(ans);
                    }
                }
                if( j < text[0].size() - m[i]){
                    t[i] = (d * (t[i] - text[j][col] * h[i]) + text[j+m[i]][col]) % q;
                }
            }
        }
    }
    return res;
}