#pragma once
#include <vector>
#include <string>
#include <list>
#include <algorithm>
using namespace std;

class Solution494 {
public:

	// �ȼ�����ȫ1����,
	// ������target����¼dp[i][j]Ϊѡȡ0-iԪ�أ����������Ϊtarget�ķ�ʽ�ļ���;
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