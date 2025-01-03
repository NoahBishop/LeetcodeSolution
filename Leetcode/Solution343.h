#pragma once
#include <vector>
#include <string>
#include <list>
#include <algorithm>
using namespace std;


class Solution343 {
public:
    int integerBreak(int n) {
        // ����dp[i]Ϊ��i�ֽ��ܵõ������ֵ
        // �� j Ϊ�ֽ�ĵ�һ������
        // dp[i] ��ת��Ϊֱ�ӷ�2�� ���� ��ʣ������ֽ�
        // ��Ϊ�˷��ǽ���ʱ���max���ۻ�
        // ��ôdp[i] = max(j * (i - j), j * dp[i - j]);
        // dp[2] = 1 x 1 = 1;
        int dp[59] = { 0 };
        dp[1] = 0;
        dp[2] = 1;
        for (int i = 3; i <= n; i++) {
            for (int j = 1; j < i; j++) {
                // ��Ϊ֮ǰ�м�¼����Ҫ�ٱȽ�һ��
                dp[i] = max(dp[i], max(j * (i - j), j * dp[i - j]));
            }
        }

        return dp[n];
    }
};