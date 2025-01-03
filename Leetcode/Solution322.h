#pragma once
#include <vector>
#include <string>
#include <list>
#include <algorithm>
using namespace std;

class Solution322 {
public:

	// 等价问题全背包,记录的是装满情况下,value需要最小,
	// 容量是j,记录dp[i][j]为选取任意0-i元素,容量为j是填充满的value最小
	int coinChange(vector<int>& coins, int amount) {
		vector<unsigned long long> dp(amount + 1, INT32_MAX);
		dp[0] = 0;

		for (int i = 0; i < coins.size(); i++) {
			for (int j = 0; j <= amount; j++) {
				if (j - coins[i] >= 0) {
					dp[j] = min(dp[j], dp[j - coins[i]] + 1);
				}
			}
		}

		if (dp[amount] == INT32_MAX || (amount != 0 && dp[amount] == 0)) {
			return -1;
		}
		return dp[amount];
	}
};