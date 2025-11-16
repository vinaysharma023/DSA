// Problem Link:

#include <iostream>
#include <bits/stdc++.h>
#define pb push_back
#define int long long
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;

void solve() {
    int n;
    cin>>n;
    int a; cin>>a;

    vector<int> v(n);
    rep(i, 0, n) cin>>v[i];

    int smaller = -1, greater = -1;
    rep(i, 0, n) {
        if (v[i] < a) {
            smaller = i;
        }
        if (v[i] > a) {
            greater = i;
            break;
        }
    }

    int left = smaller + 1;
    int right = n - greater;

    // cout<<smaller<<", "<<greater<<"\n";

    if(smaller == -1 && greater == -1) {
        cout<<v[n - 1] + 1<<"\n";
        return;
    }

    if(left >=  right) {
        cout<<v[smaller]<<"\n";
    } else {
        cout<<v[greater]<<"\n";
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
