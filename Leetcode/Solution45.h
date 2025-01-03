#pragma once
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution45 {
public:
    int jump(vector<int>& nums) {
		if (nums.size() == 1) {
			return 0;
		}

		int maxdis = 0;
		int curdis = 0;
		int c = 0;
		for (int i = 0; i < nums.size() - 1; i++) {
			maxdis = max(maxdis, i + nums[i]);

			if (i == curdis) {
				c++;
				curdis = maxdis;
				if (maxdis >= nums.size() - 1) {
					break;
				}
			}
		}
		return c;
    }
};