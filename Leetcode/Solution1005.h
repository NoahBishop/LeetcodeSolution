#pragma once
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution1005 {
public:
    static int mycmp(int a, int b) {
        return abs(a) > abs(b);
    }

    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end(), mycmp);

        int idx = 0;
        while (k) {
            // ��СԪ�أ�ֻ�ܷ�ת
            if (idx == nums.size() - 1) {
                nums[idx] = -nums[idx];
                k--;
                continue;
            }

            // С��0��ת
            if (nums[idx] < 0) {
                nums[idx] = -nums[idx];
                idx++;
                k--;
            }
            else if(nums[idx] == 0) {
                k--;
            }
            else {
                idx++;
            }
        }

        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }
        return sum;
    }
};