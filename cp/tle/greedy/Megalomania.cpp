// Problem Link: https://atcoder.jp/contests/abc131/tasks/abc131_d

#include <iostream>
#include <bits/stdc++.h>
#define pb push_back
#define int long long
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;

void solve() {
    int n; cin>>n;
    vector<pair<int, int>> jobs;

    rep(i, 0, n) {
        int a, b;
        cin>>a>>b;
        pair<int, int> p = {a, b};
        jobs.pb(p);
    }

    sort(jobs.begin(), jobs.end(), [](const pair<int, int> &a, const pair<int, int> &b) {
        return a.second < b.second;
    });

    int curr_time = 0;

    rep(i, 0, n) {
        int time_taken = curr_time + jobs[i].first;
        if(time_taken > jobs[i].second) {
            cout<<"No\n";
            return;
        }
        curr_time = time_taken;
    }

    cout<<"Yes\n";
    return;
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
