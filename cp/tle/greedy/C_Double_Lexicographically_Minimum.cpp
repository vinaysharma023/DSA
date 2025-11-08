// Problem Link: https://codeforces.com/problemset/problem/1675/E

#include <iostream>
#include <bits/stdc++.h>
#define pb push_back
// #define int long long
#include <map>
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

void solve1() {
    string s;
    cin >> s;
    int n = s.size();

    
    map<char, int> freq;
    for (char c : s) freq[c]++;

    string t(n, '.');
    int left = 0, right = n - 1;
    int midPtr = n / 2; // start of second half

    while (left <= right && !freq.empty()) {
        // Pick up to 3 characters (count-based, not distinct)
        vector<char> picks;
        for (auto &p : freq) {
            for (int i = 0; i < p.second && picks.size() < 3; i++)
                picks.push_back(p.first);
            if (picks.size() >= 3) break;
        }

        if (picks.size() == 3) {
            char x = picks[0], y = picks[1], z = picks[2];

            if (x == y) {
                t[left++] = y;
                t[right--] = x;
                freq[x] -= 2; // two of same used
            }
            else if (x != y && y == z) {
                t[left++] = y;
                t[right--] = z;
                freq[y]--; freq[z]--;
                if (n % 2 == 1)
                    t[n / 2] = x;
                else
                    t[midPtr++] = x;
                freq[x]--;
            }
            else if (x != y && y != z) {
                t[left++] = y;
                t[right--] = x;
                freq[x]--; freq[y]--;
            }
        } 
        else if (picks.size() == 2) {
            char x = picks[0], y = picks[1];
            // smaller -> end, larger -> start
            if (x < y) {
                t[left++] = y;
                t[right--] = x;
            } else {
                t[left++] = x;
                t[right--] = y;
            }
            freq[x]--; freq[y]--;
        } 
        else if (picks.size() == 1) {
            char x = picks[0];
            t[left] = x;
            freq[x]--;
            left++;
        }

        // Clean up empty keys
        vector<char> toErase;
        for (auto &p : freq)
            if (p.second <= 0)
                toErase.push_back(p.first);
        for (char c : toErase)
            freq.erase(c);
    }

    cout<< t << endl;

}

void solve2() {
    string s;
    cin >> s;
    int n = s.size();

    sort(s.begin(), s.end()); 

    string t(n, '.');

    int left  = 0;
    int right = n - 1;

    for(int i = 0; i < n; i++) {
        char x = s[i];
        char y = s[i + 1];

        // cout<<"x: "<<x<<", y: "<<y<<"\n";

        if(i == n - 1) {
            t[left] = x;
            left++;
            break;
        }

        if(x == y) {
            t[left] = x;
            t[right] = x;
            left++;
            right--;
            i++;
        } else {
            if(y == s[n - 1]) {
                // form a palindrome-like segment from left to right
                rep(j, left, right + 1) {
                    if(j == n / 2)
                        t[j] = x;
                    else
                        t[j] = y;
                }
                // cout<<"here\n";
                break;
            } else {
                t[right] = x;
                t[left] = y;
                left++;
                right--;
                int k = i + 2;
                while(left <= right && k < n) {
                    t[left] = s[k];
                    left++;
                    k++;
                }
                // cout<<"here again\n";
                break;
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
        solve2();
    }
}
