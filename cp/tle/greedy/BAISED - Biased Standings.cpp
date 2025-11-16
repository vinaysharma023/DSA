// Problem Link:

#include <iostream>
#include <bits/stdc++.h>
#include <set>
#define pb push_back
#define int long long
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;

// void solve() {
//     int n;
//     cin>>n;

//     vector<int> ranks(n + 1);
//     set<int> s;

//     rep(i, 0, n) {
//         string team;
//         int rank;
//         cin>>team;
//         cin>>rank;

//         ranks[rank]++;
//     }

//     rep(i, 1, n + 1) {
//         if(ranks[i] == 0) {
//             s.insert(i);
//         }
//     }

//     int next;
//     int prev;
//     int ans = 0;
//     rep(i, 1, n + 1) {
//         if(ranks[i] == 0 || ranks[i] == 1) continue;
//         while(ranks[i] > 1) {
//             next = (int)1e9;
//             prev = (int)1e9;
//             int pos = i;
//             bool has_prev;
//             bool has_next;
//             auto it_next = s.upper_bound(pos);
//             if(it_next != s.end()) {
//                 next = *it_next;
//                 has_next = true;
//             }

//             auto it_prev = s.lower_bound(pos);
//             if (it_prev != s.begin()) {
//                 --it_prev;
//                 prev = *it_prev;
//                 has_prev = true;
//             }

//             if (abs(pos - prev) < abs(pos - next)) {
//                 // use prev
//                 ans += abs(pos - prev);
//                 if(has_prev) s.erase(it_prev);
//             } else {
//                 // use next
//                 ans += abs(pos - next);
//                 if(has_next) s.erase(it_next);
//             }
//             ranks[i]--;
//         }
//     }
//     cout<<ans<<"\n";
// }

void solve_() {
    int n;
    cin>>n;

    vector<int> ranks(n + 1);
    set<int> s;

    rep(i, 0, n) {
        string team;
        int rank;
        cin>>team;
        cin>>rank;

        ranks[rank]++;
    }

    rep(i, 1, n + 1) {
        if(ranks[i] == 0) {
            s.insert(i);
        }
    }

    // int next;
    // int prev;
    int ans = 0;
    rep(i, 1, n + 1) {
        if(ranks[i] == 0 || ranks[i] == 1) continue;
        while (ranks[i] > 1) {
            int pos = i;

            bool has_prev = false, has_next = false;
            int prev = 1e18, next = 1e18;

            auto it_next = s.upper_bound(pos);
            if (it_next != s.end()) {
                next = *it_next;
                has_next = true;
            }

            auto it_lower = s.lower_bound(pos);
            auto it_prev = it_lower;
            if (it_lower != s.begin()) {
                --it_prev;
                prev = *it_prev;
                has_prev = true;
            }
            // Choose closest
            if (has_prev && (!has_next || abs(pos - prev) < abs(pos - next))) {
                s.erase(it_prev);
                ans += abs(pos - prev);
            } else if (has_next) {
                s.erase(it_next);
                ans += abs(pos - next);
            } else {
                // Should never happen logically
                break;
            }

            ranks[i]--;
        }
    }
    cout<<ans<<"\n";
}
 
signed main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cin.exceptions(cin.failbit);
    int T; cin>>T;
    while(T--){
        solve_();
    }
}
