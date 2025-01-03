#pragma once
#include <vector>
using namespace std;
class Solutin704 {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1, max = nums.size() - 1;
        while (left >=0 && left <= max &&
            right >= 0 && right <= max &&
            left <= right) {
            int mid = (left + right) / 2;

            if (nums[mid] == target) {
                return mid;
            }
            else if (nums[mid] > target) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        return -1;
    }
};

