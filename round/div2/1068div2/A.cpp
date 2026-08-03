#include<bits/stdc++.h>

using namespace std;

void solve(){
	int n,k;
	cin>>n>>k;

	vector<char> str(n);

	for(int i=0;i<n;i++){
		cin>>str[i];
	}

	int ans=0;
	for(int i=0;i<n;i++){
		if(str[i]=='2') continue;

		if(str[i]=='0') ans++;

		if(str[i]=='1'){
			int remain=min(k,n-i-1);

			for(int j=i+1;j<=i+remain;j++){
				if(str[j]=='1') continue;
				str[j]='2';
				//printf("%d ",ans);
			}
		}
	}

	cout<<ans<<endl;
}

int main(){
	int t;
	cin>>t;

	while(t--){
		solve();
	}

	return 0;
}