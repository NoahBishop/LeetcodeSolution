#pragma once
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

class Solution123 {
public:
    // ����dp[0][i]Ϊ�ڵ�i���һ�μ����е��ֽ�
    // ����dp[1][i]Ϊ�ڵ�i���һ�γ��й�Ʊ���ֽ�
    // ����dp[2][i]Ϊ�ڵ�i��ڶ��μ����е��ֽ�
    // ����dp[3][i]Ϊ�ڵ�i��ڶ��γ��й�Ʊ���ֽ�
    // ��Ϊ�����2����ô,��ʼ״̬
    // dp[0][0] ������������, dp[1][0] ��������
    // dp[0][0] = 0; dp[1][0] = -prices[0]; dp[2][0] = 0; dp[3][0] = -prices[0];
    // ת�ƹ�ʽ
    // dp[0][i] = max(dp[0][i - 1], dp[1][i - 1] + prices[i]); ���첻���к�������н�������
    // dp[1][i] = max(dp[1][i - 1], 0 - prices[i]); ����������߱�������һ��

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