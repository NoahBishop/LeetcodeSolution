#pragma once
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution55 {
public:
    bool canJump(vector<int>& nums) {
		int pre_left = 0, pre_right = nums[0];
		int cur_left = 0, cur_right = 0;
		for (int i = 1; i < nums.size(); i++) {
			cur_left = i;
			cur_right = i + nums[i];

			if (pre_right < cur_left) {
				return false;
			}

			pre_left = min(cur_left, pre_left);
			pre_right = max(cur_right , pre_right);
		}

		return true;
    }
};