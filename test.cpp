#include <bits/stdc++.h>

#define lin(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;
using ll = long long;

const int mn=100005;
const int lg=20;

int st[mn][lg];
int g[mn];

void pre(int n,const vector<int>& a){
    g[1]=0;
    lin(i,2,n+1) g[i]=g[i/2]+1;

    lin(i,1,n+1) st[i][0]=a[i-1];

    lin(j,1,lg)
        for(int i=1;i+(1<<j)-1<=n;i++) st[i][j]=st[i][j-1] | st[i+(1<<(j-1))][j-1];
}

int que(int l,int r){
    int mid=g[r-l+1];
    return st[l][mid] | st[r-(1<<mid)+1][mid];
}

void solve() {
    int n,k;
    cin>>n>>k;

    vector<int> a(n);
    lin(i,0,n) cin>>a[i];

    pre(n,a);
    int ans=0;

    for(int i=1;i<=n-k+1;i++) ans=max(ans,que(i,i+k-1));

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