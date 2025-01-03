#pragma once
#include <vector>
#include <string>
#include <map>
using namespace std;
class Solution37 {
public:
    bool checkPos(vector<vector<char>>& board, int row, int col, char val) {
        for (int i = 0; i < 9; i++) {
            if (board[row][i] == val) {
                return false;
            }
        }

        for (int i = 0; i < 9; i++) {
            if (board[i][col] == val) {
                return false;
            }
        }

        int startRow = (row / 3) * 3;
        int startCol = (col / 3) * 3;
        for (int i = startRow; i < startRow + 3; i++) { // 判断9方格里是否重复
            for (int j = startCol; j < startCol + 3; j++) {
                if (board[i][j] == val) {
                    return false;
                }
            }
        }
        return true;
    }

    bool toNext(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    continue;
                }
                for (auto k = '1'; k <= '9'; k++) {
                    if (checkPos(board, i, j, k)) {
                        board[i][j] = k;
                        if (toNext(board)) {
                            return true;
                        }
                        board[i][j] = '.';
                    }
                }
                return false;
            }
        }
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        toNext(board);
    }
};