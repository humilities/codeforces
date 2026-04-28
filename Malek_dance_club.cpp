//#include <iostream>
//#include <string>
//
//using namespace std;
//
//const int MOD = 1000000007;
//
//long long fast_pow(long long base, int exponent) {
//    long long result = 1;
//    while (exponent > 0) {
//        if (exponent % 2 == 1) {
//            result = (result * base) % MOD;
//        }
//        base = (base * base) % MOD;
//        exponent /= 2;
//    }
//    return result;
//}
//
//int main() {
//    string x;
//    cin >> x;
//    int n = x.size();
//    long long ans = 0;
//    for (int k = 0; k < n; ++k) {
//        if (x[n - 1 - k] == '1') {
//            int exponent = n + k - 1;
//            ans = (ans + fast_pow(2, exponent)) % MOD;
//        }
//    }
//    cout << ans << endl;
//    return 0;
//}