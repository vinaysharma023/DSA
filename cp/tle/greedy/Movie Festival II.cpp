// Problem Link: https://cses.fi/problemset/task/1632

#include <iostream>
#include <bits/stdc++.h>
#define pb push_back
#include <set> 
// #define int long long
#include <queue>
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;

struct CompareSecond {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) const {
        if (a.second == b.second)
            return a.first > b.first;
        return a.second > b.second;
    }
};


void solve() {
    int n, k;
    cin>>n>>k;

    vector<pair<int, int>> movies;

    rep(i, 0, n) {
        int a, b;
        cin>>a>>b;
        pair<int, int> p = {a, b};
        movies.pb(p);
    }

    sort(movies.begin(), movies.end(), [](const pair<int,int> &a, const pair<int,int> &b) {
        if (a.second == b.second)
            return a.first < b.first;
        return a.second < b.second;
    });

    priority_queue<pair<int, int>, vector<pair<int, int>>, CompareSecond> minHeap;

    rep(i, 1, k + 1) {
        minHeap.push({i, 0});
    }

    int ans = 0;

    rep(i, 0, n) {
        int cm = minHeap.top().first;
        int occupancy = minHeap.top().second;

        // cout<<"occupancy: "<<occupancy<<", startTime: "<<movies[i].first<<"\n";

        if(occupancy <= movies[i].first) {
            minHeap.pop();
            ans++;
            minHeap.push({cm, movies[i].second});
        }

        // cout<<"i: "<<i<<", ans:"<<ans<<"\n";
    }

    cout<<ans<<"\n";
}

void solve_() {
    int n, k;
    cin >> n >> k;
    vector<pair<int,int>> movies(n);
    for (int i = 0; i < n; i++) cin >> movies[i].first >> movies[i].second;

    sort(movies.begin(), movies.end(), [](auto &a, auto &b){
        if (a.second == b.second) return a.first < b.first;
        return a.second < b.second;
    });

    multiset<int> endTimes; // stores when each member is free next
    for (int i = 0; i < k; i++) endTimes.insert(0);

    int ans = 0;
    for (auto &[start, end] : movies) {
        // find member whose end time <= start
        auto it = endTimes.upper_bound(start);
        if (it == endTimes.begin()) continue; // no member free
        --it; // take the member with largest time <= start
        endTimes.erase(it);
        endTimes.insert(end);
        ans++;
    }

    cout << ans << "\n";
}
 
signed main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cin.exceptions(cin.failbit);
    int T = 1;
    while(T--){
        solve_();
    }
}
