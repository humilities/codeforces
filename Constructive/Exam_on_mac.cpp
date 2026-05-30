//1935D
//#include <iostream>
//
//using namespace std;
//
//int T, n, c, sum[2]; // sum[0] 记录偶数个数，sum[1] 记录奇数个数
//long long ans; // 答案开 long long
//
//void Solve() {
//    cin >> n >> c;
//    ans = 1ll * (c + 2) * (c + 1) / 2; // 初始数对个数
//    for (int i = 1, x; i <= n; i++) {
//        cin >> x, ans -= x / 2 + 1 + c - x + 1, sum[x % 2]++; // 减去满足任意一个条件的数对个数
//    }
//    cout << ans + 1ll * (sum[0] + 1) * sum[0] / 2 + 1ll * (sum[1] + 1) * sum[1] / 2; // 加上满足两个条件的数对个数
//    sum[0] = sum[1] = 0;
//}
//
//int main() {
//    ios::sync_with_stdio(0), cin.tie(0);
//    for (cin >> T; T--; Solve(), cout << '\n') {}
//    return 0;
//}