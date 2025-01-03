#pragma once
#include <vector>
#include <string>
#include <list>
#include <algorithm>
using namespace std;

class Solution279 {
public:

	// �ȼ�����ȫ����,��¼����װ�������,value��Ҫ��С,
	// ������j,��¼dp[i][j]Ϊѡȡ����0-iԪ��,����Ϊj���������value��С
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