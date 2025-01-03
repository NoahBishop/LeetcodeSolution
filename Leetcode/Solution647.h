#pragma once
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

class Solution647 {
public:
    // 定义dp[i][j]为s从下标[i,j]的闭合区间是否为回串
    // 如果s[i] == s[j], 那么j - i <= 1 时 同一个位置或者相隔位置
    // dp[i][j] = true;
    // j - i >= 2 时 dp[i][j] = dp[i + 1][j - 1];
    // 如果s[i] != s[j], 一定不是回串 dp[i][j] = false;
    int countSubstrings(string s) {
        vector<vector<bool>> dp(s.length(), vector<bool>(s.length(), 0));
        int cnt = 0;
        for (int j = 0; j < s.length(); j++) { // 结束位置
            for (int i = 0; i <= j; i++) {     // 开始位置
                if (s[i] == s[j]) {
                    // 同一个位置或者相隔位置
                    if (j - i <= 1) {
                        dp[i][j] = true;
                    }
                    else {
                        dp[i][j] = dp[i + 1][j - 1];
                    }
                }
                else {
                    dp[i][j] = false;
                }
                if (dp[i][j]) {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};