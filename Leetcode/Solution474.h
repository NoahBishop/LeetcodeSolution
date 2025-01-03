#pragma once
#include <vector>
#include <string>
#include <list>
#include <algorithm>
using namespace std;

class Solution474 {
public:

	// �ȼ�����01����,��������ά����2,
	// ������i,j,��¼dp[k][i][j]Ϊѡȡ0-kԪ��,����Ϊij�µõ���Ԫ������
	// ��ֵ���Ϊ1
	int findMaxForm(vector<string>& strs, int m, int n) {
		vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

		for (int k = 0; k < strs.size(); k++) {
			int num_one = 0, num_zero = 0;
			for (int it = 0; it < strs[k].length(); it++) {
				if (strs[k][it] == '0') {
					num_zero++;
				}
				else {
					num_one++;
				}
			}

			for (int i = m; i >= num_zero; i--) {
				for (int j = n; j >= num_one; j--) {
					dp[i][j] = max(dp[i][j], dp[i - num_zero][j - num_one] + 1);
				}
			}
		}

		return dp[m][n];
	}
};