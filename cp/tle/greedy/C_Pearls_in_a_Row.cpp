// Problem Link: https://codeforces.com/problemset/problem/620/C

#include <iostream>
#include <bits/stdc++.h>
#include <unordered_set>
#define pb push_back
#define int long long
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;

void solve() {
    int n;
    cin>>n;

    vector<int> v(n + 1);
    rep(i, 1, n + 1) cin>>v[i];

    unordered_set<int> seen;
    vector<pair<int, int>> segments;

    int start = 1;
    rep(i, 1, n + 1) {
        if(seen.count(v[i])) {
            segments.pb({start, i});
            start = i + 1;
            seen.clear();
        } else {
            seen.insert(v[i]);
        }
    }

    if(segments.empty()) {
        cout<<"-1\n";
        return;
    }

    segments.back().second = n;

    cout<<segments.size()<<"\n";
    for(auto [l, r]: segments) {
        cout<<l<<" "<<r<<"\n";
    }

}
 
signed main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cin.exceptions(cin.failbit);
    int T = 1;
    while(T--){
        solve();
    }
}
