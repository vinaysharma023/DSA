// Problem Link:

#include <iostream>
#include <bits/stdc++.h>
#define pb push_back
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int n = (int)s.size();

        vector<int> stars;
        for (int i = 0; i < n; ++i) if (s[i] == '*') stars.push_back(i);

        // More than one star -> infinite
        if ((int)stars.size() > 1) {
            cout << -1 << '\n';
            continue;
        }

        // If there exists a '>' to the left of a '<' (i.e. pattern > ... <) -> infinite
        bool seen_gt = false;
        bool invalid = false;
        for (char c : s) {
            if (c == '>') seen_gt = true;
            if (seen_gt && c == '<') { invalid = true; break; }
        }
        if (invalid) {
            cout << -1 << '\n';
            continue;
        }

        // Exactly one star
        if ((int)stars.size() == 1) {
            int idx = stars[0];
            // if any '>' to left -> -1
            bool bad = false;
            for (int i = 0; i < idx; ++i) if (s[i] == '>') { bad = true; break; }
            if (bad) { cout << -1 << '\n'; continue; }
            // if any '<' to right -> -1
            for (int i = idx + 1; i < n; ++i) if (s[i] == '<') { bad = true; break; }
            if (bad) { cout << -1 << '\n'; continue; }
            // All left are '<' and all right are '>'
            cout << max(idx + 1, n - idx) << '\n';
            continue;
        }

        // No stars and no invalid '>' ... '<' pattern:
        // only arrangement possible is <<<<....>>>>...
        int cntL = 0, cntR = 0;
        for (char c : s) {
            if (c == '<') ++cntL;
            else if (c == '>') ++cntR;
        }
        cout << max(cntL, cntR) << '\n';
    }

    return 0;
}
