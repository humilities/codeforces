//#include <iostream>
//#include <vector>
//#include <numeric>
//
//int main() {
//    std::ios_base::sync_with_stdio(false);
//    std::cin.tie(NULL);
//    int n;
//    std::cin >> n;
//    std::vector<long long> a(n);
//    for (int i = 0; i < n; ++i) {
//        std::cin >> a[i];
//    }
//
//    if (n == 1) {
//        std::cout << 1 << " " << 1 << std::endl;
//        std::cout << -a[0] << std::endl;
//        std::cout << 1 << " " << 1 << std::endl;
//        std::cout << 0 << std::endl;
//        std::cout << 1 << " " << 1 << std::endl;
//        std::cout << 0 << std::endl;
//        return 0;
//    }
//
//    // Operation 1: Segment [1, n-1]
//    // Length is n-1. Add a multiple of n-1 to make a[i] a multiple of n.
//    std::cout << 1 << " " << n - 1 << std::endl;
//    for (int i = 0; i < n - 1; ++i) {
//        // Calculate the value to add.
//        // We want a[i] + x to be a multiple of n, where x is a multiple of n-1.
//        // x = k * (n-1). (a[i] + k * (n-1)) % n = 0.
//        // (a[i] + k * (-1)) % n = 0 => (a[i] - k) % n = 0 => k = a[i] % n.
//        // so x = (a[i] % n) * (n-1).
//        long long rem = ((a[i] % n) + n) % n;
//        long long val_to_add = rem * (n - 1);
//        std::cout << val_to_add << (i == n - 2 ? "" : " ");
//        a[i] += val_to_add;
//    }
//    std::cout << std::endl;
//
//    // Operation 2: Segment [n, n]
//    // Length is 1. Add any integer to make it 0.
//    std::cout << n << " " << n << std::endl;
//    std::cout << -a[n - 1] << std::endl;
//    a[n - 1] = 0;
//
//    // Operation 3: Segment [1, n]
//    // Length is n. Add a multiple of n to make all elements 0.
//    std::cout << 1 << " " << n << std::endl;
//    for (int i = 0; i < n; ++i) {
//        // After op 1, a[0..n-2] are multiples of n.
//        // After op 2, a[n-1] is 0, which is also a multiple of n.
//        // Add -a[i] to each element. This is a multiple of n.
//        std::cout << -a[i] << (i == n - 1 ? "" : " ");
//    }
//    std::cout << std::endl;
//
//    return 0;
//}