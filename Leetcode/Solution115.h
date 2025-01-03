#pragma once
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

class Solution115 {
public:
    // 定义dp[i][j]为A以i为结束元素的序列中出现B以j为结束元素的连续序列的次数
    // 如果s[i] == t[j], 那么可以选用这个元素匹配 dp[i][j] += dp[i - 1][j - 1]
    // 也可以不用这个元素匹配 dp[i][j] += dp[i - 1][j];
    // 如果s[i] != t[j], dp[i][j] = dp[i - 1][j];

    int numDistinct(string s, string t) {
        vector<vector<unsigned long long>> dp(s.length(), vector<unsigned long long>(t.length(), 0));
        for (int i = 0; i < s.length(); i++) {
            for (int j = 0; j < t.length(); j++) {
                if (s[i] == t[j]) {
                    if (i != 0 && j != 0) {
                        dp[i][j] += dp[i - 1][j - 1];
                        dp[i][j] += dp[i - 1][j];
                    }
                    else if (i != 0 && j == 0) {
                        dp[i][j] += dp[i - 1][j];
                        dp[i][j] += 1;
                    }
                    else if (i == 0 && j == 0) {
                        dp[i][j] = 1;
                    }
                    else {
                        // i == 0, j != 0
                        // 此时不能让过去匹配的继续使用，所以是 0
                    }
                }
                else {
                    if (i != 0) {
                        dp[i][j] = dp[i - 1][j];
                    }
                    else {
                        dp[i][j] = 0;
                    }
                }
            }
        }
        return dp[s.length() - 1][t.length() - 1];
    }
};