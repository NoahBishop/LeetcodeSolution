#pragma once
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

class Solution123 {
public:
    // 定义dp[0][i]为在第i天第一次减持有的现金
    // 定义dp[1][i]为在第i天第一次持有股票的现金
    // 定义dp[2][i]为在第i天第二次减持有的现金
    // 定义dp[3][i]为在第i天第二次持有股票的现金
    // 因为最多买2次那么,初始状态
    // dp[0][0] 当天卖当天卖, dp[1][0] 当天买入
    // dp[0][0] = 0; dp[1][0] = -prices[0]; dp[2][0] = 0; dp[3][0] = -prices[0];
    // 转移公式
    // dp[0][i] = max(dp[0][i - 1], dp[1][i - 1] + prices[i]); 昨天不持有和昨天持有今天卖出
    // dp[1][i] = max(dp[1][i - 1], 0 - prices[i]); 今天买入或者保持昨天一样

    int maxProfit(vector<int>& prices) {
        if (prices.size() == 1) {
            return 0;
        }
        else if (prices.size() == 2) {
            return prices[1] - prices[0] > 0 ? prices[1] - prices[0] : 0;
        }

        vector<vector<int>> dp(4, vector<int>(2, 0));
        dp[0][0] = 0;
        dp[1][0] = -prices[0];
        dp[2][0] = 0;
        dp[3][0] = -prices[0];
        for (int i = 1; i < prices.size(); i++) {
            dp[0][i % 2] = max(dp[0][(i - 1) % 2], dp[1][(i - 1) % 2] + prices[i]);
            dp[1][i % 2] = max(dp[1][(i - 1) % 2], 0 - prices[i]);
            dp[2][i % 2] = max(dp[2][(i - 1) % 2], dp[3][(i - 1) % 2] + prices[i]);
            dp[3][i % 2] = max(dp[3][(i - 1) % 2], dp[0][(i - 1) % 2] - prices[i]);
        }

        return dp[2][(prices.size() - 1) % 2];
    }
};