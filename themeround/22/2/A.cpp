#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;

  vector<int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];

  string ans;
  int l = 0;
  int r = n - 1;
  int flag = 1;

  while (l <= r) {
    if (flag & 1) {
      if (a[l] < a[r]) {
        ans += 'L';
        l++;

        flag = abs(flag - 1);
      } else {
        ans += 'R';
        r--;

        flag = abs(flag - 1);
      }
    } else {
      if (a[l] < a[r]) {
        ans += 'R';
        r--;

        flag = abs(flag - 1);
      } else {
        ans += 'L';
        l++;

        flag = abs(flag - 1);
      }
    }
  }

  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;

  while (t--)
    solve();

  return 0;
}

// #include <bits/stdc++.h>
//
// using namespace std;
//
// void solve() {
//   int n;
//   cin >> n;
//
//   vector<int> a(n);
//   for (int i = 0; i < n; i++)
//     cin >> a[i];
//
//   string ans;
//   int l = 0;
//   int r = n - 1;
//   bool odd_turn = true; // true 代表奇数轮取最小，false 代表偶数轮取最大
//
//   while (l <= r) {
//     // 如果 (a[l] < a[r]) 与 odd_turn 同真或同假，说明应该选择左边
//     if ((a[l] < a[r]) == odd_turn) {
//       ans += 'L';
//       l++;
//     } else {
//       ans += 'R';
//       r--;
//     }
//     odd_turn = !odd_turn; // 切换轮次
//   }
//
//   cout << ans << "\n";
// }
//
// int main() {
//   ios_base::sync_with_stdio(false);
//   cin.tie(NULL);
//
//   int t;
//   cin >> t;
//
//   while (t--)
//     solve();
//
//   return 0;
// }
