//1401D

// #include<vector>
// #include<iostream>
// #include<algorithm>
// #define pb push_back

// using namespace std;
// typedef long long ll;

// const int N = 2e5 + 10, P = 1e9 + 7;
// int n, m;
// vector<ll> a[N], w;

// ll dfs(int x, int fa) {
// 	if (a[x].size() == 1 && a[x][0] == fa) return 1;
	
// 	ll sum = 0;
// 	for (int i = 0;i < a[x].size();i++) {
// 		if (a[x][i] == fa) continue;
// 		ll cnt = dfs(a[x][i], x);
// 		w.pb(cnt * (n - cnt));
// 		sum += cnt;
// 	}

// 	return sum + 1;
// }

// void solve() {
// 	cin >> n;
// 	for (int i = 1;i <= n;i++) {
// 		a[i].clear(), w.clear();
// 	}
// 	for (int i = 1;i < n;i++) {
// 		int u, v;
// 		cin >> u >> v;

// 		a[u].pb(v), a[v].pb(u);
// 	}

// 	cin >> m;
// 	vector<ll> p(m);
// 	for (int i = 0;i < m;i++) {
// 		cin >> p[i];
// 	}

// 	if (m < n - 1) {
// 		for (int i = m + 1;i < n;i++) {
// 			p.pb(1);
// 		}
// 	}
// 	sort(p.begin(), p.end());

// 	if (m > n - 1) {
// 		for (int i = n - 1;i < m;i++) {
// 			p[n - 2] = (p[n - 2] * p[i]) % P;
// 		}
// 	}

// 	dfs(1, 0);
// 	sort(w.begin(), w.end());

// 	ll ans = 0;
// 	for (int i = 0;i < n-1;i++) {
// 		ans = (ans + p[i] * w[i]) % P;
// 	}

// 	cout << ans << endl;
// }

// int main() {
// 	int t;
// 	cin >> t;

// 	while (t--) {
// 		solve();
// 	}

// 	return 0;
// }



#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int n,m;
const int N=2e5+10,M=1e9+7;
vector<ll> point[N],w;

ll dfs(int x,int fa){
	if(point[x].size()==1&&point[x][0]==fa) return 1;

	ll cnt=0;
	for(int i=0;i<point[x].size();i++){
		if(point[x][i]==fa) continue;
		ll temp=dfs(point[x][i],x);
		w.push_back(temp*(n-temp));

		cnt+=temp;
	}

	return cnt+1;
}

void solve(){
	cin>>n;
	for (int i = 1;i <= n;i++) {
 		point[i].clear(), w.clear();
 	}

	for(int i=0;i<n-1;i++){
		int u,v;
		cin>>u>>v;

		point[u].push_back(v);
		point[v].push_back(u);
	}

	cin>>m;

	vector<ll> pr(m);
	for(int i=0;i<m;i++){
		cin>>pr[i];
	}

	if(m<n-1){
		for(int i=m+1;i<n;i++){
			pr.push_back(1);
		}
	}
	sort(pr.begin(),pr.end());

	if(m>n-1){
		for(int i=n-1;i<m;i++){
			pr[n-2]=(pr[n-2]*pr[i])%M;
		}
	}

	dfs(1,0);
	sort(w.begin(),w.end());

	ll ans=0;
	for(int i=0;i<n-1;i++){
		ans=(ans+pr[i]*w[i])%M;
	}

	cout<<ans<<endl;
}

int main(){
	int t;
	cin>>t;

	while(t--){
		solve();
	}
}