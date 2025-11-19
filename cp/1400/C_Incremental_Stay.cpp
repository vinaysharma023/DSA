// Problem Link: https://codeforces.com/contest/2151/problem/C

#include <iostream>
#include <bits/stdc++.h>
#define pb push_back
#define int long long
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;

void solve() {
    int n; cin>>n;
    vector<int> a(2*n + 1);
    rep(i, 1, 2*n + 1) cin>>a[i];

    vector<int> prefixSum(2* n + 1);
    prefixSum[1] = a[1];

    rep(i, 2, 2*n + 1) {
        // cout<<i<<", hehe\n";
        // cout<<prefixSum[i - 1]<<", "<<a[i]<<"\n";
        prefixSum[i] = prefixSum[i - 1] + a[i]; 
    }

    // rep(i, 1, 2*n + 1) {
    //     cout<<prefixSum[i]<<" ";
    // }
    // cout<<"\n";

    vector<int> fdiff(n + 1);
    vector<int> sdiff(n + 1);

    for(int i = 1; i <= 2 * n - 1; i += 2) {
        int idx = (i + 1) / 2;
        int y = a[i] - a[i + 1];
        // cout<<y<<" ";
        fdiff[idx] = fdiff[idx - 1] + y;
    }
    // cout<<"\n";
    for(int i = 2; i <= 2*n -2; i += 2) {
        int idx = i / 2;
        int y = a[i] - a[i + 1];
        // cout<<y<<" ";
        sdiff[idx] = sdiff[idx - 1] + y;
    }
    // cout<<"hererererere\n";

    // for(int i = 1; i <= n; i++) {
    //     cout<<fdiff[i]<<" "; 
    // }
    // cout<<"\n";

    // for(int i = 1; i <= n; i++) {
    //     cout<<sdiff[i]<<" "; 
    // }
    // cout<<"\n";
    
    rep(i, 1, n + 1) {

        int ans = 0;
        int k = i;
        // Add the last k items in ans.
        ans += prefixSum[2*n] - prefixSum[2*n - k];

        // cout<<ans<<"\n";

        // Subtract the first k items from the ans.
        ans -= prefixSum[k];

        // cout<<ans<<"\n";

        // Now take the middle part in consideration for forming the answer.

        if(k % 2 == 0) {
            // use fdiff.

            // No of index to skip from start
            int start = k / 2;
            int end = n - (k / 2);

            // cout<<k<<": "<<start<<", "<<end<<"\n";

            ans += fdiff[end] - fdiff[start];
        } else {

            int start = k / 2;
            int end = (n - 1) - k / 2;

            // cout<<n<<"\n";

            // cout<<k<<": "<<start<<", "<<end<<"\n";

            ans += sdiff[end] - sdiff[start];
        }
        cout<<ans<<" ";
    }
    cout<<"\n";

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
