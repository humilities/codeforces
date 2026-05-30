#include <bits/stdc++.h>

#define lin(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin>>n;

    string s1,s2;
    cin>>s1>>s2;

    vector<pair<int,int>> v1;
    vector<pair<int,int>> v2;
    lin(i,0,n){
        if(s1[i]!='b') v1.push_back({s1[i],i});
        if(s2[i]!='b') v2.push_back({s2[i],i});
    }

    if(v1.size() != v2.size()) {cout<<"NO"<<"\n"; return;}

    lin(i,0,v1.size()){
        if(v1[i].first!=v2[i].first) {cout<<"NO"<<"\n"; return;}

        if(v1[i].first=='a' && v1[i].second > v2[i].second) {cout<<"NO"<<"\n"; return;}

        if(v1[i].first=='c' && v1[i].second < v2[i].second) {cout<<"NO"<<"\n"; return;}
    }

    cout<<"YES"<<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--)
        solve();

    return 0;
}