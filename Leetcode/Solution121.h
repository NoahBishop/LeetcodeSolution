#pragma once
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

class Solution121 {
public:
    // 定义dp[i]为在第i天买入的最低价格
    // 那么反向遍历那天卖出的收益
    int maxProfit(vector<int>& prices) {
        vector<int> dp(prices.size());
        dp[0] = INT32_MAX;
        for (int i = 0; i < prices.size() - 1; i++) {
            dp[i + 1] = min(dp[i], prices[i]);
        }

        int profit = 0;
        for (int i = prices.size() - 1; i > 0; i--) {
            profit = max(profit, prices[i] - dp[i]);
        }

        return profit;
    }

    // 定义dp[0][i]为在第i天不持有的现金
    // 定义dp[1][i]为在第i天持有股票的现金
    // 因为只能买一次那么,初始状态
    // dp[0][0] = 0; dp[1][0] = -prices[0];
    // 转移公式
    // dp[0][i] = max(dp[0][i - 1], dp[1][i - 1] + prices[i]); 昨天不持有和昨天持有今天卖出
    // dp[1][i] = max(dp[1][i - 1], 0 - prices[i]); 今天买入或者保持昨天一样
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(2, vector<int>(2, 0));
        dp[0][0] = 0; dp[1][0] = -prices[0];
        for (int i = 1; i < prices.size(); i++) {
            dp[0][i % 2] = max(dp[0][(i - 1) % 2], dp[1][(i - 1) % 2] + prices[i]);
            dp[1][i % 2] = max(dp[1][(i - 1) % 2], 0 - prices[i]);
        }

        return dp[0][(prices.size() - 1) % 2];
    }
};