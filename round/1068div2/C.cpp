// #include<bits/stdc++.h>

// using namespace std;

// typedef long long ll;
// const int N=1e9+7;
// const int M=1e6+7;

// vector<vector<ll>> ma(M,vector<ll>(N));
// ll prime[M];

// void prim(){
// 	for(ll i=2;i<M;i++){
// 		if(prime[i]==0){
// 			prime[i]=i;
// 		}

// 		for(ll j=i*i;j<M;j+=i){
// 			if(prime[j]==0){
// 				prime[j]=i;
// 			}
// 		}
// 	}
// }

// void solve(){
// 	int n,k;
// 	cin>>n>>k;

// 	for(int i=0;i<n;i++){
// 		int val;
// 		cin>>val;

// 		ll div=prime[val];
// 		ll remain=val/div;

// 		ma[div].push_back(remain);
// 	}

// 	vector<ll> b;
// 	bool flag1=true;
// 	bool flag2=true;
// 	for(int i=0;i<M;i++){
// 		if(ma[i].size()==0){
// 			continue;
// 		}

// 		else{
// 			for(ll j=1;j<ma[i].size();j++){
// 				if((ma[i][j]-ma[i][j-1])>1){
// 					flag1=false;
// 					break;
// 				}
// 			}

// 			if(!flag1){
// 				cout<<-1<<endl;
// 				flag2=false;
// 			}
// 			else{
// 				b.push_back(i);
// 			}
// 		}
// 	}

// 	if(flag2){
// 		cout<<b.size()<<endl;

// 		for(int i=0;i<b.size();i++){
// 			cout<<b[i];
// 		}

// 		cout<<endl;
// 	}
// }

// int main(){
// 	int t;
// 	cin>>t;
// 	prim();

// 	while(t--){
// 		solve();
// 	}
// 	return 0;
// }


#include<bits/stdc++.h>

using namespace std;

void solve(){
	int n,k;
	cin>>n>>k;

	set<int> s1,s2,s3;

	for(int i=0;i<n;i++){
		int val;
		cin>>val;

		s1.insert(val);
		s2.insert(val);
	}

	while(s1.size()){
		int u=*begin(s1);

		for(int j=u;j<=k;j+=u){
			if(s2.find(j)==s2.end()){
				cout<<-1<<endl;
				return;
			}
			s1.erase(j);
		}

		s3.insert(u);
	}

	cout<<s3.size()<<endl;

	for(int i:s3){
		cout<<i<<" ";
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