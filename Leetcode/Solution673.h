#pragma once
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

class Solution673 {
public:
    // ����dp[i]Ϊ��iΪ����Ԫ�ص����е�������
    // ����һ���ַ���λ��i - 1 λ��
    // ���nums[i] > nums[i - 1], ��ôdp[i] = dp[i - 1] + 1;
    // ����dp[i] = 1;
    int findLengthOfLCIS(vector<int>& nums) {
        vector<int> dp(2, 1);
        dp[0] = 1;

        int maxl = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1]) {
                dp[i % 2] = dp[(i - 1) % 2] + 1;
            }
            maxl = max(maxl, dp[i % 2]);
        }
        return maxl;
    }
};