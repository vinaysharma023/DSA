// Problem Link: https://codeforces.com/problemset/problem/2131/E

#include <iostream>
#include <bits/stdc++.h>
#define pb push_back
#define int long long
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;

void solve() {
    int n; cin>>n;
    vector<int> a(n);
    vector<int> b(n);
    vector<int> aa(n);

    rep(i, 0, n) cin>>a[i];
    rep(i, 0, n) cin>>b[i];
    rep(i, 0, n) aa[i] = a[i];

    for(int i = n - 1; i > 0; i--) {
        if(a[i] != b[i]) {
            cout<<"NO\n";
            return;
        }
        if((a[i - 1] != b[i - 1]) && ((a[i] ^ a[i - 1]) != b[i - 1])) {
            if ((a[i - 1] != b[i - 1]) && ((aa[i] ^ a[i - 1]) != b[i - 1])) {
                cout<<"NO\n";
                return;
            }
        }
        a[i - 1] = b[i - 1];
    }
    cout<<"YES\n";
    return;
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
