#pragma once
#include <vector>
#include <unordered_map>
using namespace std;
class Solution1 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> number_idxs;
        vector<int> res;

        for (int i = 0; i < nums.size(); i++) {
            int rem = target - nums[i];
            if (number_idxs.count(rem)) {
                res.push_back(i);
                res.push_back(number_idxs[rem]);
                break;
            }
            else {
                number_idxs[nums[i]] = i;
            }
        }
        return res;
    }
};