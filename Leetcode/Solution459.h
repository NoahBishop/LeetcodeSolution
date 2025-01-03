#pragma once
#include <string>
#include <algorithm>
using namespace std;
class Solution459 {
public:
	void getNext(int* next, string s) {
		int j = 0;
		next[0] = j;
		for (int i = 1; i < s.length(); i++) {
			while (j > 0 && s[i] != s[j]) {
				j = next[j - 1];
			}

			if (s[i] == s[j]) {
				j++;
			}
			next[i] = j;
		}
	}

	bool repeatedSubstringPattern(string s) {
		int len = s.length();
		auto next = (int*)malloc(len * sizeof(int));

		getNext(next, s);

		if (next[len - 1] != 0 && len % (len -(next[len - 1])) == 0) {
			return true;
		}

		return false;
	}
};