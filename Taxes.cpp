//#include<iostream>
//#include<vector>
//
//using namespace std;
//typedef long long ll;
//
//void solve(ll n) {
//	const int s = 100000;
//	vector<ll> prime;
//	int nsqrt = sqrt(n);
//	vector<bool> is_prime(nsqrt + 1, true);
//
//	for (int i = 2;i <= nsqrt;i++) {
//		if (is_prime[i]) {
//			prime.push_back(i);
//			for (int j = i * i;j < nsqrt;j += i) {
//				is_prime[j] = false;
//			}
//		}
//	}
//
//	vector<bool> allprimes;
//	vector<bool> block(s,true);
//
//	for (int i = 0;i * s <= n;i ++) {
//		int start = i * s;
//
//		for (ll p : prime) {
//			int start_idx = (start + p - 1) / p;
//			int j = max((long long)start_idx, p) * p - start;
//
//			for (;j < s && start + j <= n;j += p) {
//				block[j] = false;
//			}
//		}
//
//		if (i == 0) {
//			block[0] = 0;
//			block[1] = 0;
//		}
//
//		for (int i = 0;i < s && start + i <= n;i++) {
//			if (block[i]) {
//				allprimes.push_back(true);
//			}
//		}
//	}
//
//	int ans = 0;
//	int remain = 0;
//	while (n) {
//		int temp = n - 1;
//		
//		if (allprimes[temp]) {
//			++remain;
//			ans++;
//		}
//
//		n = remain;
//	}
//
//	cout << ans << endl;
//}
//
//int main() {
//	ll n;
//	cin >> n;
//
//	solve(n);
//
//	return 0;
//}

//#include <iostream>
//#include <cmath>
//using namespace std;
//
//bool isPrime(long long n) {
//    if (n < 2) return false;
//    if (n == 2) return true;
//    if (n % 2 == 0) return false;
//    for (long long i = 3; i * i <= n; i += 2) {
//        if (n % i == 0) return false;
//    }
//    return true;
//}
//
//int main() {
//    long long n;
//    cin >> n;
//
//    if (isPrime(n)) {
//        cout << 1 << endl;
//    }
//    else if (n % 2 == 0) {
//        cout << 2 << endl;
//    }
//    else {
//        if (isPrime(n - 2)) {
//            cout << 2 << endl;
//        }
//        else {
//            cout << 3 << endl;
//        }
//    }
//
//    return 0;
//}