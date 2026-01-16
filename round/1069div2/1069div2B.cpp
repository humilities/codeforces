#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve(){
	int n,l,r;
	cin>>n>>l>>r;

	vector<int> num(n+1);

	for(int i=0;i<=n;i++){
		num[i]=i;

		if(l==1){
			num[r]=0;
		}
		else{
			num[r]=l-1;
		}
	}

	for(int i=1;i<=n;i++){
		cout<<(num[i]^num[i-1])<<" ";
	}
	cout<<endl;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin>>t;

	while(t--){
		solve();
	}

	return 0;
}