// Problem Link: https://codeforces.com/problemset/problem/1810/C

#include <iostream>
#include <bits/stdc++.h>
#define pb push_back
#define int long long
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;

void solve() {
    int n, c, d;
    cin>>n>>c>>d;

    vector<int> v(n);
    rep(i, 0, n) {
        int x;
        cin>>x;
        v[i] = x;
    }

    sort(v.begin(), v.end());

    vector<int> vu;

    vu.pb(v[0]);

    rep(i, 1, n) {
        if(v[i] != v[i - 1]) {
            vu.pb(v[i]);
        }
    }   

    int sz = vu.size();

    int ans = d + (n) * c;
    
    int costTillNow = 0;
    int prev = 0;

    // cout<<"sz: "<<sz<<"\n";
    // cout<<"c: "<<c<<"\n";


    rep(i, 0, sz) {
        costTillNow += d * (vu[i] - prev - 1);
        prev = vu[i];
        // cout<<"(sz - i - 1): "<<(sz - i - 1)<<"\n";
        int y = (sz - i - 1) * c + (n - sz)*c;
        // cout<<"i: "<<i<<", costTillNow: "<<costTillNow<<", y: "<<y<<"\n";
        ans = min(ans, costTillNow + y);
        // cout<<"i: "<<i<<", ans: "<<ans<<"\n";
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
