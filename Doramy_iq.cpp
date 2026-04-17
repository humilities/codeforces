//#include<iostream>
//#include<vector>
//
//using namespace std;
//
//void solve() {
//	int n, q;
//	cin >> n >> q;
//
//	vector<int> test(n);
//	for (int i = 0;i < n;i++) {
//		cin >> test[i];
//		if(q>=test[i]){
//			test[i] = 1;
//		}
//		else {
//			test[i] = -1;
//		}
//	}
//
//	string str;
//	int ans = q;
//	int min=0, max=0;
//	vector<pair<int, int>> set;
//	int length = 0;
//
//	for (int l = 0;l < n;) {
//		int r = l;
//		ans += test[r];
//
//		if (ans >= 0) {
//			r++;
//		}
//		else {
//			set.push_back({l,r-1});
//			l = r;
//		}
//	}
//
//	for (int i = 0;i < set.size();i++) {
//		int temp = set[i].second - set[i].first + 1;
//		if (temp > length) {
//			length = temp;
//			min = set[i].first;
//		}
//	}
//
//	for (int i = 0;i < n;i++) {
//		if (i < min) {
//			str.append("0");
//		}
//		if (i >= min && i <= max) {
//			str.append("0");
//		}
//		str.append("0");
//	}
//
//	cout << str << endl;
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


//#include <iostream>
//#include <vector>
//#include <string>
//#include <numeric>
//#include <algorithm>
//
//void solve() {
//    int n;
//    long long q; // q can be up to 10^9, so use long long
//    std::cin >> n >> q;
//    std::vector<long long> a(n);
//    for (int i = 0; i < n; ++i) {
//        std::cin >> a[i];
//    }
//
//    std::string s(n, '0');
//    long long current_iq = 0;
//
//    for (int i = n - 1; i >= 0; --i) {
//        if (a[i] <= current_iq) {
//            s[i] = '1';
//        }
//        else if (current_iq < q) {
//            current_iq++;
//            s[i] = '1';
//        }
//    }
//    std::cout << s << std::endl;
//}
//
//int main() {
//    std::ios_base::sync_with_stdio(false);
//    std::cin.tie(NULL);
//    int t;
//    std::cin >> t;
//    while (t--) {
//        solve();
//    }
//    return 0;
//}
