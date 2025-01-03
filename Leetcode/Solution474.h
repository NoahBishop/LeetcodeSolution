#pragma once
#include <vector>
#include <string>
#include <list>
#include <algorithm>
using namespace std;

class Solution474 {
public:

	// 等价问题01背包,但是容量维度是2,
	// 容量是i,j,记录dp[k][i][j]为选取0-k元素,容量为ij下得到的元素数量
	// 价值恒等为1
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