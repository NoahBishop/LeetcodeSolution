#pragma once
#pragma once
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
class Solution40 {
public:
	vector<vector<int>> res;
	vector<int> last;

	void toNext(int n, int begin, vector<int>& candidates) {
		if (n < 0) {
			return;
		}

		if (n == 0) {
			res.push_back(last);
			return;
		}
		int usenums[50] = { 0 };
		for (int i = begin; i < candidates.size(); i++) {
			if (usenums[candidates[i] - 1]) {
				continue;
			}
			usenums[candidates[i] - 1] = 1;

			last.push_back(candidates[i]);
			toNext(n - candidates[i], i + 1, candidates);
			last.pop_back();
		}
	}

	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		sort(candidates.begin(), candidates.end());
		toNext(target, 0, candidates);
		return res;
	}
};