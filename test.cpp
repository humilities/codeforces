// #include <bits/stdc++.h>

// #define lin(i, a, b) for (int i = (a); i < (b); i++)
// using namespace std;
// using ll = long long;

// const int mn=200005;
// vector<int> ve(mn);

// void solve() {
//     string s;
//     int cnt=0;

//     while(cin>>s){
//         if(s=="push"){
//             int x;
//             cin>>x;

//             ve.push_back(x);
//             cnt++;
//         }else{
//             int ans=0;
//             int mid=(cnt+1)/2;
//             cnt--;

//             int idx=0;
//             int i=0;
//             while(idx<=mid){
//                 if(ve[i]==0) {i++; continue;}
//                 else{
//                     ans=ve[i];

//                     ve[i]=0;
//                     idx++;
//                     i++;
//                 }
//             }

//             cout<<ans<<"\n";
//         }
//     }
// }

// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

//     //int t;
//     //cin >> t;

//     //while (t--)
//         solve();

//     return 0;
// }

#include <bits/stdc++.h>

#define lin(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;
using ll = long long;

priority_queue<int> l;
priority_queue<int,vector<int>,greater<int>> r;

void ba(int cnt){
    int mid=(cnt+1)/2;

    while(l.size() > mid){
        r.push(l.top());
        l.pop();
    }

    while(l.size() < mid){
        l.push(r.top());
        r.pop();
    }
}

void solve() {
    string s;
    int cnt=0;

    while(cin>>s){
        if(s=="push"){
            int x;
            cin>>x;
            cnt++;

            if(l.empty() || x<=l.top()) l.push(x);
            else r.push(x);

            ba(cnt);
        }else{
            cout<<l.top()<<"\n";

            l.pop();
            cnt--;
            ba(cnt);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //int t;
    //cin >> t;

    //while (t--)
        solve();

    return 0;
}