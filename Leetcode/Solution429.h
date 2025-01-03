#pragma once

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

#include <vector>
#include <queue>
using namespace std;
class Solution637 {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        queue<Node*> q;
        if (root != nullptr) {
            q.push(root);
        }

        while (!q.empty()) {
            vector<int> level;
            int len = q.size();

            for (int i = 0; i < len; i++) {
                level.push_back(q.front()->val);
                for (int i = 0; i < q.front()->children.size(); i++) {
                    q.push(q.front()->children[i]);
                }

                q.pop();
            }
            res.push_back(level);
        }
        return res;
    }
};