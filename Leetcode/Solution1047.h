#pragma once
#include <stack>
#include <string>
#include <algorithm>
using namespace std;
class Solution1047 {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        for (int i = 0; i < s.length(); i++) {
            if (!st.empty()) {
                if (st.top() == s[i]) {
                    st.pop();
                }
                else {
                    st.push(s[i]);
                }
            }
            else {
                st.push(s[i]);
            }
        }
        
        string str;
        while (!st.empty()) {
            str += str.front();
            st.pop();
        }
        reverse(str.begin(), str.end());
        return str;
    }
};