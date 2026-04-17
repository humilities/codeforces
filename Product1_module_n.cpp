//#include<iostream>
//#include<vector>
//#include<algorithm>
//
//using namespace std;
//
//int gcd(int a, int b) {
//	if (b == 0) return a;
//	return gcd(b, a % b);
//}
//
//int main() {
//	int n;
//	cin >> n;
//	vector<int> list;
//	long long product = 1;
//
//	for (int i = 1;i <= n - 1;i++) {
//		if (gcd(i, n) == 1) {
//			list.push_back(i);
//			product = (product * i) % n;
//		}
//	}
//
//	if (product != 1) {
//		for (auto it = list.begin();it != list.end();it++) {
//			if (*it == n - 1) {
//				list.erase(it);
//				break;
//			}
//		}
//	}
//
//	cout << list.size() << endl;
//	for (int i : list) {
//		cout << i << " ";
//	}
//
//	cout << endl;
//
//	return 0;
//}
