#pragma once
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution53 {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int maxl = INT32_MIN;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (maxl < sum) {
                maxl = sum;
            }
            if (sum < 0) {
                sum = 0;
            }
        }
        return maxl;
    }
};