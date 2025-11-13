// Problem Link: https://codeforces.com/problemset/problem/1765/N

#include <iostream>
#include <bits/stdc++.h>
#define pb push_back
#define int long long
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;

void solve() {
    int num;
    cin>>num;
    int k; cin>>k;

    vector<int> nums;

    while(num != 0) {
        nums.pb(num % 10);
        num = num / 10;
    }

    reverse(nums.begin(), nums.end());

    vector<int> aux(nums.size());
    vector<int> pos;

    rep(i, 0, nums.size()) {
        if(nums[i] == 0) pos.pb(i);
    }

    int zeroes = pos.size();
    int ans = 0;

    int prev = -1;

    int brkIdx = -1;

    rep(i, 0, zeroes) {
        int idx = pos[i];
        int len = idx - prev;

        if(len > k) {
            // remove all the element except the smallest one.
            // Sorting here will be of O(len*log(len)).
            vector<int> subset(nums.begin() + prev + 1, nums.begin() + idx);
            sort(subset.begin(), subset.end());

            

            brkIndex = idx + 1;

            break;
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
