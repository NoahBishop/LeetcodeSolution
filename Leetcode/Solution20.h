#pragma once
#include <stack>
#include <string>
using namespace std;
class Solution20 {
public:
    bool checkpair(char a, char b) {
        if (a == '[' && b == ']') {
            return true;
        }else if (a == '{' && b == '}') {
            return true;
        }else if (a == '(' && b == ')') {
            return true;
        }
        else {
            return false;
        }
    }

    bool isValid(string s) {
        stack<char> st;
        for (int i = 0; i < s.length(); i++) {
            if (!st.empty()) {
                if (checkpair(st.top(), s[i])) {
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
        if (st.empty()) {
            return true;
        }
        return false;
    }
};