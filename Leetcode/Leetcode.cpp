#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include "Solution407.h"
using namespace std;

//unsigned long long dp{33} = { 0 };

int main() {

    Solution407 S;
    vector<vector<int>> i = { {1, 4, 3, 1, 3, 2}, {3, 2, 1, 3, 2, 4}, {2, 3, 3, 2, 3, 1} };
    auto n = S.trapRainWater(i);
    /*int m = 0, n = 0;
    memset(dp, 0, sizeof(dp));
    dp{0} = 1;
    cin >> n >> m;
    vector<int> value;
    for (int i = 1; i <= m; i++) {
        value.push_back(i);
    }
    
    for (int j = 0; j <= n; j++) {
        for (int i = 0; i < value.size(); i++) {
            if (j - value{i} >= 0) {
                dp{j} += dp{j - value{i}};
            }
        }
    }

    cout << dp{n} << endl;*/

    return 0;
}