#pragma once
#include <vector>
#include <stack>
#include <map>
#include <algorithm>
using namespace std;

class Solution42 {
public:
    int trap(vector<int>& height) {
        // �ܽӵ���ˮ�ĵط�,����ľͰЧӦ,�˱߾����߶�
        // ��������λ����˵,�������ұߵ�һ�������ߵ�λ�������
        // ��Ϊ����������ڲ���������,û�б����ߵ�,���Ժ��������ˮ
        // min(height[s.top], height[i]) * (i - st.top() - 1)
        int sum = 0;

        stack<int> st;
        st.push(0);

        for (int i = 1; i < height.size(); i++) {
            // ����߽�
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
            // ����
            if (height[i] < height[st.top()]) {
                st.push(i);
            } if (height[i] == height[st.top()]) {
                // ����������������
                // ������֤ǰһ��������߽�,��ô�����ʱ�����(i - st.top() - 1);
                // ����������� h ���� 0��Ȼ�󱻵������������
                st.pop();
                st.push(i);
            }
        }

        return sum;
    }
};