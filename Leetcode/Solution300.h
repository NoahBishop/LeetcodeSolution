#pragma once
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

class Solution300 {
public:
    // ����dp[i]Ϊ��iΪ����Ԫ�ص���ϵ�������
    // �Թ�ȥ���ֵ������ַ���λ��jλ��(0 <= j < i)
    // ���nums[i] > nums[j], ��ôdp[i] = max(dp[i], dp[j] + 1);
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 1);
        dp[0] = 1;

        int maxl = 1;
        for (int i = 1; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            maxl = max(maxl, dp[i]);
        }
        return maxl;
    }
};