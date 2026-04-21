#include <bits/stdc++.h>

#define lin(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin>>n;

    vector<int> a(n);
    lin(i,0,n) cin>>a[i];

    int cnt=0;
    lin(i,0,n) if(a[i]&1) cnt++;

    //cout<<cnt<<" ";
    
    if(!(cnt&1)) cout<<"Yes"<<"\n";
    else cout<<"No"<<"\n";
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