#include <bits/stdc++.h>

#define lin(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;
using ll = long long;

void solve() {
    int n,k;
    cin>>n>>k;

    ll tem=n;
    int cnt2=0,cnt5=0;
    while(tem && tem%2==0) {cnt2++; tem/=2;}
    while(tem && tem%5==0) {cnt5++; tem/=5;}

    ll m=1;
    while(cnt2<cnt5 && m*2<=k){
        m*=2;
        cnt2++;
    }

    while(cnt2>cnt5 && m*5<=k){
        m*=5;
        cnt5++;
    }

    while(m*10<=k) m*=10;

    if(m) m=(k/m)*m;
    cout<<n*m<<"\n";  
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