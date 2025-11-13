// Problem Link: https://codeforces.com/problemset/problem/545/C

#include <iostream>
#include <bits/stdc++.h>
#define pb push_back
#define int long long
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;

void solve() {
    int n;
    cin>>n;

    vector<int> coord(n);
    vector<int> height(n);

    rep(i, 0, n) {
        cin>>coord[i];
        cin>>height[i];
    }

    int ans = 1;

    if(n > 1) ans = 2;

    int prev = coord[0];

    rep(i, 1, n - 1) {
       int left = coord[i] - height[i];
       int right = coord[i] + height[i];

       prev = max(prev, coord[i - 1]);

       if(left > prev) {
            // The tree can be fallen on the left.
            ans++;
       } else if(right < coord[i + 1]) {
            // The tree can be fallen on th right.
            ans++;
            prev = right;
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
