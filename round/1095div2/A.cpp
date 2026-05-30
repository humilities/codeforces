#include <bits/stdc++.h>

#define lin(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;
using ll = long long;

const int mod=676767677;

void solve() {
    int n;
    cin>>n;

    vector<int> a(n);
    int last=-1;

    lin(i,0,n) {cin>>a[i];if(a[i]>=2) last=i;}
    ll ans=0;

    if(last!=-1){
        lin(i,0,n) if(a[i]>=2) ans=(ans+a[i])%mod;

        bool flag=false;
        lin(i,last+1,n){
            if(a[i]==1) {flag=true; break;}
        }

        if(flag) ans=(ans+1)%mod;
    }else ans=1;

    cout<<ans<<"\n";
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