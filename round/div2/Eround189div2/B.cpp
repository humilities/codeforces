#include <bits/stdc++.h>

#define lin(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;
using ll = long long;

void solve() {
    string s;
    cin>>s;

    int n=s.length();
    int cnt=0;
    lin(i,0,n-1)
        if(s[i]==s[i+1]) cnt++;

    if(cnt>2) cout<<"NO"<<"\n";
    else cout<<"YES"<<"\n";
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