#include <bits/stdc++.h>

#define lin(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;
using ll = long long;

int num[100005];

void solve() {
    int temp;
    int idx=0;

    while(cin>>temp) num[idx++]=temp;

    vector<int> b1;
    lin(i,0,idx){
        if(b1.empty() || num[i]<=b1.back()) b1.push_back(num[i]);
        else{
            auto it=upper_bound(b1.begin(),b1.end(),num[i],greater<int>());
            *it=num[i];
        }
    }

    vector<int> b2;
    lin(i,0,idx){
        if(b2.empty() || num[i]>b2.back()) b2.push_back(num[i]);
        else{
            auto it=lower_bound(b2.begin(),b2.end(),num[i]);
            *it=num[i];
        }
    }

    cout<<b1.size()<<"\n"<<b2.size();
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