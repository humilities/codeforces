//1517D

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 使用 long long 来存储疲劳值，以防止溢出，虽然题目中最大值是 10^6 * 20，
// 仍在 int 范围内，但使用 long long 更安全。
using ll = long long;

// 定义一个极大的值，表示不可达
const ll INF = 1e18; 

void solve() {
    int n, m, k;
    
    // 读取 N, M, K
    if (!(cin >> n >> m >> k)) return;

    // 1. 奇数 K 处理
    if (k % 2 != 0) {
        // 如果 K 是奇数，则不可能回到起点，输出 -1
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cout << -1 << (j == m - 1 ? "" : " ");
            }
            cout << endl;
        }
        return;
    }

    int K_half = k / 2;

    // 2. 读取边权
    // hori_weights[i][j] 存储 (i, j) 到 (i, j+1) 的边权 (0-indexed)
    // 对应题目中的 i 行 j 列：(i, j) 与 (i, j+1) 的边
    vector<vector<int>> hori_weights(n, vector<int>(m - 1));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m - 1; ++j) {
            cin >> hori_weights[i][j];
        }
    }

    // vert_weights[i][j] 存储 (i, j) 到 (i+1, j) 的边权 (0-indexed)
    // 对应题目中的 i 行 j 列：(i, j) 与 (i+1, j) 的边
    vector<vector<int>> vert_weights(n - 1, vector<int>(m));
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> vert_weights[i][j];
        }
    }

    // 3. 动态规划
    // DP[s][i][j]: 从 (i, j) 出发，经过恰好 s 步后，所能达到的最小疲劳值。
    // 使用三维向量存储 DP 状态，[步数][行][列]
    // 步数从 0 到 K_half
    vector<vector<vector<ll>>> dp(K_half + 1, vector<vector<ll>>(n, vector<ll>(m, INF)));

    // 基础情况：0 步的疲劳值为 0
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            dp[0][i][j] = 0;
        }
    }

    // 状态转移
    for (int s = 1; s <= K_half; ++s) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                ll min_boredness = INF;

                // 尝试向四个方向走一步 (i, j) -> (i', j')
                
                // 1. 向上走 (i, j) -> (i-1, j)
                if (i > 0) {
                    // 边权是 vert_weights[i-1][j]
                    ll weight = vert_weights[i - 1][j];
                    // 转移：w((i, j), (i-1, j)) + DP[s-1][i-1][j]
                    if (dp[s - 1][i - 1][j] != INF) {
                        min_boredness = min(min_boredness, weight + dp[s - 1][i - 1][j]);
                    }
                }

                // 2. 向下走 (i, j) -> (i+1, j)
                if (i < n - 1) {
                    // 边权是 vert_weights[i][j]
                    ll weight = vert_weights[i][j];
                    // 转移：w((i, j), (i+1, j)) + DP[s-1][i+1][j]
                    if (dp[s - 1][i + 1][j] != INF) {
                        min_boredness = min(min_boredness, weight + dp[s - 1][i + 1][j]);
                    }
                }

                // 3. 向左走 (i, j) -> (i, j-1)
                if (j > 0) {
                    // 边权是 hori_weights[i][j-1]
                    ll weight = hori_weights[i][j - 1];
                    // 转移：w((i, j), (i, j-1)) + DP[s-1][i][j-1]
                    if (dp[s - 1][i][j - 1] != INF) {
                        min_boredness = min(min_boredness, weight + dp[s - 1][i][j - 1]);
                    }
                }

                // 4. 向右走 (i, j) -> (i, j+1)
                if (j < m - 1) {
                    // 边权是 hori_weights[i][j]
                    ll weight = hori_weights[i][j];
                    // 转移：w((i, j), (i, j+1)) + DP[s-1][i][j+1]
                    if (dp[s - 1][i][j + 1] != INF) {
                        min_boredness = min(min_boredness, weight + dp[s - 1][i][j + 1]);
                    }
                }

                dp[s][i][j] = min_boredness;
            }
        }
    }

    // 4. 输出最终结果
    // 最终答案是 2 * DP[K_half][i][j]
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            ll result = dp[K_half][i][j];
            
            // 如果仍然是 INF，则输出 -1 (不可达)
            if (result == INF) {
                cout << -1 << (j == m - 1 ? "" : " ");
            } else {
                // 否则输出 2 * 最小 K_half 步路径疲劳值
                cout << result * 2 << (j == m - 1 ? "" : " ");
            }
        }
        cout << endl;
    }
}

int main() {
    // 优化输入/输出速度
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}