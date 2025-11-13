// Problem Link: https://cses.fi/problemset/task/1073

#include <iostream>
#include <bits/stdc++.h>
#define pb push_back
#define int long long
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;

void solve() {
    int n;
    cin>>n;

    vector<int> tops;
    int x;

    rep(i, 0, n) {
        cin>>x;

        auto it = upper_bound(tops.begin(), tops.end(), x);

        if(it == tops.end()) {
            tops.pb(x);
        } else {
            *it = x;
        }

    }

    cout<<tops.size()<<"\n";

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
