#pragma once
#include <vector>
#include <algorithm>
using namespace std;
class Solution15 {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> fres;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) {
                break;
            }

            // filter same a value
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            int left = i + 1, right = nums.size() - 1;
            while (right > left) {
                int res = nums[i] + nums[left] + nums[right];

                if (res > 0) {
                    right--;
                }
                else if (res < 0) {
                    left++;
                }
                else {
                    fres.push_back({ nums[i] , nums[left] , nums[right] });
                    while (right > left && nums[left] == nums[left + 1]) {
                        left++;
                    }
                    while (right > left && nums[right] == nums[right - 1]) {
                        right--;
                    }

                    left++;
                    right--;
                }
            }
        }
        return fres;
    }
};