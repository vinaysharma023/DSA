// Problem Link: https://cses.fi/problemset/task/1164

#include <iostream>
#include <bits/stdc++.h>
#define pb push_back
// #define int long long
#include <queue>
#include <vector>
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;

int findSmallerIndex(vector<pair<int, int>>& v, int x) {
    int left = 0, right = (int)v.size() - 1;
    int ans = -1;  // will store index of element < x

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (v[mid].first < x) {
            ans = mid;          // valid candidate
            left = mid + 1;     // try to find a larger one
        } else {
            right = mid - 1;    // go left
        }
    }

    return ans;  // -1 if all elements >= x
}

void solve() {
    int n; 
    cin>>n; 
    vector<pair<int, int>> arrivals;
    vector<int> departures;

    rep(i, 0, n) {
        int a, b;
        cin>>a>>b;
        pair<int, int> p = {a, i};
        arrivals.pb(p);
        departures.pb(b);
    }

    sort(arrivals.begin(), arrivals.end(), [](const pair<int,int> &a, const pair<int,int> &b) {
        return a.first < b.first;
    });

    // vector<pair<int, int>> rooms;

    vector<int> ans(n);

    // rep(i, 0, n) {
    //     int arrival = arrivals[i].first;
    //     int customeridx = arrivals[i].second;

    //     // Find the room for this customer.
    //     // sort(rooms.begin(), rooms.end(), [](const pair<int,int> &a, const pair<int,int> &b) {
    //     //     return a.first < b.first;
    //     // });

    //     priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    //     // int roomidx = findSmallerIndex(rooms, arrival);

    //     if (roomidx == -1) {
    //         int roomnumber = rooms.size() + 1;
    //         pair<int, int> rp = {departures[customeridx], roomnumber};

    //         rooms.pb(rp);
    //         ans[customeridx] = roomnumber;
    //     } else {
    //         int roomnumber = rooms[roomidx].second;
    //         rooms[roomidx].first = departures[customeridx];
    //         ans[customeridx] = roomnumber;
    //     }
        
    //     // cout<<"customer: "<<customeridx<<" :: "<<roomidx<<" :: "<<ans[customeridx]<<"\n";
    // }

        // min-heap: {departure_time, room_number}
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    int room_count = 0;
    
    rep(i, 0, n) {
        int arrival = arrivals[i].first;
        int customeridx = arrivals[i].second;
        if(!pq.empty() && pq.top().first < arrival){
            auto [dep, room] = pq.top(); pq.pop();
            ans[customeridx] = room;
            pq.push({departures[customeridx], room});
        } else {
            room_count++;
            ans[customeridx] = room_count;
            pq.push({departures[customeridx], room_count});
        }
    }


    // int sz = rooms.size();

    // cout<<sz<<"\n";

    cout<<room_count<<"\n";
    rep(i, 0, n) {
        cout<<ans[i]<<" ";
    }
    cout<<"\n";

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
