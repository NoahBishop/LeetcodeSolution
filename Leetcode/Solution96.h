#pragma once
#include <vector>
#include <string>
#include <list>
#include <algorithm>
using namespace std;


class Solution96 {
public:
    int numTrees(int n) {
        // ����dp[i]Ϊ�Գ���Ϊi���������У��ܹ�����2�������з�ʽ
        // dp[0] = 1; // 0 ���ǿսڵ�һ��
        // dp[1] = 1; // 1 ���� 1��
        // ��i=2��ʼ�� ���ƴ���ѡÿ���ڵ���Ϊ���ڵ�
        // ��ڵ����������j, �ұ���i - 1 - j, ѭ��0 <= j <= i - 1;
        // dp[i] += dp[j] * dp[i - 1 - j];
        int dp[20] = { 0 };
        dp[0] = 1;
        dp[1] = 1;

        for (int i = 2; i <= n; i++) {
            for (int j = 0; j <= i - 1; j++) {
                dp[i] += dp[j] * dp[i - 1 - j];
            }
        }

        return dp[n];
    }
};