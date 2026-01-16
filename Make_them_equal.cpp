//#include<iostream>
//#include<vector>
//
//using namespace std;
//
//const int MAXN = 1005;
//const int MAXV = 1000;
//int dp[MAXN];
//
//void precompute() {
//	for (int i = 2;i <= MAXV;i++) {
//		dp[i] = INT_MAX;
//	}
//
//	for (int i = 1;i <= MAXV;i++) {
//		for (int j = 1;j <= i;j++) {
//			int num = i + i / j;
//			if (num <= MAXV) {
//				dp[num] = min(dp[num], dp[i] + 1);
//			}
//		}
//	}
//}
//
//int main() {
//	precompute();
//	int t;
//	cin >> t;
//	while (t--) {
//		int n, k;
//		cin >> n >> k;
//		vector<int> b(n), c(n);
//
//		for (int i = 0;i < n;i++) {
//			cin >> b[i];
//		}
//		for (int i = 0;i < n;i++) {
//			cin >> c[i];
//		}
//		int total_weight = 0;
//		vector<int> weight;
//
//		for (int i = 0;i < n;i++)
//		{
//			int w = dp[b[i]];
//			weight.push_back(w);
//			total_weight += w;
//		}
//
//		int cap = min(k, total_weight);
//		vector<int> f(cap+1,0);
//
//		for (int i = 0;i < n;i++) {
//			int w = weight[i];
//			int num = c[i];
//			for (int j = cap;j >= w;j--) {
//				f[j] = max(f[j], f[j - w] + num);
//			}
//		}
//
//		cout << f[cap] << endl;
//	}
//	return 0;
//}