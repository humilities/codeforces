#include "testlib.h"
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    // 参数 1: t (测试用例数)
    // 参数 2: max_n (每个 case 的最大 n)
    // 参数 3: max_a (a_i 的最大值)
    // 参数 4: mode (0: 完全随机, 1: 强制有解, 2: 极端数据)
    
    int t = opt<int>(1);
    int max_n = opt<int>(2);
    long long max_a = opt<long long>(3);
    int mode = opt<int>(4);

    printf("%d\n", t);
    while (t--) {
        int n = rnd.next(max_n / 2, max_n);
        vector<long long> a(n);
        long long sum = 0;

        for (int i = 0; i < n; i++) {
            a[i] = rnd.next(1LL, max_a);
            sum += a[i];
        }

        if (mode == 1) { // 强制有解模式：调整最后一个数使总和能被 n 整除
            long long rem = sum % n;
            if (rem != 0) {
                a[n - 1] += (n - rem);
            }
        } else if (mode == 2) { // 极端构造：大部分是 1，最后一个极大
            for(int i = 0; i < n - 1; i++) a[i] = 1;
            a[n-1] = max_a;
        }

        printf("%d\n", n);
        for (int i = 0; i < n; i++) {
            printf("%lld%c", a[i], i == n - 1 ? '\n' : ' ');
        }
    }
    return 0;
}