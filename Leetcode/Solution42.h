#pragma once
#include <vector>
#include <stack>
#include <map>
#include <algorithm>
using namespace std;

class Solution42 {
public:
    int trap(vector<int>& height) {
        // 能接到雨水的地方,根据木桶效应,端边决定高度
        // 对于任意位置来说,找他的右边第一个比他高的位置且这个
        // 因为在这个区间内不包括两端,没有比他高的,所以横向计算雨水
        // min(height[s.top], height[i]) * (i - st.top() - 1)
        int sum = 0;

        stack<int> st;
        st.push(0);

        for (int i = 1; i < height.size(); i++) {
            // 有左边界
            while (!st.empty() && height[st.top()] < height[i]) {
                int base = height[st.top()];
                st.pop();
                if (!st.empty()) {
                    int h = min(height[st.top()], height[i]);
                    sum += (h - base) * (i - st.top() - 1);
                }
                else {
                    st.push(i);
                }
            }
            // 更新
            if (height[i] < height[st.top()]) {
                st.push(i);
            } if (height[i] == height[st.top()]) {
                // 弹出不弹出都可以
                // 弹出保证前一个就是左边界,那么计算的时候就是(i - st.top() - 1);
                // 不弹出计算的 h 就是 0，然后被弹出后继续计算
                st.pop();
                st.push(i);
            }
        }

        return sum;
    }
};