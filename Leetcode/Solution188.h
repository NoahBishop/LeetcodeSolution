#pragma once
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

class Solution188 {
public:
    // ����dp[0][i]Ϊ�ڵ�i�첻�����ֽ�
    // ����dp[1][i]Ϊ�ڵ�i���һ�γ��й�Ʊ���ֽ�
    // ����dp[2][i]Ϊ�ڵ�i���һ�μ����е��ֽ�
    // ����dp[3][i]Ϊ�ڵ�i��ڶ��γ��й�Ʊ���ֽ�
    // ����dp[4][i]Ϊ�ڵ�i��ڶ��μ����е��ֽ�
    // ���Ƶ�k��
    // ���Ե�������������
    // dp[0] = 0
    // dp[1] = max(dp[1], dp[0] - price[i]);
    // ת�ƹ�ʽ
    // dp[0][i] = max(dp[0][i - 1], dp[1][i - 1] + prices[i]); ���첻���к�������н�������
    // dp[1][i] = max(dp[1][i - 1], 0 - prices[i]); ����������߱�������һ��

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