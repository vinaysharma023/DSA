// Problem Link:

#include <iostream>
#include <bits/stdc++.h>
#define pb push_back
#define int long long
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;

void solve() {
    int a, b, n;
    cin>>a>>b>>n;

    if (b >= a) {
        cout<<"1\n";
        return;
    }

    if(b < a) {
        if(b <= float(a/n)) {
            cout<<"1\n";
        } else {
            cout<<"2\n";
        }
    }
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
