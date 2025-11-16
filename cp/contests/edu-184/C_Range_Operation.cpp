// Problem Link:

#include <iostream>
#include <bits/stdc++.h>
#define pb push_back
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<ll> a(n + 1), pref(n + 1);

        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            pref[i] = pref[i - 1] + a[i];
        }

        ll ansGain = 0;
        ll best = pref[1] - 1LL * 1 * (1 + 1);

        for (int r = 1; r <= n; r++) {
            ansGain = max(ansGain, 1LL * r * (r + 1) - pref[r]);

            ll gain = 1LL * r * (r + 1) - pref[r] + best;
            ansGain = max(ansGain, gain);

            ll x = pref[r] - 1LL * r * (r + 1);
            best = max(best, x);
        }

        cout << pref[n] + ansGain << "\n";
    }

    return 0;
}
