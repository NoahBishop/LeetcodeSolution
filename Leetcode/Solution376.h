#pragma once
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution376 {
public:
    int wiggleMaxLength(vector<int>& nums) {
		if (nums.size() <= 1) return nums.size();
		int cur_dis = 0, pre_dis = 0;
		int maxl = 1;
		for (size_t i = 0; i < nums.size() - 1; i++) {
			int cur_dis = nums[i + 1] - nums[i];

			if ((cur_dis > 0 && pre_dis <= 0) || (cur_dis < 0 && pre_dis >= 0)) {
				maxl++;
				pre_dis = cur_dis;
			}
		}

		return maxl;
    }
};