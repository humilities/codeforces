//#include <iostream>
//#include <vector>
//#include <map>
//using namespace std;
//
//int main() {
//    int n;
//    cin >> n;
//    vector<int> a(n), b(n);
//    for (int i = 0; i < n; i++) cin >> a[i];
//    for (int i = 0; i < n; i++) cin >> b[i];
//    long long m;
//    cin >> m;
//
//    map<int, int> cnt_x, pair_x;
//    for (int i = 0; i < n; i++) {
//        cnt_x[a[i]]++;
//        cnt_x[b[i]]++;
//        if (a[i] == b[i]) {
//            pair_x[a[i]]++;
//        }
//    }
//
//    int N = 2 * n;
//    vector<long long> fact(N + 1), fact_no2(N + 1);
//    fact[0] = 1;
//    fact_no2[0] = 1;
//    for (int i = 1; i <= N; i++) {
//        int x = i;
//        int twos = 0;
//        while (x % 2 == 0) {
//            x /= 2;
//            twos++;
//        }
//        fact[i] = (fact[i - 1] * i) % m;
//        fact_no2[i] = (fact_no2[i - 1] * x) % m;
//    }
//
//    long long ans = 1;
//    for (auto& [x, t] : cnt_x) {
//        int p = pair_x[x];
//        
//        int exp2 = 0;
//        int tmp = t;
//        while (tmp) {
//            tmp /= 2;
//            exp2 += tmp;
//        }
//
//        if (exp2 < p) {
//            ans = 0;
//            break;
//        }
//
//        long long fact_t_no2 = fact_no2[t];
//        
//        long long pow2 = 1;
//        int exp = exp2 - p;
//        long long base = 2;
//        while (exp > 0) {
//            if (exp & 1) {
//                pow2 = (pow2 * base) % m;
//            }
//            base = (base * base) % m;
//            exp >>= 1;
//        }
//
//        ans = (ans * fact_t_no2) % m;
//        ans = (ans * pow2) % m;
//    }
//
//    cout << ans << endl;
//
//    return 0;
//}