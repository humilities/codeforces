#include <bits/stdc++.h>

#define lin(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin>>n;

    vector<int> a(n);
    lin(i,0,n) cin>>a[i];

    if(n==1){
        cout<<0<<"\n";
        return;
    }

    int cnt=0;
    lin(i,1,n)
        if(abs(a[i]-a[i-1])==gcd(a[i],a[i-1])) cnt++;

    cout<<cnt<<"\n";
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