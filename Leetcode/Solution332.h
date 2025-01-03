#pragma once
#include <vector>
#include <string>
#include <map>
using namespace std;
class Solution332 {
public:
    map<string, map<string, int>> save_tickets;
    vector<string> res = {"JFK"};

    bool toNext(int n, string begin) {
        if (n == 0) {
            return true;
        }

        auto dess = save_tickets[begin];
        for (auto i = dess.begin(); i != dess.end(); i++) {
            // ÓÐÆ±Ã»ÓÃ
            if (i->second > 0) {
                save_tickets[begin][i->first]--;
                res.push_back(i->first);
                auto tres = toNext(n - 1 , i->first);
                if (tres) {
                    return true;
                }
                save_tickets[begin][i->first]++;
                res.pop_back();
            }
        }
        return false;
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        // init
        for (int i = 0; i < tickets.size(); i++) {
            save_tickets[tickets[i][0]][tickets[i][1]]++;
        }

        toNext(tickets.size(), "JFK");
        return res;
    }
};