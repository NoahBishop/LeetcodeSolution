#pragma once
#include <vector>
#include <string>
#include <list>
#include <algorithm>
using namespace std;

class Solution494 {
public:

	// 等价问题全1背包,
	// 容量是target，记录dp[i][j]为选取0-i元素，特殊操作和为target的方式的计数;
	int findTargetSumWays(vector<int>& nums, int target) {
		vector<vector<int>> dp(nums.size(), vector<int>(20000 + 1, 0));
		dp[0][10000 + nums[0]]++;
		dp[0][10000 - nums[0]]++;

		for (int i = 1; i < nums.size(); i++) {
			for (int j = 0; j < 20001; j++) {
				if (dp[i - 1][j]) {
					dp[i][j - nums[i]] += dp[i - 1][j];
					dp[i][j + nums[i]] += dp[i - 1][j];
				}
			}
		}

		return dp[nums.size() - 1][10000 + target];
	}
};