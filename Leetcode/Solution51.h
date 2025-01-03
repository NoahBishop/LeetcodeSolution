#pragma once
#include <vector>
#include <string>
#include <map>
using namespace std;
class Solution51 {
public:
    vector<vector<pair<int, int>>> final_res;
    vector<pair<int, int>> res;

    bool checkPos(int x1, int y1, int x2, int y2) {
        if (x1 == x2 || y1 == y2 || abs(x1 - x2) == abs(y1 - y2)) {
            return false;
        }
        return true;
    }

    void toNext(int k, int n) {
        if (k == 0) {
            final_res.push_back(res);
        }

        int row = n - k;
        for (int i = 0; i < n; i++) {
            bool can = true;
            for (int j = 0; j < res.size(); j++) {
                // 检查新添加是否冲突
                if (!checkPos(res[j].first, res[j].second, row, i)) {
                    can = false;
                    break;
                }
            }
            
            if (can) {
                // 有放置位置就继续
                res.push_back(make_pair(row, i));
                toNext(k - 1, n);
                res.pop_back();
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        toNext(n, n);

        for (int i = 0; i < final_res.size(); i++) {
            std::vector<std::string> chessboard(n, std::string(n, '.'));
            for (int j = 0; j < final_res[i].size(); j++) {
                chessboard[final_res[i][j].first][final_res[i][j].second] = 'Q';
            }
            result.push_back(chessboard);
        }

        return result;
    }
};