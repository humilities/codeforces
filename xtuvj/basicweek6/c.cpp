#include <bits/stdc++.h>

#define lin(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin>>n;

    vector<int> a(n);
    lin(i,0,n) cin>>a[i];

    vector<int> dp1(n,1);
    lin(i,0,n)
        lin(j,0,i) if(a[j]<a[i]) dp1[i]=max(dp1[i],dp1[j]+1);

    vector<int> dp2(n,1);
    for(int i=n-1;i>=0;i--)
        for(int j=n-1;j>=i;j--) if(a[j]<a[i]) dp2[i]=max(dp2[i],dp2[j]+1);
    
    int ans=0;
    lin(i,0,n) ans=max(ans,dp1[i]+dp2[i]-1);

    cout<<n-ans<<"\n";
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