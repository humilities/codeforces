#include<bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin>>t;

	while(t--){
		int n;
		cin>>n;

		set<int> col;

		for(int i=0;i<n;i++){
			int val;
			cin>>val;

			col.insert(val);
		}

		int dis=col.size();
		int cur=dis;

		while(col.find(cur)==col.end()){
			col.insert(cur);
			cur++;
		}

		cout<<cur<<endl;
	}

	return 0;
}