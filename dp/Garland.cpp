//1286A

//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <climits>
//
//using namespace std;
//
//int main() {
//    int n;
//    cin >> n;
//    vector<int> arr(n);
//    vector<bool> used(n + 1, false);
//
//    for (int i = 0; i < n; i++) {
//        cin >> arr[i];
//        if (arr[i] != 0) {
//            used[arr[i]] = true;
//        }
//    }
//
//    // 计算可用的偶数和奇数数量
//    int even_avail = 0, odd_avail = 0;
//    for (int i = 1; i <= n; i++) {
//        if (!used[i]) {
//            if (i % 2 == 0) {
//                even_avail++;
//            }
//            else {
//                odd_avail++;
//            }
//        }
//    }
//
//    // DP状态: dp[已用偶数][已用奇数][上一个类型]
//    // 上一个类型: 0=偶数, 1=奇数, 2=未定义(开始)
//    const int INF = 1e9;
//    vector<vector<vector<int>>> dp(
//        even_avail + 1,
//        vector<vector<int>>(
//            odd_avail + 1,
//            vector<int>(3, INF)
//        )
//    );
//
//    dp[0][0][2] = 0;  // 初始状态
//
//    for (int i = 0; i < n; i++) {
//        vector<vector<vector<int>>> new_dp(
//            even_avail + 1,
//            vector<vector<int>>(
//                odd_avail + 1,
//                vector<int>(3, INF)
//            )
//        );
//
//        for (int even_used = 0; even_used <= even_avail; even_used++) {
//            for (int odd_used = 0; odd_used <= odd_avail; odd_used++) {
//                for (int last_type = 0; last_type < 3; last_type++) {
//                    if (dp[even_used][odd_used][last_type] == INF) {
//                        continue;
//                    }
//
//                    int current_val = dp[even_used][odd_used][last_type];
//
//                    if (arr[i] != 0) {  // 固定灯泡
//                        int bulb_type = (arr[i] % 2 == 0) ? 0 : 1;
//                        int cost = (last_type == 2 || last_type == bulb_type) ? 0 : 1;
//                        new_dp[even_used][odd_used][bulb_type] = min(
//                            new_dp[even_used][odd_used][bulb_type],
//                            current_val + cost
//                        );
//                    }
//                    else {  // 空灯泡 - 尝试两种可能性
//                        // 尝试偶数
//                        if (even_used < even_avail) {
//                            int cost = (last_type == 2 || last_type == 0) ? 0 : 1;
//                            new_dp[even_used + 1][odd_used][0] = min(
//                                new_dp[even_used + 1][odd_used][0],
//                                current_val + cost
//                            );
//                        }
//
//                        // 尝试奇数
//                        if (odd_used < odd_avail) {
//                            int cost = (last_type == 2 || last_type == 1) ? 0 : 1;
//                            new_dp[even_used][odd_used + 1][1] = min(
//                                new_dp[even_used][odd_used + 1][1],
//                                current_val + cost
//                            );
//                        }
//                    }
//                }
//            }
//        }
//
//        dp = move(new_dp);
//    }
//
//    // 找出最小复杂度
//    int result = min(dp[even_avail][odd_avail][0], dp[even_avail][odd_avail][1]);
//    cout << result << endl;
//
//    return 0;
//}