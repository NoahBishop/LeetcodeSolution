#pragma once
#include <vector>
#include <string>
#include <list>
#include <algorithm>
using namespace std;

class Solution377 {
public:

	// �ȼ�����ȫ����,���Ǽ�¼����װ����,��¼����װ���ж������з�ʽ
	// ������j,��¼dp[i][j]Ϊѡȡ����0-iԪ��,����Ϊj����������ж������з�ʽ
	int combinationSum4(vector<int>& nums, int target) {
		vector<unsigned long long> dp(target + 1, 0);
		dp[0] = 1;

		for (int j = 0; j <= target; j++) {
			for (int i = 0; i < nums.size(); i++) {
				if (j - nums[i] >= 0) {
					dp[j] += dp[j - nums[i]];
				}
			}
		}

		return dp[target];
	}
};