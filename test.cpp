#include <bits/stdc++.h>

#define lin(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;
using ll = long long;

ll f(int k,int hi,const vector<int>& c){
    if(k==0) return 0;
    if(c[k]==hi) return f(k-1,hi,c);
    
    return f(k-1,6-hi-c[k],c)+(1LL<<(k-1));
}

void solve() {
    int n;
    cin>>n;

    vector<int> a(n+1),b(n+1);
    lin(i,1,n+1) cin>>a[i];
    lin(i,1,n+1) cin>>b[i];

    int k=n;
    while(k && a[k]==b[k]) k--;

    if(k==0){
        cout<<0<<"\n";
        return;
    }

    int hi=6-a[k]-b[k];
    cout<<f(k-1,hi,a)+1+f(k-1,hi,b)<<"\n";
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