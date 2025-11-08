// Problem Link: https://codeforces.com/problemset/problem/1791/G1

#include <iostream>
#include <bits/stdc++.h>
#define pb push_back
#define int long long
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;

void solve() {
    int n; cin>>n;
    int coins; cin>>coins;
    vector<int> cost(n + 1);

    rep(i, 1, n + 1) {
        cin>>cost[i];
        cost[i] += i;
    }

    sort(cost.begin(), cost.end());

    int cost_till_now = 0;
    int ans = 0;
    rep(i, 1, n + 1) {
        cost_till_now += cost[i];

        if(cost_till_now > coins) {
            break;
        }

        ans++;
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
        solve();
    }
}
