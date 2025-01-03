#pragma once
#include <vector>
#include <string>
#include <list>
#include <algorithm>
using namespace std;

int dp[101][101] = { 0 };
class Solution63 {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        // no solution
        if (obstacleGrid[0][0] == 1) {
            return 0;
        }
        // ����dp[i][j]Ϊ����i,j���������ѡ��
        // ���Դ�0,0����,û��ѡ
        // dp[0][0] = 1;
        // �������»���������,ע��߽�λ�ã��е�λ��ֻ�п��ܴ�һ��λ����
        // dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (obstacleGrid[j][i] == 1) {
                    continue;
                }

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