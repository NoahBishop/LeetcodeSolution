#pragma once
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

class Solution516 {
public:
    // 定义dp[i][j]为s从下标[i,j]的闭合区间内的回文序列长度
    // 如果s[i] == s[j], 
    // 如果j == i dp[i][j] = 1;
    // 如果j = i + 1 dp[i][j] = 2;
    // j - i >= 2 时 dp[i][j] = dp[i + 1][j - 1] + 2;
    // 如果s[i] != s[j], dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    int longestPalindromeSubseq(string s) {
        vector<vector<int>> dp(s.length(), vector<int>(s.length(), 0));
        for (int i = s.length() - 1; i >= 0; i--) { // 结束位置
            for (int j = i; j < s.length(); j++) {     // 开始位置
                if (s[i] == s[j]) {
                    if (j == i) {
                        dp[i][j] = 1;
                    }
                    else if (j == i + 1) {
                        dp[i][j] = 2;
                    }
                    else {
                        dp[i][j] = dp[i + 1][j - 1] + 2;
                    }
                }
                else {
                    if (j - i == 1) {
                        dp[i][j] = 1;
                    }
                    else {
                        dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                    }
                }
            }
        }
        return dp[0][s.length() - 1];
    }
};