#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

/**
 * @brief 将数字 n 分解为 n = R * 2^e2 * 3^e3 * 5^e5 的形式。
 * * @param n 原始数字
 * @return tuple<long long, int, int, int> {基数 R, e2, e3, e5}
 */
tuple<long long, int, int, int> factorize(long long n) {
    int e2 = 0;
    int e3 = 0;
    int e5 = 0;

    // 计数并消除因子 2
    while (n > 0 && n % 2 == 0) {
        n /= 2;
        e2++;
    }
    // 计数并消除因子 3
    while (n > 0 && n % 3 == 0) {
        n /= 3;
        e3++;
    }
    // 计数并消除因子 5
    while (n > 0 && n % 5 == 0) {
        n /= 5;
        e5++;
    }

    // n 现在就是基数 R
    return {n, e2, e3, e5};
}

void solve() {
    long long a, b;
    if (!(cin >> a >> b)) return;

    // 初始相等，操作数为 0
    if (a == b) {
        cout << 0 << endl;
        return;
    }

    // 分解 a 和 b
    auto [x, a2, a3, a5] = factorize(a);
    auto [y, b2, b3, b5] = factorize(b);

    // 1. 可达性判断
    // 如果基数 x != y，则不可能相等
    if (x != y) {
        cout << -1 << endl;
    } else {
        // 2. 最小操作数计算
        // M = |a2 - b2| + |a3 - b3| + |a5 - b5|
        long long M = abs(a2 - b2) + abs(a3 - b3) + abs(a5 - b5);
        cout << M << endl;
    }
}

int main() {
    // 优化 I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}