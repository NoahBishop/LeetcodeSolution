#pragma once
#include <vector>
using namespace std;
class Solution39 {
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

		for (int i = begin; i < candidates.size(); i++) {
			last.push_back(candidates[i]);
			toNext(n - candidates[i], i, candidates);
			last.pop_back();
		}
	}

	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		toNext(target, 0 , candidates);
		return res;
	}
};