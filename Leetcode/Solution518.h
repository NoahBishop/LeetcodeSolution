#pragma once
#include <vector>
#include <string>
#include <list>
#include <algorithm>
using namespace std;

class Solution518 {
public:

	// �ȼ�����ȫ����,���Ǽ�¼����װ����,��¼����װ���ж��ٿ�����
	// ������j,��¼dp[i][j]Ϊѡȡ����0-iԪ��,����Ϊj���������ѡ�����
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