#pragma once
#include <vector>
#include <string>
#include <list>
#include <algorithm>
using namespace std;

class Solution746 {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        // ����dp[i]Ϊ����̨��i��Ҫ���ѵ���С����
        // ���Դ�0����1ѡ�����
        // dp[0] = 0; //��0������
        // dp[1] = 0; //��1������
        // ��2����ʼ��֮����Դ�����2����ѡ��
        // �⼶����Ϊ��ǰ1����������ǰ2������
        // dp[i] = min(dp[i - 2] + cost[i - 2], dp[i - 1] + cost[i - 1]);
        int dp[1001] = { 0 };

        for (int i = 2; i <= cost.size(); i++) {
            dp[i] = dp[i] = min(dp[i - 2] + cost[i - 2], dp[i - 1] + cost[i - 1]);
        }

        return dp[cost.size()];
    }
};