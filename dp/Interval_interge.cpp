//106208A

//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//const int MOD = 998244353;
//const int MAXN = 2000005;
//
//long long A[MAXN];
//long long B[MAXN];
//long long inv[MAXN]; // Linear inverse array
//
//void precompute() {
//    // 1. Precompute modular inverses
//    inv[1] = 1;
//    for (int i = 2; i < MAXN; i++) {
//        inv[i] = (MOD - (MOD / i) * inv[MOD % i] % MOD) % MOD;
//    }
//
//    // 2. Base case n = 1
//    A[1] = 1;
//    B[1] = 0;
//
//    // Running sums
//    long long P_A = 1; // Sum of A[k]
//    long long S_A = 0; // Sum of (n-k+1)A[k]
//
//    long long P_B = 0; // Sum of B[k]
//    long long S_B = 0; // Sum of (n-k+1)B[k]
//
//    long long Q = 0;   // Helper for T
//    long long T = 0;   // Sum of A[k] * (n-k)(n-k+1)/2
//
//    long long inv2 = inv[2];
//
//    for (int n = 2; n < MAXN; n++) {
//        // Calculate Kn = n(n+1)/2 - 1
//        long long Kn = (long long)n * (n + 1) % MOD * inv2 % MOD;
//        Kn = (Kn - 1 + MOD) % MOD;
//
//        // Inverse of Kn. 
//        // Note: Kn = (n-1)(n+2)/2. We can use precomputed inv array.
//        // invKn = 2 * inv[n-1] * inv[n+2]
//        long long invKn;
//        if (n + 2 < MAXN) {
//            invKn = 2 * inv[n - 1] % MOD * inv[n + 2] % MOD;
//        }
//        else {
//            // Fallback for edge cases near MAXN boundary if any, 
//            // though n+2 < MAXN usually holds if we size array right.
//            // Using Fermat's Little Theorem for safety if needed, 
//            // but simply sizing array to MAXN + 5 is enough.
//            // Since we sized 2000005 and loop goes to 2000000, n+2 is fine.
//            invKn = 2 * inv[n - 1] % MOD * inv[n + 2] % MOD;
//        }
//
//        // Update S_A
//        // S_A(n) = S_A(n-1) + P_A(n-1) + A(n-1)
//        long long term_A = (P_A + A[n - 1]) % MOD;
//        S_A = (S_A + term_A) % MOD;
//
//        // Calculate A[n]
//        // A[n] = 1 + S_A / Kn  => (Kn + S_A) * invKn
//        A[n] = (Kn + S_A) % MOD * invKn % MOD;
//
//        // Update Q and T
//        // Q(n) = Q(n-1) + P_A(n-1)
//        Q = (Q + P_A) % MOD;
//        // T(n) = T(n-1) + Q(n)
//        T = (T + Q) % MOD;
//
//        // Update S_B
//        // S_B(n) = S_B(n-1) + P_B(n-1) + B(n-1)
//        long long term_B = (P_B + B[n - 1]) % MOD;
//        S_B = (S_B + term_B) % MOD;
//
//        // Calculate B[n]
//        // B[n] = (n-1)/2 + (T + S_B) / Kn
//        long long linear_term = (n - 1) * inv2 % MOD;
//        long long sum_term = (T + S_B) % MOD * invKn % MOD;
//        B[n] = (linear_term + sum_term) % MOD;
//
//        // Update Prefix Sums
//        P_A = (P_A + A[n]) % MOD;
//        P_B = (P_B + B[n]) % MOD;
//    }
//}
//
//void solve() {
//    int l, r;
//    cin >> l >> r;
//    int n = r - l + 1;
//    long long ans = (A[n] * l % MOD + B[n]) % MOD;
//    cout << ans << "\n";
//}
//
//int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
//    precompute();
//    int t;
//    cin >> t;
//    while (t--) {
//        solve();
//    }
//    return 0;
//}