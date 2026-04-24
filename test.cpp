#include <bits/stdc++.h>

#define lin(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin>>n;

    vector<int> a(3*n);
    lin(i,0,3*n) cin>>a[i];

    sort(a.begin(),a.end());

    ll ans=0;
    for(int i=0;i<3*n;i+=3)
        ans+=((a[i]-a[i+1])*(a[i]-a[i+1])+(a[i+1]-a[i+2])*(a[i+1]-a[i+2]));

    cout<<ans<<"\n";
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