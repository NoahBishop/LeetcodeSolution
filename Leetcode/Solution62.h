#pragma once
#include <vector>
#include <string>
#include <list>
#include <algorithm>
using namespace std;

int dp[101][101] = { 0 };
class Solution62 {
public:
    int uniquePaths(int m, int n) {
        // ����dp[i][j]Ϊ����i,j���������ѡ��
        // ���Դ�0,0����,û��ѡ
        // dp[0][0] = 1;
        // �������»���������,ע��߽�λ�ã��е�λ��ֻ�п��ܴ�һ��λ����
        // dp[i][j] = dp[i - 1][j] + dp[i][j - 1];

        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (j != 0) {
                    dp[i][j] += dp[i][j - 1];
                }

                if (i != 0) {
                    dp[i][j] += dp[i - 1][j];
                }
            }
        }

        return dp[n - 1][m - 1];
    }
};