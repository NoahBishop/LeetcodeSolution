#pragma once
#include <vector>
#include <unordered_map>
using namespace std;
class Solution1 {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
		unordered_map<int, int> counts;
		for (int i = 0; i < nums1.size(); i++) {
			for (int j = 0; j < nums2.size(); j++) {
				int res = nums1[i] + nums2[j];
				counts[res]++;
			}
		}
		int ress = 0;
		for (int i = 0; i < nums3.size(); i++) {
			for (int j = 0; j < nums4.size(); j++) {
				int res = -(nums3[i] + nums4[j]);
				auto p = counts.find(res);
				if (p != counts.end()) {
					ress += p->second;
				}
			}
		}
		return ress;
    }
};