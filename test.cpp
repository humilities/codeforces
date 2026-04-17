#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/**
 * 题目逻辑：
 * 1. 预处理 a[i]，确保 a[i] 随 i 递增且满足后缀限制。
 * 2. 计算出选 k 枚硬币时，每一枚硬币的最小可能取值 L_prime[j]。
 * 3. 确定 k 的合法上界 K_upper。
 * 4. 遍历 k，寻找满足 [S_min, S_max] 包含 m 的 k。
 * 5. 使用贪心策略从最大面值开始调整，补齐差额。
 */

void solve() {
  int n;
  long long m;
  if (!(cin >> n >> m))
    return;

  vector<int> a(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }

  // 1. 约束预处理：a[i] 表示面值 <= i 的硬币至多 a_i 枚
  // 如果 a[i] > a[i+1]，则 a[i] 实际上被限制在了 a[i+1]
  for (int i = n - 1; i >= 1; --i) {
    if (a[i] > a[i + 1])
      a[i] = a[i + 1];
  }

  // 2. 计算 k 的上界：对于任意 i，k - (n - i) <= a[i] => k <= a[i] + n - i
  int k_upper = n;
  for (int i = 1; i <= n; ++i) {
    k_upper = min(k_upper, a[i] + n - i);
  }

  // 3. 计算第 j 枚硬币的最小可能面值 L_prime[j]
  // L_j 是使得 a[i] >= j 的最小 i
  vector<int> l_prime(k_upper + 1);
  int p = 1;
  for (int j = 1; j <= k_upper; ++j) {
    while (p <= n && a[p] < j)
      p++;
    if (j == 1) {
      l_prime[j] = p;
    } else {
      l_prime[j] = max(p, l_prime[j - 1] + 1);
    }
  }

  // 4. 寻找合法的 k
  int best_k = -1;
  long long current_s_min = 0;
  for (int k = 1; k <= k_upper; ++k) {
    current_s_min += l_prime[k];
    // 这里的 s_max 是选最大的 k 个硬币的和
    long long current_s_max = 1LL * k * n - 1LL * k * (k - 1) / 2;

    if (m >= current_s_min && m <= current_s_max) {
      best_k = k;
      break;
    }
  }

  if (best_k == -1) {
    cout << -1 << "\n";
    return;
  }

  // 5. 构造答案：从 S_min 开始向上调整
  vector<int> res(best_k + 1);
  long long current_sum = 0;
  for (int j = 1; j <= best_k; ++j) {
    res[j] = l_prime[j];
    current_sum += res[j];
  }

  long long diff = m - current_sum;
  // 从最后一枚硬币开始，尽可能调大面值
  for (int j = best_k; j >= 1 && diff > 0; --j) {
    int upper_limit = (j == best_k) ? n : res[j + 1] - 1;
    int can_add = min((long long)upper_limit - res[j], diff);
    res[j] += can_add;
    diff -= can_add;
  }

  // 输出结果
  cout << best_k << "\n";
  for (int j = 1; j <= best_k; ++j) {
    cout << res[j] << (j == best_k ? "" : " ");
  }
  cout << "\n";
}

int main() {
  // 关掉同步流提高 I/O 速度
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  if (!(cin >> t))
    return 0;
  while (t--) {
    solve();
  }
  return 0;
}
