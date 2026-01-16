//#include<iostream>
//#include<vector>
//
//using namespace std;
//
//int cnt(int n) {
//	return n * (n - 1) * (n - 2) / 6;
//}
//
//int add(int n) {
//	return n * (n - 1) / 2;
//}
//
//int main() {
//	int k;
//	int m = 0;
//	cin >> k;
//
//	int l = 1, r = 100;
//	while (l <= r) {
//		int mid = l + (r - l) / 2;
//
//		if (cnt(mid) > k&&cnt(mid-1) < k) {
//			m = mid-1;
//			break;
//		}
//
//		else if (cnt(mid) > k && cnt(mid - 1) > k) {
//			r = mid - 1;
//			continue;
//		}
//
//		else {
//			l = mid + 1;
//			continue;
//		}
//	}
//
//	int k_rem = k - cnt(m);
//	
//	vector<vector<int>> ad(100, vector<int>(100, 0));
//
//	for (int i = 0;i < m;i++) {
//		for (int j = i + 1;j < m;j++) {
//			ad[i][j] = 1;
//			ad[j][i] = 1;
//		}
//	}
//
//	while (k_rem > 0) {
//		int d = 1;
//		while (d <= m && add(d) <= k_rem) {
//			d++;
//		}
//		d--;
//
//		for (int i = 0;i < d;i++){
//			ad[m][i] = 1;
//			ad[i][m] = 1;
//		}
//		
//		k_rem -= add(d);
//		m++;
//	}
//
//	cout << m << endl;
//	for (int i = 0;i < m;i++) {
//		for (int j = 0;j < m;j++) {
//			cout << ad[i][j];
//		}
//		cout << endl;
//	}
//
//	return 0;
//}