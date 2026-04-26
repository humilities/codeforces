#include <bits/stdc++.h>

#define lin(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;
using ll = long long;

bool che(ll mid,ll n,ll t,const vector<int>& a){
    priority_queue<ll,vector<ll>,greater<ll>> co;
    ll mn=0;

    lin(i,0,mid){
        co.push(a[i]);
        mn=max(mn,(ll)a[i]);
    }

    lin(i,mid,n){
        ll cur=co.top();
        co.pop();

        ll end=cur+a[i]+1;
        mn=max(mn,end);

        if(mn>t) return false;
        co.push(end);
    }

    return mn<=t;
}


void solve(int n,ll t) {
    vector<int> a(n);
    lin(i,0,n) cin>>a[i];

    ll l=1,r=n;
    ll ans=n;

    while(l<=r){
        ll mid=l+(r-l)/2;
        if(che(mid,n,t,a)){
            ans=mid;
            r=mid-1;
        }else l=mid+1;
    }

    cout<<ans<<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

   int n;
   ll t;

   while(cin>>n>>t)
        solve(n,t);

    return 0;
}