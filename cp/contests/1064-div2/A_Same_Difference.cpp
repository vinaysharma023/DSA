// Problem Link:

#include <iostream>
#include <bits/stdc++.h>
#define pb push_back
#define int long long
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;

void solve() {
    int n; cin>>n;
    string s;
    cin>>s;

    vector<int> chars(26);

    rep(i, 0, n) {
        chars[s[i] - 'a']++;
    }

    int count = chars[s[n - 1] - 'a'];

    cout<<n - count << "\n";
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
