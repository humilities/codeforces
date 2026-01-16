//#include<iostream>
//#include<vector>
//#include<algorithm>
//
//using namespace std;
//
////#define MAX 2000000000;
//
//int main() {
//	int t;
//	cin >> t;
//
//	while (t--) {
//		int n;
//		bool flag = true;
//		cin >> n;
//		//vector<int> a(n);
//		vector<int> vis(n,0);
//
//		for (int i = 0;i < n;i++) {
//			long long val;
//			cin >> val;
//			val = ((val + i) % n+n)%n;
//			if (vis[val] == 1) {
//				flag = false;
//				//break;
//			}
//			vis[val] = 1;
//		}
//
//		if (flag) {
//			cout << "YES" << endl;
//		}
//		else {
//			cout << "NO" << endl;
//		}
//	}
//
//	return 0;
//}