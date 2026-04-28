//#include<iostream>
//#include<vector>
//#include<algorithm>
//
//using namespace std;
//
//int main() {
//	int n, m;
//	cin >> n >> m;
//
//	vector<pair<int, int>> num(n);
//
//	for (int i = 0;i < n;i++) {
//		cin >> num[i].first;
//		num[i].second = i;
//	}
//
//	sort(num.begin(), num.end());
//
//	vector<int> color(n);
//	for (int i = 0;i < n;i++) {
//		color[num[i].second] = i % 2;
//	}
//
//	vector<pair<int, int>> seg(m);
//	for (int i = 0;i < m;i++) {
//		cin >> seg[i].first >> seg[i].second;
//	}
//
//	bool flag = true;
//	for (auto const& se : seg) {
//		int l = se.first;
//		int r = se.second;
//		int red = 0, blue = 0;
//
//		for (int i = 0;i < n;i++) {
//			int x = num[i].first;
//
//			if (x >= l && x <= r) {
//				if (color[num[i].second] == 0) {
//					red++;
//				}
//				else {
//					blue++;
//				}
//			}
//		}
//
//		if (abs(red - blue) > 1) {
//			flag = false;
//			break;
//		}
//	}
//
//	if (flag) {
//		for (int c : color) {
//			cout << c << " ";
//		}
//	}
//	else {
//	    for (int i = 0;i < n;i++) {
//		    color[num[i].second] = 1 - i % 2;
//	    }
//
//		bool flag = true;
//		for (auto const& se : seg) {
//			int l = se.first;
//			int r = se.second;
//			int red = 0, blue = 0;
//
//			for (int i = 0;i < n;i++) {
//				int x = num[i].first;
//
//				if (x >= l && x <= r) {
//					if (color[num[i].second] == 0) {
//						red++;
//					}
//					else {
//						blue++;
//					}
//				}
//			}
//
//			if (abs(red - blue) > 1) {
//				flag = false;
//				break;
//			}
//		}
//
//		if (flag) {
//			for (int c : color) {
//				cout << c << " ";
//			}
//		}
//		else {
//			cout << -1 << endl;
//		}
//    }
//
//	return 0;
//}