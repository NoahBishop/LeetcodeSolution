#pragma once
#include <vector>
using namespace std;
class Solutin27 {
public:
    int removeElement(vector<int>& nums, int val) {
		int length = nums.size();
		int s = 0;
		for (int i = 0; i < length; i++) {
			if (nums[i] != val) {
				nums[s++] = nums[i];
			}
		}
    }
};