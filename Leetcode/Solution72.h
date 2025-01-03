#pragma once
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

class Solution72 {
public:
    // 定义dp[i + 1][j + 1]为A以i为结束元素的序列和B以j为结束元素转变的最小操作
    // 如果word1[i] == word2[j], 那么dp[i + 1][j + 1] = dp[i][j]; 即不用操作
    // 否则可能需要增加，删除，或者替换
    // 因为对一个的增加 等价与 另一个删除, 替换只需要从dp[i][j]位置后, 使word1[i] == word2[j]
    // 所以 dp[i + 1][j + 1] = min(dp[i][j], dp[i + 1][j] , dp[i][j + 1]) + 1;
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.length() + 1, vector<int>(word2.length() + 1, 0));

        for (int i = 1; i < word1.length(); i++) {
            dp[i][0] = i;
        }
        for (int i = 1; i < word2.length(); i++) {
            dp[0][i] = i;
        }

        for (int i = 0; i < word1.length(); i++) {
            for (int j = 0; j < word2.length(); j++) {
                if (word1[i] == word2[j]) {
                    dp[i + 1][j + 1] = dp[i][j];
                }
                else {
                    dp[i + 1][j + 1] = min({ dp[i][j], dp[i + 1][j], dp[i][j + 1] }) + 1;
                }
            }
        }
        return dp[word1.length()][word2.length()];
    }
};