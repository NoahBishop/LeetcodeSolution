#pragma once
#include <string>
#include <algorithm>
using namespace std;
class Solution151 {
public:
    string reverseWords(string s) {
		int length = s.length();
		int slow = 0;
		for (int i = 0; i < length; i++) {
			if (s[i] != ' ') {
				if (slow != 0) {
					s[slow++] = ' ';
				}
				while (i < length && s[i] != ' ') {
					s[slow++] = s[i++];
				}
			}
		}
		s.resize(slow);
		reverse(s.begin(), s.end());

		for (int i = 0; i < s.length(); i++) {
			int end = i;
			while (end < s.length() && s[end] != ' ') {
				end++;
			}

			for (int j = 0; j < (end - i) / 2; j++) {
				swap(s[i + j], s[end - 1 - j]);
			}

			i = end;
		}
		return s;
    }
};