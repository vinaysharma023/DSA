// Problem Link: https://codeforces.com/contest/2160/problem/C

#include <iostream>
#include <bits/stdc++.h>
#define pb push_back
#define int long long
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;

bool check(string s) {
    if(s.size() & 1) {
        if(s[s.size() / 2] == '1') return false;
    }

    rep(i, 0, (int)s.size()) {
        if(s[i] != s[s.size() - i - 1]) return false; 
    }
    return true;
}

string bbits(int n) {
    string ans;
    while(n) {
        if(n & 1) {
            ans += '1';
        } else {
            ans += '0';
        }
        n = n >> 1;
    }
    return ans;
}

void solve() {
    int n;
    cin>>n;

    string s = bbits(n);

    if(check(s)) {
        cout<<"YES\n";
        return;
    }

    rep(i, 0, 32) {
        s += '0';
        if(check(s)) {
            cout<<"YES\n";
            return;
        }
    }
    cout<<"NO\n";
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
