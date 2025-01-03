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

        // ����������˫�����ƣ���i % nums.size() �ظ����ÿռ�
        for (int i = 1; i < 2 * nums.size(); i++) {
            // ��ʱ��iλ�ñȶ���Ԫ�ش�, �ǵ�һ���������Ԫ��
            while (!st.empty() && nums[st.top()] < nums[i % nums.size()]) {
                res[st.top()] = nums[i % nums.size()];
                st.pop();
            }
            st.push(i % nums.size());
        }

        return res;
    }
};