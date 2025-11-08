// Problem Link: https://cses.fi/problemset/task/2183/

#include <iostream>
#include <bits/stdc++.h>
#define pb push_back
#define int long long
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;

void solve() {
    int n;
    cin>>n;
    vector<int> v(n);
    rep(i, 0, n) {
        cin>>v[i];
    }

    sort(v.begin(), v.end());

    int minCoinSum = 0;
    int maxCoinSum = 0;

    rep(i, 0, n) {
        int newMinCoinSum = minCoinSum + v[i];
        int newMaxCoinSum = maxCoinSum + v[i];
        if(newMinCoinSum - maxCoinSum > 1) {
            break;
        }
        maxCoinSum = max(maxCoinSum, newMaxCoinSum);
    }
    cout<<maxCoinSum + 1<<"\n";

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
