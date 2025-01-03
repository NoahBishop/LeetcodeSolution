#pragma once
#include <vector>
#include <algorithm>
using namespace std;
class Solution18 {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> fres;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++) {
            // filter same a value
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            for (int j = i + 1; j < nums.size(); j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }

                long long two_res = nums[i] + nums[j];

                int left = j + 1, right = nums.size() - 1;
                while (right > left) {
                    long long res = two_res + nums[left] + nums[right];

                    if (res > target) {
                        right--;
                    }
                    else if (res < target) {
                        left++;
                    }
                    else {
                        fres.push_back({ nums[i], nums[j] , nums[left] , nums[right]});
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
        }
        return fres;
    }
};