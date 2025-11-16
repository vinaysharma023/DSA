// Problem Link: https://codeforces.com/problemset/problem/898/D

#include <iostream>
#include <bits/stdc++.h>
#define pb push_back
// #define int long long
#include <deque>
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> alarms(n);

    for (int i = 0; i < n; i++) {
        cin>>alarms[i];
    }

    sort(alarms.begin(), alarms.end());
    deque<int> dq;
    int ans = 0;

    rep(i, 0, n) {
        dq.pb(alarms[i]);

        while(!dq.empty() && (dq.back() - dq.front() >= m)) {
            dq.pop_front();
        }

        while(!dq.empty() && ((int)dq.size() >= k)) {
            dq.pop_back();
            ans++;
        }
    }

    cout<<ans<<"\n";
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
