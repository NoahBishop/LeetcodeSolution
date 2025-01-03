#pragma once
#include <vector>
#include <string>
#include <list>
#include <algorithm>
using namespace std;

class Solution518 {
public:

	// 等价问题全背包,但是记录不是装多少,记录的是装满有多少可能性
	// 容量是j,记录dp[i][j]为选取任意0-i元素,容量为j是填充满的选择个数
	int change(int amount, vector<int>& coins) {
		vector<unsigned long long> dp(amount + 1, 0);
		dp[0] = 1;

		for (int i = 0; i < coins.size(); i++) {
			for (int j = coins[i]; j <= amount; j++) {
				dp[j] = dp[j] + dp[j - coins[i]];
			}
		}

		return dp[amount];
	}
};