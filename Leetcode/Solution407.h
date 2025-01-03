#pragma once
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

class Solution407 {
public:
    class side {
    public:
        int height;
        int x;
        int y;

        side(int h, int x, int y) :height(h), x(x), y(y) {}

        //Overload the < operator.
        bool operator <(const side& a) const {
            return a.height < height;
        }
        //Overload the > operator.
        bool operator >(const side& a) const {
            return height > a.height;
        }
    };

    int trapRainWater(vector<vector<int>>& heightMap) {
        if (heightMap.size() <= 2 || heightMap[0].size() <= 2) {
            return 0;
        }
        vector<vector<bool>> usedmap(heightMap.size(), vector<bool>(heightMap[0].size()));

        priority_queue<side> pq;

        for (int i = 0; i < heightMap.size(); i++) {
            for (int j = 0; j < heightMap[0].size(); j++) {
                if (i == 0 || i == heightMap.size() - 1 || j == 0 || j == heightMap[0].size() - 1) {
                    usedmap[i][j] = true;
                    pq.push(side(heightMap[i][j], i, j));
                }
            }
        }
        int sum = 0;
        int dirs[4][2] = { {0 , 1},{0 , -1}, {-1 , 0}, {1 , 0} };
        while (!pq.empty()) {
            side s = pq.top();
            pq.pop();
            // 4个方向
            for (size_t i = 0; i < 4; i++) {
                int newx = s.x + dirs[i][0];
                int newy = s.y + dirs[i][1];
                // 相邻位置有效
                if (newx >= 0 && newx <= heightMap.size() - 1 && newy >= 0 && newy <= heightMap[0].size() - 1) {
                    // 确保之前没用统计过
                    if (!usedmap[newx][newy]) {
                        // 地势低,会流入水
                        if (heightMap[newx][newy] < s.height) {
                            // 计算补全的就算一堵墙
                            sum += s.height - heightMap[newx][newy];
                            pq.push(side(s.height, newx, newy));
                        }
                        else {
                            // 更高的边界
                            pq.push(side(heightMap[newx][newy], newx, newy));
                        }
                        usedmap[newx][newy] = true;
                    }
                }
            }
        }
        return sum;
    }
};