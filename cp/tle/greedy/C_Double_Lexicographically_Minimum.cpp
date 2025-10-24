// Problem Link:

#include <iostream>
#include <bits/stdc++.h>
#define pb push_back
// #define int long long
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;

void solve_() {
    string s;
    cin >> s;
    int n = s.size();

    vector<int> freq(26, 0);
    for (char c : s) freq[c - 'a']++;

    string t(n, '?');
    int left = 0, right = n - 1;

    for (int i = 0; i < 26; i++) {
        while (freq[i] >= 2) {
            t[left++] = 'a' + i;
            t[right--] = 'a' + i;
            freq[i] -= 2;
        }

        if (freq[i] == 1) {
            // find next available char
            int j = i + 1;
            while (j < 26 && freq[j] == 0) j++;

            if (j < 26) {
                // place larger on left, smaller on right
                t[left++] = max('a' + i, 'a' + j);
                t[right--] = min('a' + i, 'a' + j);
                freq[i]--;
                freq[j]--;
                // stay on same i in case more left of same char
                i--;
            } else {
                // only one char left overall (place in middle)
                if (left == right) {
                    t[left] = 'a' + i;
                    freq[i]--;
                }
            }
        }
    }

    cout << t << endl;
}

void solve() {
    string s; cin>>s;

    vector<int> ch(26, 0);

    int len = s.length();

    for(int i = 0; i < len; i++) {
        ch[s[i] - 'a']++;
    }

    string t = s;

    int left = 0;
    int right = len - 1;
    vector<int> vis(len, 0);

    bool done = false;

    for(int i = 0; i < 26 ; i++) {
        cout<<ch[i]<<",";
        while(ch[i] != 0) {
            if(ch[i] >= 2) {
                if (vis[left] != 1) {
                    t[left] = 'a' + i;
                    vis[left] = 1;
                    left++;
                    ch[i]--;
                }
                if (vis[right] != 1) {
                    t[right]= 'a' + i;
                    vis[right] = 1;
                    right--;
                    ch[i]--;
                }
                // cout<<"start "<<t[left]<<", "<<t[right]<<" end"<<"\n";
                // cout<<"this jkbkjb happened";
            }
            else if (ch[i] == 1) {
                if (!done) {
                    if ((len % 2 == 1) && (right == len/2 + 1) && (vis[len/2] != 1)) {
                        t[len/2] = 'a' + i;
                        vis[len/2] = 1;
                    } else if (vis[right] != 1) {
                        t[right] = 'a' + i;
                        right--;
                        vis[right] = 1;
                    }
                } else {
                    if (vis[right] != 1) t[right] = 'a' + i;
                    // cout<<"this one strange happened";
                    right--;
                    vis[right] = 1;
                    done = true;
                }
                ch[i]--;
            }
        }
    }

    cout<<t<<"\n";
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
