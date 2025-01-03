#pragma once
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

class Solution583 {
public:
    // 定义dp[i][j]为A以i为结束元素的和出现B以j为结束元素的最大重复长度
    // 如果word1[i] == word1[j], dp[i][j] = dp[i - 1][j - 1] + 1;
    // 如果word1[i] != word1[j], dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.length(), vector<int>(word2.length(), 0));

        int maxl = 0;
        for (int i = 0; i < word1.length(); i++) {
            for (int j = 0; j < word2.length(); j++) {
                if (word1[i] == word2[j]) {
                    if (i != 0 && j != 0) {
                        dp[i][j] = dp[i - 1][j - 1] + 1;
                    }
                    else {
                        dp[i][j] = 1;
                    }
                }
                else {
                    if (i == 0 && j == 0) {
                        dp[i][j] = 0;
                    }
                    else if (i == 0 && j != 0) {
                        dp[i][j] = max(0, dp[i][j - 1]);
                    }
                    else if (j == 0 && 1 != 0) {
                        dp[i][j] = max(dp[i - 1][j], 0);
                    }
                    else {
                        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                    }
                }
                maxl = max(maxl, dp[i][j]);
            }
        }
        return word1.length() + word2.length() - 2 * maxl;
    }
};