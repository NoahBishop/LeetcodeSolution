#pragma once
#include <vector>
using namespace std;
class Solution209 {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int length = nums.size();

        int sum = 0;
        int min_len = INT32_MAX;
        int sublen = 0;
        int begin = 0;
        for (int end = 0; end < length; end++) {
            sum += nums[end];
            while (sum >= target) {
                sublen = end - begin + 1;
                if (sublen < min_len) {
                    min_len = sublen;
                }
                sum -= nums[begin];
                begin++;
            }
        }

        if (min_len == INT32_MAX) {
            return 0;
        }
        else {
            return min_len;
        }
    }
};