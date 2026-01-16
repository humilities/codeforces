#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve(){
	int n;
	cin>>n;

	//int temp=n;

	while(n>9){
		int cnt=0;
		int temp=n;
		while(temp){
			temp/=10;
			cnt++;
		}

		cnt/=2;
		int pre=n/(int)pow(10,cnt);
		int suf=n%(int)pow(10,cnt);

		n=pre+suf;
		//printf("%d ",n);
	}

	//cout<<endl;

	cout<<n<<endl;
}

int main(){
	int t;
	cin>>t;

	while(t--){
		solve();
	}

	return 0;
}
