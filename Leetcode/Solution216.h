#pragma once
#include <vector>
using namespace std;
class Solution216 {
public:
	vector<vector<int>> res;
	vector<int> last;

	void toNext(int begin, int n, int k) {
		if (n < 0) {
			return;
		}

		if (k == 0 && n == 0) {
			res.push_back(last);
			return;
		}

		for (int i = begin; i <= 10 - k; i++) {
			last.push_back(i);
			toNext(i + 1, n - i, k - 1);
			last.pop_back();
		}
	}

    vector<vector<int>> combinationSum3(int k, int n) {
		toNext(1, n, k);
    }
};