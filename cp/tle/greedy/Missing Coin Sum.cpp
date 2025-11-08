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

    // In a brute force approach we would have to ensure picking/ not picking an ele at each turn and keep track of the 
    // possible sums formed.
    // Keeping a range allows us to do this greedily. We will keep a range of min sum and max sum possible.
    // When we pick an element then each possible sum can be turned into sum + i.
    // So, all the sums in the range of [minSum, maxSum] can be turned into [newMinSum, newMaxSum] = [minSum + i, maxSum +i].
    // Crux in this question is that if the [newMinSum, newMaxSum] overlaps with [minSum, maxSum]
    // OR, newMinCoinSum <= maxSum + 1. then the possible range turns into [minSum, newMaxSum],
    // since, this is the new possible range.

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
