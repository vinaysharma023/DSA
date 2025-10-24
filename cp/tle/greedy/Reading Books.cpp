// Problem Link: https://cses.fi/problemset/task/1631/

#include <iostream>
#include <bits/stdc++.h>
#define pb push_back
#define int long long
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;

void solve() {
    int n; cin>>n;
    vector<int> v(n, 0);
    // cout<<n<<"\n";
    int sum = 0;
    int mx = 0;
    rep(i, 0, n){
        int x; cin>>x;
        v[i] = x;
        sum += v[i];
        mx = max(mx, v[i]);
    }

    int my = sum - mx;

    if(mx > my) cout<<2*mx<<"\n";
    else cout<<sum<<"\n";
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
