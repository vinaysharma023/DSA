// Problem Link: https://codeforces.com/contest/762/problem/B

#include <iostream>
#include <bits/stdc++.h>
#define pb push_back
// #define int long long
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;

void solve() {
    int a, b, c;
    cin>>a>>b>>c;

    int n; cin>>n;

    vector<int> usb;
    vector<int> ps2;

    for(int i = 0; i < n; i++) {
        int a; string as;
        cin>>a; 
        cin>>as;
        if(as == "USB") usb.pb(a);
        else ps2.pb(a);
    }

    sort(usb.begin(), usb.end());
    sort(ps2.begin(), ps2.end());

    long long cost = 0;
    int comp = 0;

    int usbcounter = 0;
    int ps2counter = 0;

    int usbsize = int(usb.size());
    int ps2size = int(ps2.size());

    for(int i = 0; i < usbsize; i++) {
        if(a == 0) {
            break;
        }
        usbcounter++;

        cost += usb[i];
        a--;
        comp++;
    }

    for(int i = 0; i < ps2size; i++){
        if(b == 0) {
            break;
        }
        ps2counter++;

        cost += ps2[i];
        b--;
        comp++;
    }

    while(c != 0) {
        if(usbcounter == usbsize && ps2counter == ps2size) {
            break;
        } else if ((usbcounter < usbsize) && (ps2counter < ps2size) && (usb[usbcounter] <= ps2[ps2counter])) {
            // cout<<"hey1\n";
            c--;
            cost += usb[usbcounter];
            comp++;
            usbcounter++;
        } else if ((ps2counter < ps2size) && (usbcounter < usbsize) && (usb[usbcounter] > ps2[ps2counter])){
            // cout<<"hey2\n";
            c--;
            cost += ps2[ps2counter];
            comp++;
            ps2counter++;
        } else if ((usbcounter == usbsize) && (ps2counter < ps2size)) {
            // cout<<"hey3\n";
            c--;
            cost += ps2[ps2counter];
            comp++;
            ps2counter++;
        } else if ((ps2counter == ps2size) && usbcounter < usbsize) {
            // cout<<"hey4\n";
            c--;
            cost += usb[usbcounter];
            comp++;
            usbcounter++;
        }
    }

    cout<<comp<<" "<<cost<<"\n";

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
