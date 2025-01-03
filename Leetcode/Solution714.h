#pragma once
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

class Solution714 {
public:
    // ����dp[0][i]Ϊ�ڵ�i�챣�ֳ��е��ֽ�
    // ����dp[1][i]Ϊ�ڵ�i�챣���������ֽ�
    // dp[0][i] = max(dp[0][i - 1], dp[1][i] - fee - prices[0]);
    // dp[1][i] = max(dp[1][i - 1], dp[0][i] + prices[0]);
    int maxProfit(vector<int>& prices, int fee) {
        vector<vector<int>> dp(2, vector<int>(prices.size(), 0));
        dp[0][0] = -fee -prices[0];


        for (int i = 1; i < prices.size(); i++) {
            dp[0][i] = max(dp[0][i - 1], dp[1][i] - prices[0]);
            dp[1][i] = max(dp[1][i - 1], dp[0][i] + prices[0] - fee);
        }

        return dp[1][prices.size() - 1];
    }
};