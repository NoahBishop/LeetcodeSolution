#pragma once
#include <string>
#include <algorithm>
using namespace std;
class Solution541 {
public:
    char tmp;
    string reverseStr(string s, int k) {
        int len = s.length();
        int t = len / (2 * k);
        int rem = len % (2 * k);

        for (int i = 0; i < t; i++) {
            for (int j = 0; j < k / 2; j++) {
                int pbase = i * 2 * k;
                tmp = s[pbase + j];
                s[pbase + j] = s[pbase + k - 1 - j];
                s[pbase + k - 1 - j] = tmp;
            }
        }

        int base = t * (2 * k);
        if (rem >= k) {
            rem = k;
        }
        for (int j = 0; j < rem / 2; j++) {
            tmp = s[base + j];
            s[base + j] = s[base + rem - 1 - j];
            s[base + rem - 1 - j] = tmp;
        }
        return s;
    }
};