// Problem Link: https://codeforces.com/problemset/problem/1338/A

#include <iostream>
#include <bits/stdc++.h>
#define pb push_back
#define int long long
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;

void solve() {
    int n;
    cin>>n;

    vector<int> v(n);

    rep(i, 0, n) cin>>v[i];

    int maxSecondsReq = -1;
    int flag = 0;

    rep(i, 1, n) {
        int diff = v[i - 1] - v[i];
        if(diff > 0) {
            flag = 1;
            int highestSetBit = (int)(log2(diff));
            maxSecondsReq = max(maxSecondsReq, highestSetBit);
            v[i] = v[i - 1];
        }
    }

    if (flag) cout << maxSecondsReq + 1 << "\n";
    else cout << "0\n";
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
