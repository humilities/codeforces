#include <bits/stdc++.h>

#define lin(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;
using ll = long long;

void solve(string s) {
    int n=s.length();
    ll ans=0;
    vector<ll> cnt(26,0),su(26,0);

    lin(i,0,n){
        int num=s[i]-'a';

        if(cnt[num]) ans+=cnt[num]*(i+1)-su[num];

        cnt[num]++;
        su[num]+=i;
    }

    cout<<ans<<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //int t;
    //cin >> t;

    //while (t--)
    string s;
    while(cin>>s)
        solve(s);

    return 0;
}