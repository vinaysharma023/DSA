// Problem Link:

#include <iostream>
#include <bits/stdc++.h>
#define pb push_back
#define int long long
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;

void solve() {
    string s;
    cin>>s;

    string t = "hello";

    int idx = 0;
    // int si = 0;

    int nt = t.size();
    int ns = s.size();

    for(int i = 0; i < ns; i++) {
        if(s[i] == t[idx] && idx < nt) idx++;
    }

    if(idx == nt) cout<<"YES\n";
    else cout<<"NO\n";
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
