 #include <bits/stdc++.h>
 
 #define lin(i, a, b) for (int i = (a); i < (b); i++)
 using namespace std;
 using ll = long long;

 int dp[1005][1005];

 void solve() {
     int n;
     cin>>n;

     vector<vector<int>> gra(n,vector<int>(n,0));
     lin(i,0,n)
        lin(j,0,i+1) cin>>gra[i][j];

    lin(i,0,n) dp[n-1][i]=gra[n-1][i];
    for(int i=n-2;i>=0;i--){
        lin(j,0,i+1) dp[i][j]=gra[i][j]+max(dp[i+1][j],dp[i+1][j+1]);
    }

    cout<<dp[0][0]<<"\n";
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