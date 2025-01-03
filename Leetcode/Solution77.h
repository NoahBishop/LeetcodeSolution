#pragma once
#include <vector>
using namespace std;
class Solution77 {
public:
	vector<vector<int>> res;
	vector<int> last;

	void toNext(int begin, int n, int k) {
		if (k == 0) {
			res.push_back(last);
			return;
		}

		for (int i = begin; i <= n + 1 - k; i++) {
			last.push_back(i);
			toNext(i + 1, n, k - 1);
			last.pop_back();
		}
	}

    vector<vector<int>> combine(int n, int k) {
		res.clear();
		toNext(1, n, k);
		return res;
    }
};