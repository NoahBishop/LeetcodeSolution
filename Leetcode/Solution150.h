#pragma once
#include <string>
#include <vector>
#include <stack>
using namespace std;
class Solution150 {
public:
    bool isNumber(string& s) {
        int begin = 0;
        if (s[0] == '-') {
            if (s.size() == 1) {
                return false; // 只有负号不是数字
            }
            begin = 1;
        }
        for (int i = begin; i < s.length(); i++) {
            if (!std::isdigit(s[i])) {
                return false;
            }
        }
        return true;
    }

    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for (int i = 0; i < tokens.size(); i++) {
            if (isNumber(tokens[i])) {
                int n = stoi(tokens[i]);
                st.push(n);
            }
            else {
                int second = st.top();
                st.pop();
                int first = st.top();
                st.pop();
                int res = 0;

                switch (tokens[i][0]) {
                case '+':
                    res = first + second;
                    break;
                case '-':
                    res = first - second;
                    break;
                case '*':
                    res = first * second;
                    break;
                case '/':
                    res = first / second;
                    break;
                default:
                    break;
                }

                st.push(res);
            }
        }

        if (!st.empty()) {
            return st.top();
        }

        return -1;
    }
};