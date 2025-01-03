#pragma once
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

class Solution309 {
public:
    // 定义dp[0][i]为在第i天保持持有的现金
    // 定义dp[1][i]为在第i天保持卖出的现金
    // 定义dp[2][i]为在第i天进行卖出股票的现金
    // 定义dp[3][i]为在第i天处于冷静期间
    // dp[0][i] 可能是从昨天持有,或者前一天是冷静期或者保持卖出
    // dp[0][i] = max(dp[0][i - 1], max(dp[1][i - 1], dp[3][i - 1]) - prices[i]);
    // dp[1][i] = max(dp[1][i - 1], dp[3][i - 1]);
    // dp[2][i] = dp[0][i - 1] + prices[i];
    // dp[3][i] = dp[2][i - 1];
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(4, vector<int>(prices.size(), 0));
        dp[0][0] = -prices[0];


        for (int i = 1; i < prices.size(); i++) {
             dp[0][i] = max(dp[0][i - 1], max(dp[1][i - 1], dp[3][i - 1]) - prices[i]);
             dp[1][i] = max(dp[1][i - 1], dp[3][i - 1]);
             dp[2][i] = dp[0][i - 1] + prices[i];
             dp[3][i] = dp[2][i - 1];
        }

        return max(dp[1][prices.size() - 1],max(dp[3][prices.size() - 1], dp[2][prices.size() - 1]));
    }
};