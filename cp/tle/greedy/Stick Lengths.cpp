// Problem Link: https://cses.fi/problemset/task/1074

#include <iostream>
#include <bits/stdc++.h>
#define pb push_back
#include <map>
#define int long long
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;

void solve() {
    int n; cin>>n; 
    vector<int> a(n);
    rep(i, 0, n){
        int x; cin>>x;
        a[i] = x;
    }

    sort(a.begin(), a.end());

    int finalLength = 0;

    if(n & 1) { // case when n is odd.
        finalLength = a[n/2];
    } else {
        finalLength = (a[n/2] + a[n/2 - 1]) / 2;
    }

    int cost = 0;

    rep(i, 0, n) {
        cost += abs(a[i] - finalLength);
    }

    cout<<cost<<"\n";
}   
 
signed main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cin.exceptions(cin.failbit);
    // int T; cin>>T;
    int T = 1;
    while(T--){
        solve();
    }
}
