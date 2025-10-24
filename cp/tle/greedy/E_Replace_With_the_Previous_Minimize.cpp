// Problem Link:

#include <iostream>
#include <bits/stdc++.h>
#define pb push_back
#define int long long
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;

void solve() {
    int n; int k;
    cin>>n>>k;

    string s;
    cin>>s;

    int min_reduced_to_so_far = 26;
    int max_reduced_so_far = 0;

    rep(i, 0, n) {
        int cval = s[i] - 'a' + 1;
        if(cval <= min_reduced_to_so_far) {
            continue;
        }
        if(max_reduced_so_far >= cval) {
            s[i] = 'a' + min_reduced_to_so_far;
        }
        if(k >= cval)  {
            s[i] = 'a';
            k = k - cval;
            int reduced_to = 1;
            min_reduced_to_so_far = min(min_reduced_to_so_far, reduced_to);
            max_reduced_so_far = max(max_reduced_so_far, cval);
        } else {
            // We can reduce k from the current char.
            int reduced_to = cval - k;
            s[i] = 'a' + reduced_to;
            k = 0;
            min_reduced_to_so_far = min(min_reduced_to_so_far, reduced_to);
            max_reduced_so_far = max(max_reduced_so_far, k);
        }
    }

    cout<<s<<"\n";

}

void solve_() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    int max_reduced_so_far = 0;     
    int min_reduced_to_so_far = 26;

    int cval = s[0] - 'a' + 1;
    if (k >= cval - 1) {
        k -= (cval - 1);
        max_reduced_so_far = cval;
        min_reduced_to_so_far = 1;
        s[0] = 'a';
    } else {
        int reduced_to = cval - k;
        k = 0;
        max_reduced_so_far = cval;
        min_reduced_to_so_far = reduced_to;
        s[0] = 'a' + reduced_to - 1;
    }

    for (int i = 1; i < n; i++) {
        int cval = s[i] - 'a' + 1;

        if (cval <= min_reduced_to_so_far) {
            continue;
        }

        if (cval <= max_reduced_so_far) {
            s[i] = 'a' + min_reduced_to_so_far - 1;
            continue;
        }

        if (k >= cval - 1) {
            k -= (cval - 1);
            max_reduced_so_far = max(max_reduced_so_far, cval);
            min_reduced_to_so_far = 1;
            s[i] = 'a';
        } else {
            int reduced_to = cval - k;
            k = 0;
            max_reduced_so_far = max(max_reduced_so_far, cval);
            min_reduced_to_so_far = min(min_reduced_to_so_far, reduced_to);
            s[i] = 'a' + reduced_to - 1;
        }
    }

    cout << s << "\n";
}

void solve_f() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    int pivot = 0;
    int max_left = -1;
    int max_reduced_so_far = s[0] - 'a';
    int min_reduced_to_so_far = 26;
    for (int i = 0; i < n; i++) {
        int cval = s[i] - 'a';
        // cout<<"i: "<<i<<", cval: "<<cval<<", max_left: "<<max_left<<"\n";

        if (cval <= k && cval > max_left) {
            // cout<<"updating pivot at: "<<i<<"\n";
            pivot = i;
        }
        max_left = max(max_left, cval);
    }

    int cval = s[pivot] - 'a';
    int ops_needed = cval;    
    int used_ops = min(k, ops_needed);

    for (int i = 0; i <= pivot; i++) {
        int val = s[i] - 'a';
        if (val <= cval) {
            int reduced_val = max(int64_t(0), val - used_ops);
            s[i] = 'a' + reduced_val;
        }
    }

    cout<<"pivot is: "<<pivot<<"\n";
    cout<<"k: "<<k<<"\n";

    min_reduced_to_so_far = max(0LL, s[pivot] - 'a' - k);; 

    if(pivot + 1 < n) {
        int x = s[pivot + 1] - 'a';
        cout<<"x: "<<x<<"\n";
        min_reduced_to_so_far = min(min_reduced_to_so_far, max(0LL, x - k));
    }
    k -= used_ops;


    cout<<"min_reduced_to_so_far: "<<min_reduced_to_so_far<<"\n";
    cout<<"max_reduced_so_far: "<<max_reduced_so_far<<"\n";

    for (int i = pivot + 1; i < n; i++) {
        int cval = s[i] - 'a';

        // Already below current minimum reduction range → leave it
        if (cval <= min_reduced_to_so_far)
            continue;

        // Falls inside already reduced window
        if (cval <= max_reduced_so_far) {
            s[i] = 'a' + min_reduced_to_so_far;
            continue;
        }

        // Can fully reduce to 'a'
        if (k >= cval) {
            k -= cval;
            s[i] = 'a';
            max_reduced_so_far = max(max_reduced_so_far, cval);
            min_reduced_to_so_far = 0;
        } 
        // Can partially reduce
        else if (k > 0) {
            int reduced_to = cval - k;
            s[i] = 'a' + reduced_to;
            max_reduced_so_far = max(max_reduced_so_far, cval);
            min_reduced_to_so_far = min(min_reduced_to_so_far, reduced_to);
            k = 0;
        }
    }

    cout << s << "\n";
}

void slve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;


    int pivot = -1;
    int max_left = -1;

    int max_reduced_so_far = -1;
    int min_reduced_to_so_far = 26;
    int ops = 0;

    rep(i, 0, n) {
        int cval = s[i] - 'a';
        if(cval <= k && cval > max_left) {
            // cout<<"herererer\n";
            pivot = i;
            max_reduced_so_far = max(max_reduced_so_far, cval);
            min_reduced_to_so_far = min(min_reduced_to_so_far, max(0LL, cval - k));
            ops = max(ops, cval);
        }
        max_left = max(max_left, cval);
    }

    cout<<"pivot is: "<<pivot<<"\n";

    rep(i, 0, pivot + 1) {
        s[i] = 'a' + min_reduced_to_so_far;
    }

    k -= ops;

    // cout<<"ops: "<<ops<<", k left: "<<k<<"\n";

    // max_reduced_so_far = -1;
    // min_reduced_to_so_far = 26;

    if (pivot + 1 < n) {
        int cval = s[pivot + 1] - 'a' + 1;
        if (k >= cval - 1) {
            k -= (cval - 1);
            max_reduced_so_far = cval;
            min_reduced_to_so_far = 1;
            s[pivot + 1] = 'a';
        } else {
            int reduced_to = cval - k;
            k = 0;
            max_reduced_so_far = cval;
            min_reduced_to_so_far = reduced_to - 1;
            s[pivot + 1] = 'a' + reduced_to - 1;
        }
    }

    // cout<<"min_reduced_to_so_far: "<<min_reduced_to_so_far<<"\n";
    // cout<<"max_reduced_so_far: "<<max_reduced_so_far<<"\n";

    rep(i, pivot + 2, n) {
        int cval = s[i] - 'a';

        // Skip if the char is already lesser than the lease we can reduce to after the ops till pivot.
        if (cval <= min_reduced_to_so_far)
            continue;

        // Falls inside already reduced window
        if (cval <= max_reduced_so_far) {
            s[i] = 'a' + min_reduced_to_so_far;
            // cout<<"dvavadsv\n";
            continue;
        }

         // Can fully reduce to 'a'
        if (k >= cval) {
            k -= cval;
            s[i] = 'a';
            max_reduced_so_far = max(max_reduced_so_far, cval);
            min_reduced_to_so_far = 0;
        } else if (k > 0) { // Can partially reduce
            int reduced_to = cval - k;
            s[i] = 'a' + reduced_to;
            // cout<<"cval: "<<cval<<"\n";
            max_reduced_so_far = max(max_reduced_so_far, cval);
            min_reduced_to_so_far = min(min_reduced_to_so_far, reduced_to);
            // cout<<"min_reduced_to_so_far: "<<min_reduced_to_so_far<<"\n";
            // cout<<"max_reduced_so_far: "<<max_reduced_so_far<<"\n";
            k = 0;
        }

    }
    cout << s << "\n";

}

 
signed main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cin.exceptions(cin.failbit);
    int T; cin>>T;
    while(T--){
        slve();
    }
}
