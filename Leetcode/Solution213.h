#pragma once
#include <vector>
#include <string>
#include <list>
#include <algorithm>
using namespace std;

class Solution213 {
public:
    // ֻ�ܿ������͵��,����λ���������Կ���ȷ����β���ֻ����һ��
    // ����һ������ͷ��һ������β��ȡmax
    // dp[i] Ϊ����͵��ǰi�ҵõ��������
    // ͵���߲�͵��֮ǰ��״̬ת����
    // dp[i] = max(dp[i - 2] + nums[i], dp[i - 1])
    int rob_imp(vector<int>& nums, int begin, int end) {
        int dp_0 = nums[begin], dp_1 = max(nums[begin], nums[begin + 1]), dp_2;
        int first = 0;

        for (int i = begin + 2; i <= end; i++) {
            dp_2 = max(dp_0 + nums[i], dp_1);
            dp_0 = dp_1;
            dp_1 = dp_2;
        }

        return dp_1;
    }

    int rob(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }
        else if (nums.size() == 2) {
            return max(nums[0], nums[1]);
        }
        else {
            return max(rob_imp(nums, 0, nums.size() - 2), rob_imp(nums, 1, nums.size() - 1));
        }
    }
};