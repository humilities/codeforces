// #include <bits/stdc++.h>
//
// #define lin(i, a, b) for (int i = (a); i < (b); i++)
// using namespace std;
// using ll = long long;
//
// void solve() {
//   int n;
//   cin >> n;
//
//   string s[2];
//   cin >> s[0] >> s[1];
//
//   vector<vector<bool>> vis(n, vector<bool>(n, false));
//   queue<pair<int, int>> q;
//
//   q.push({0, 0});
//   vis[0][0] = true;
//
//   while (!q.empty()) {
//     auto [r, c] = q.front();
//     q.pop();
//
//     int dr[] = {0, 0, 1, -1};
//     int dc[] = {1, -1, 0, 0};
//
//     if (r == 1 && c == n - 1) {
//       cout << "YES" << "\n";
//       return;
//     }
//
//     for (int i = 0; i < 4; i++) {
//       int nx = r + dr[i];
//       int ny = c + dc[i];
//
//       if (nx >= 0 && nx < 2 && ny >= 0 && ny < n) {
//         int mx = nx;
//         int my = ny + (s[nx][ny] == '<' ? -1 : 1);
//
//         if (my >= 0 && my < n && !vis[mx][my])
//           vis[mx][my] = true, q.push({mx, my});
//       }
//     }
//   }
//
//   cout << "NO" << "\n";
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
//

#include <bits/stdc++.h>

#define lin(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;

  vector<int> a1(n / 2), a2(n / 2);
  for (int i = 0; i < 2; i++) {
    string s;
    cin >> s;

    for (int j = 0; j < n; j++)
      if ((i + j) & 1) {
        a1[(i + j) / 2] |= (s[j] == '>');
        a2[(j - i + 1) / 2] |= (s[j] == '>');
      }
  }

  bool ans = true;
  for (int i = 0; i < n / 2; i++)
    ans &= a1[i] && a2[i];

  cout << (ans ? "YES" : "NO") << "\n";
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
