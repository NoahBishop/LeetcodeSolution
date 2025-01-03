#pragma once
#include <vector>
using namespace std;
class Solution59 {
public:
    vector<vector<int>> generateMatrix(int n) {
        std::vector<std::vector<int>> matrix(n, std::vector<int>(n, 0));
        int loop = (n + 1) / 2;
        int val = 1;
        int begin, end, row, col;
        for (int line = 0; line < loop; line++) {
            // 4 [) line
            begin = line;
            end = (n - 1 - line);
            row = line;
            for (; begin < end; begin++) {
                matrix[row][begin] = val++;
            }

            begin = line;
            end = (n - 1 - line);
            col = (n - 1 - line);
            for (; begin < end; begin++) {
                matrix[begin][col] = val++;
            }

            begin = (n - 1 - line);
            end = line;
            row = (n - 1 - line);
            for (; begin > end; begin--) {
                matrix[row][begin] = val++;
            }

            begin = (n - 1 - line);
            end = line;
            col = line;
            for (; begin > end; begin--) {
                matrix[begin][col] = val++;
            }
        }
        if (n%2 != 0) {
            matrix[n / 2][n / 2] = n * n;
        }
        return matrix;
    }
};