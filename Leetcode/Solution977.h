#pragma once
#include <vector>
using namespace std;
class Solution977 {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        vector<int> res;
        res.resize(nums.size());
        int idx = right;
        while (left <= right) {
            int right_res = nums[right] * nums[right];
            int left_res = nums[left] * nums[left];
            if (right_res > left_res) {
                res[idx--] = right_res;
                right--;
            }
            else if (right_res < left_res) {
                res[idx--] = left_res;
                left++;
            }
            else {
                res[idx--] = left_res;
                if (left != right) {
                    res[idx--] = left_res;
                }
                left++;
                right--;
            }
        }

        return res;
    }
};

