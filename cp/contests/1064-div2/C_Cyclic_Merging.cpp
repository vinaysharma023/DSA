// Problem Link: https://codeforces.com/contest/2166/problem/C

#include <iostream>
#include <bits/stdc++.h>
#include <set>
#define pb push_back
#define int long long
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;

void solve() {
    int n;
    cin>>n;
    vector<int> a(n);
    rep(i,0,n) cin>>a[i];
    int ans = 0;
    int x = 0;
    rep(i, 0, n) {
        int mx = max(a[i], a[(i + 1) % n]);
        ans += mx;
        x = max(x, mx);
    }

    cout<<ans - x<<"\n";
}

// 0 1 2 3 4 5

void solve_() {
    int n; cin>>n;
    vector<int> a(n);
    rep(i, 0, n) cin>>a[i];

    // Stores the index left of the index i.
    vector<int> left(n);

    // Stores the index on the right of index i/
    vector<int> right(n);

    // Set stores the cost (of the operation of the merge operation of idx and idx - 1)
    // and the idx which is the right index in the pair of the operation.
    set<pair<int, int>> s;

    rep(i, 0, n) {
        left[i] = (i - 1 + n) % n; 
        right[i] = (i + 1) % n;

        s.insert({max(a[i], a[left[i]]), i});
    }

    int ans = 0;

    for(int i = 1; i < n; i++) {
        pair<int, int> top = *s.begin();
        // This is the min cost of a single merge operation possible right now in the whole ring.
        ans += top.first;

        // right index amongst the two index that is part of the merge operation.
        int r = top.second;

        // left index amongst the two index that is part of the merge operation.
        int l = left[r];

        int widx;

        if(a[l] < a[r]) {
            widx = l;
        } else {
            widx = r;
        }

        if(s.find({max(a[widx], a[right[widx]]), right[widx]}) != s.end()) {
            s.erase({max(a[widx], a[right[widx]]), right[widx]});
        }
        if(s.find({max(a[widx], a[left[widx]]), widx}) != s.end()) {
            s.erase({max(a[widx], a[left[widx]]), widx});
        }

        right[left[widx]] = right[widx];
        left[right[widx]] = left[widx];

        s.insert({max(a[right[widx]], a[left[widx]]), right[widx]});
    }

    cout<<ans<<"\n";
}
 
signed main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cin.exceptions(cin.failbit);
    int T; cin>>T;
    while(T--){
        solve_();
    }
}
