#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];

  // 为了快速统计后面相同元素的个数，我们从后往前遍历并记录频率
  vector<int> ans(n);
  map<int, int> freq; // 使用 map 处理大数值 a[i]

  for (int i = n - 1; i >= 0; i--) {
    int total_behind = n - 1 - i;      // i 之后的总元素个数
    int same_behind = freq[abs(a[i])]; // i 之后与 a[i] 相同的个数

    ans[i] = total_behind - same_behind;

    // 更新频率表，供前面的元素使用
    freq[abs(a[i])]++;
  }

  // 输出结果
  for (int i = 0; i < n; i++) {
    cout << ans[i] << (i == n - 1 ? "" : " ");
  }
  cout << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
