#include <bits/stdc++.h>

#define lin(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;
using ll = long long;

const int mod=998244353;

int ret(ll n){
    if(n%4==0) return n;
    else if(n%4==1) return 1;
    else if(n%4==2) return n+1;
    else return 0;
}

void solve() {
    ll n,x;
    cin>>n>>x;

    if(n==x){
        cout<<0<<"\n";
        return;
    }

    map<ll,ll> l;
    map<ll,ll> r;

    lin(i,1,x) l[ret(i)]++;
    lin(i,x+1,n+1) r[ret(i)]++;

    ll ans=0;
    for(auto& [val,cnt]:l)
        ans=ans+cnt*r[val]%mod;

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