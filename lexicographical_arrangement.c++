#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string findLexSmallestString(string s, int add, int shift) {
        unordered_set<string> seen;
        deque<string> dq;
        string smallest = s;
        int len = s.size();

        dq.push_back(s);
        seen.insert(s);

        while (!dq.empty()) {
            string cur = move(dq.front());
            dq.pop_front();
            if (cur < smallest) smallest = cur;

            string withAdd = cur;
            for (int i = 1; i < len; i += 2) {
                int d = withAdd[i] - '0';
                d = (d + add) % 10;
                withAdd[i] = char('0' + d);
            }
            if (seen.emplace(withAdd).second) dq.push_back(withAdd);

            string rotated = cur;
            rotate(rotated.begin(), rotated.end() - shift, rotated.end());
            if (seen.emplace(rotated).second) dq.push_back(rotated);
        }

        return smallest;
    }
};
