// Problem Link: https://codeforces.com/problemset/problem/1742/F

#include <iostream>
#include <bits/stdc++.h>
#define pb push_back
#define int long long
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;

void solve() {
    int q;
    cin>>q;

    int d;
    int k;
    string x;

    vector<int> smap(26);
    vector<int> tmap(26);

    smap[0]++;
    tmap[0]++;

    // int slen = 1;
    // int tlen = 1;

    rep(i, 0, q) {
        cin>>d; cin>>k; cin>>x;

        int xlen = x.size();

        if(d == 1) {
            // slen += (xlen * k);
            rep(j, 0, xlen) {
                smap[x[j] - 'a'] += k;
            }


        } else {
            // tlen += (xlen * k);
            rep(j, 0, xlen) {
                tmap[x[j] - 'a'] += k;
            }
        }

        // rep(j, 0, 26) {
        //     cout<<"d: "<<d<<", j: "<<j<<", s: "<<smap[j]<<" :: "<<"t: "<<tmap[j]<<"\n";
        // }


        int ans = 0;

        int sflag = 0;
        int tflag = 0;

        rep(j, 1, 26) {
            if(smap[j] != 0) {
                sflag = 1;
                break;
            }
        }

         rep(j, 1, 26) {
            if(tmap[j] != 0) {
                tflag = 1;
                break;
            }
        }

        if((tflag == 0) && sflag != 0) {
            // cout<<i<<": a1\n";
            ans = 1;
        }

        if((tmap[0] <= smap[0]) && (sflag == 0) && (tflag == 0)) {
            // cout<<i<<": a2\n";
            ans = 1;
        }

        // cout<<"ans: "<<ans<<"\n";

        if(ans == 0) {
            cout<<"YES\n";
        } else {
            cout<<"NO\n";
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
