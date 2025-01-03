#pragma once
#include <string>
#include <algorithm>
using namespace std;
class Solution28 {
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

	int kmpSearch(string s, string pat) {
		if (pat.length() == 0) {
			return -1;
		}

		int len = pat.length();
		auto next = (int *)malloc(len * sizeof(int));

		getNext(next, pat);
		for (int i = 0; i < len; i++) {
			cout << next[i] << endl;
		}
		int j = 0;
		for (int i = 0; i < s.length(); i++) {
			while (j > 0 && pat[j] != s[i]) {
				j = next[j - 1];
			}

			if (pat[j] == s[i]) {
				j++;
			}

			if (j == len) {
				return i - len + 1;
			}
		}
	}
	
	int strStr(string haystack, string needle) {
		return kmpSearch(haystack, needle);
	}
};