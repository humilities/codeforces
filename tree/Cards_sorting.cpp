//830B

// # include <stdio.h>
// #include<vector>
// #include<iostream>
// #include<algorithm>

// using namespace std;
// const int maxn = 1e5;
// int a[maxn + 3], b[maxn + 3];
// vector<int>v[maxn + 3];

// void update(int x, int m)
// {
//    while (x <= maxn) b[x] += m, x += x & -x;
// }


// int sum(int x)
// {
//    int s = 0;
//    while (x) s += b[x], x -= x & -x;
//    return s;
// }


// int main()
// {
//    int n;
//    cin>>n;

//    for (int i = 1; i <= n; ++i) cin>>a[i], v[a[i]].push_back(i);

//    int pre = 0;
//    long long ans = 0;
//    sort(a + 1, a + 1 + n);

//    for (int i = 1; i <= n;)
//    {
//        int pos = lower_bound(v[a[i]].begin(), v[a[i]].end(), pre) - v[a[i]].begin();
//        if (pos == 0)
//        {
//            pos = v[a[i]][v[a[i]].size() - 1];
//            ans += pos - pre - sum(pos) + sum(pre);
//        }

//        else
//        {
//            pos = v[a[i]][pos - 1];
//            ans += n - pre + pos - sum(n) + sum(pre) - sum(pos);
//        }

//        pre = pos;
//        for (int j = 0; j < v[a[i]].size(); ++j) update(v[a[i]][j], 1);

//        i += v[a[i]].size();
//    }

//    printf("%lld\n", ans);
//    return 0;
// }


#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N=1e5;
int a[N+3],b[N+3];
vector<int> v[N+3];

void update(int x,int m){
	while(x<=N){
		b[x]+=m;
		x+=x&-x;
	}
}

ll sum(int x){
	ll s=0;
	while(x){
		s+=b[x];
		x-=x&-x;
	}

	return s;
}

int main(){
	int n;
	cin>>n;

	for(int i=1;i<=n;i++){
		cin>>a[i];
		v[a[i]].push_back(i);
	}

	sort(a+1,a+1+n);

	int pre=0;
	ll ans=0;
	for(int i=1;i<=n;){
		int lo=lower_bound(v[a[i]].begin(),v[a[i]].end(),pre)-v[a[i]].begin();

		if(lo==0){
			lo=v[a[i]][v[a[i]].size()-1];
			ans+=lo-pre-sum(lo)+sum(pre);
		}
		else{
			lo=v[a[i]][lo-1];
			ans+=n-pre+lo-sum(n)+sum(pre)-sum(lo);
		}

		pre=lo;
		for(int j=0;j<v[a[i]].size();j++){
			update(v[a[i]][j],1);
		}

		i+=v[a[i]].size();
	}

	cout<<ans<<endl;
	return 0;
}