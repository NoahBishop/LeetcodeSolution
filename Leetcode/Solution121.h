#pragma once
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

class Solution121 {
public:
    // ����dp[i]Ϊ�ڵ�i���������ͼ۸�
    // ��ô���������������������
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

    // ����dp[0][i]Ϊ�ڵ�i�첻���е��ֽ�
    // ����dp[1][i]Ϊ�ڵ�i����й�Ʊ���ֽ�
    // ��Ϊֻ����һ����ô,��ʼ״̬
    // dp[0][0] = 0; dp[1][0] = -prices[0];
    // ת�ƹ�ʽ
    // dp[0][i] = max(dp[0][i - 1], dp[1][i - 1] + prices[i]); ���첻���к�������н�������
    // dp[1][i] = max(dp[1][i - 1], 0 - prices[i]); ����������߱�������һ��
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