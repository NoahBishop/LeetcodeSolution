#pragma once
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

class Solution188 {
public:
    // 定义dp[0][i]为在第i天不动的现金
    // 定义dp[1][i]为在第i天第一次持有股票的现金
    // 定义dp[2][i]为在第i天第一次减持有的现金
    // 定义dp[3][i]为在第i天第二次持有股票的现金
    // 定义dp[4][i]为在第i天第二次减持有的现金
    // 类推第k次
    // 可以当天买当天卖，对
    // dp[0] = 0
    // dp[1] = max(dp[1], dp[0] - price[i]);
    // 转移公式
    // dp[0][i] = max(dp[0][i - 1], dp[1][i - 1] + prices[i]); 昨天不持有和昨天持有今天卖出
    // dp[1][i] = max(dp[1][i - 1], 0 - prices[i]); 今天买入或者保持昨天一样

    int maxProfit(int k, vector<int>& prices) {
        if (prices.size() == 1) {
            return 0;
        }

        int tar = 2 * k + 1;

        vector<int> dp(tar, 0);
        for (int i = 1; i < tar; i++) {
            dp[i] = -prices[0];
        }
        for (int i = 1; i < prices.size(); i++) {
            for (int j = 1; j < tar; j++) {
                if (j % 2 == 1) {
                    dp[j] = max(dp[j], dp[j - 1] - prices[i]);
                }
                else {
                    dp[j] = max(dp[j], dp[j - 1] + prices[i]);
                }
            }
        }

        return dp[tar - 1];
    }
};