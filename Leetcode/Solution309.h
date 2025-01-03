#pragma once
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

class Solution309 {
public:
    // ����dp[0][i]Ϊ�ڵ�i�챣�ֳ��е��ֽ�
    // ����dp[1][i]Ϊ�ڵ�i�챣���������ֽ�
    // ����dp[2][i]Ϊ�ڵ�i�����������Ʊ���ֽ�
    // ����dp[3][i]Ϊ�ڵ�i�촦���侲�ڼ�
    // dp[0][i] �����Ǵ��������,����ǰһ�����侲�ڻ��߱�������
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