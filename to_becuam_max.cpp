//#include<iostream>
//#include<algorithm>
//#include<vector>
//#include<numeric>
//
//using namespace std;
//
//bool check(const vector<int>& a, int n, int k, int target) {
//	for (int i = 0;i < n;i++) {
//		int operation = 0;
//		int cur = target;
//
//		for (int j = i;j < n;j++) {
//
//			if (a[j] >= cur) {
//				return true;
//			}
//
//			operation += cur - a[j];
//			if (operation > k) {
//				break;
//			}
//
//			cur--;
//		}
//	}
//
//	return false;
//}
//
//void solve() {
//	int n, k;
//	int Max=0;
//	cin >> n >> k;
//	vector<int> a(n);
//
//	for (int i = 0;i < n;i++) {
//		cin >> a[i];
//
//		Max = max(Max, a[i]);
//	}
//
//	int low = Max;
//	int high = Max + k;
//	int ans = Max;
//
//	while (low <= high) {
//		int mid = low + (high - low) / 2;
//
//		if (check(a, n, k, mid)) {
//			ans = mid;
//			low = mid + 1;
//		}
//		else {
//			high = mid - 1;
//		}
//	}
//
//	cout << ans << endl;
//}
//
//int main() {
//	int t;
//	cin >> t;
//
//	while (t--) {
//		solve();
//	}
//
//	return 0;
//}