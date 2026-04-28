#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	int n;
	cin>>n;

	vector<ll> num(n);
	ll cnt=0;

	for(int i=0;i<n;i++){
		cin>>num[i];
		cnt+=num[i];
	}

	ll div=cnt/n;
	ll ans=0;
	for(int i=0;i<n-1;i++){

		if(num[i]>div){
			ll temp=num[i]-div;
			num[i]-=temp;

			num[i+1]+=temp;
			ans+=temp;
		}
		else{
			ll temp=div-num[i];
			num[i+1]-=temp;

			ans+=temp;
			num[i]+=temp;
		}
	}

	cout<<ans<<endl;

	return 0;
}