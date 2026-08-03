#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve(){
	int n;
	cin>>n;

	vector<ll> a(n),b(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		cin>>b[i];
	}

	ll L=0,R=0;
	for(int i=0;i<n;i++){
		ll newl=min(L-a[i],b[i]-R);
		ll newr=max(R-a[i],b[i]-L);

		L=newl;
		R=newr;
	}

	cout<<R<<endl;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		solve();
	}

	return 0;
}