////1221D
//#include<iostream>
//#include<vector>
//
//using namespace std;
//typedef long long ll;
//
//void solve() {
//	int n;
//	cin >> n;
//
//	vector<ll> length(n);
//	vector<ll> prices(n);
//
//	for (int i = 0;i < n;i++) {
//		cin >> length[i] >> prices[i];
//	}
//
//	vector<ll> dp_prev(3);
//	vector<ll> dp_curr(3, 0);
//
//	dp_prev[0] = 0;
//	dp_prev[1] = prices[0];
//	dp_prev[2] = prices[0] * 2;
//
//	for (int i = 1;i < n;i++) {
//		for (int j = 0;j < 3;j++) {
//
//			ll min_prev = LLONG_MAX;
//
//			for (int k = 0;k < 3;k++) {
//
//				if (length[i - 1] + k != length[i] + j) {
//					if (dp_prev[k] < min_prev) {
//						min_prev = dp_prev[k];
//					}
//				}
//
//			}
//			dp_curr[j] = (ll)prices[i] * j + min_prev;
//		}
//
//		dp_prev = dp_curr;
//	}
//
//	cout << min(dp_curr[0], min(dp_curr[1], dp_curr[2])) << endl;
//
//	return;
//}
//
//int main() {
//	int q;
//	cin >> q;
//
//	while (q--) {
//		solve();
//	}
//	return 0;
//}



#include<bits/stdc++.h>

using namespace std;

int main(){
	return 0;
}
