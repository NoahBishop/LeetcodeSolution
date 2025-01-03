#pragma once
#include <vector>
#include <string>
#include <list>
#include <algorithm>
using namespace std;

class Solution279 {
public:

	// 等价问题全背包,记录的是装满情况下,value需要最小,
	// 容量是j,记录dp[i][j]为选取任意0-i元素,容量为j是填充满的value最小
	int numSquares(int n) {
		vector<unsigned long long> dp(n + 1, INT32_MAX);
		dp[0] = 0;

		vector<int> values;

		for (int i = 1; i * i <= n; i++) {
			values.push_back(i * i);
		}

		for (int i = 0; i < values.size(); i++) {
			for (int j = 0; j <= n; j++) {
				if (j - values[i] >= 0) {
					dp[j] = min(dp[j], dp[j - values[i]] + 1);
				}
			}
		}

		if (dp[n] == INT32_MAX || dp[n] == 0) {
			return -1;
		}
		return dp[n];
	}
};