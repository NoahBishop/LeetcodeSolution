#pragma once
#include <vector>
#include <string>
#include <list>
#include <algorithm>
using namespace std;

class Solution406 {
public:
    static int mycmp(vector<int>& a, vector<int>& b) {
		if (a[0] == b[0]) {
			return a[1] < b[1];
		}
		return a[0] > b[0];
    }

	vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
		sort(people.begin(), people.end(), mycmp);
		list<vector<int>> res;
		for (int i = 0; i < people.size(); i++) {
			auto pos = res.begin();
			std::advance(pos, people[i][1]);
			res.insert(pos, people[i]);
		}
		return vector<vector<int>>(res.begin(), res.end());;
	}
};