#include <bits/stdc++.h>

#define lin(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin>>n;

    string s1,s2;
    cin>>s1>>s2;

    vector<int> dp(n+1,1e9);
    dp[0]=0;

    lin(i,1,n+1){
        int c1=(s1[i-1]!='R')+(s2[i-1]!='R');
        int c2=(s1[i-1]!='B')+(s2[i-1]!='B');
        dp[i]=min(dp[i],dp[i-1]+min(c1,c2));

        if(i>=2){
            int cur=0;
            int r1=min((s1[i-2]!='R')+(s1[i-1]!='R'),(s1[i-2]!='B')+(s1[i-1]!='B'));
            int r2=min((s2[i-2]!='R')+(s2[i-1]!='R'),(s2[i-2]!='B')+(s2[i-1]!='B'));

            cur=dp[i-2]+r1+r2;
            dp[i]=min(dp[i],cur);
        }
    }

    cout<<dp[n]<<"\n";
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