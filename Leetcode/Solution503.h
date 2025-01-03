#pragma once
#include <vector>
#include <stack>
#include <map>
#include <algorithm>
using namespace std;

class Solution503 {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> res(nums.size(), -1);
        stack<int> st;
        st.push(0);

        // 环形数组上双倍复制，用i % nums.size() 重复利用空间
        for (int i = 1; i < 2 * nums.size(); i++) {
            // 这时候i位置比顶部元素大, 是第一个比他大的元素
            while (!st.empty() && nums[st.top()] < nums[i % nums.size()]) {
                res[st.top()] = nums[i % nums.size()];
                st.pop();
            }
            st.push(i % nums.size());
        }

        return res;
    }
};