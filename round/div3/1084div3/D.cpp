// #include <bits/stdc++.h>
//
// using namespace std;
//
// void solve() {
//   int n, x, y;
//   cin >> n >> x >> y;
//
//   vector<int> a(n);
//   for (int i = 0; i < n; i++)
//     cin >> a[i];
//
//   vector<int> mid;
//   for (int i = x; i < y; i++)
//     mid.push_back(a[i]);
//
//   vector<int> side;
//   for (int i = y; i < n; i++)
//     side.push_back(a[i]);
//   for (int i = 0; i < x; i++)
//     side.push_back(a[i]);
//
//   auto get = [&](vector<int> &v) {
//     int len = v.size();
//     if (len == 0)
//       return v;
//
//     vector<int> dou = v;
//     dou.insert(dou.end(), v.begin(), v.end());
//
//     int i = 0, j = 1, k = 0;
//     while (i < len && j < len && k < len) {
//       int a = dou[i + k];
//       int b = dou[j + k];
//       if (a == b)
//         k++;
//       else {
//         if (a > b)
//           i += k + 1;
//         else
//           j += k + 1;
//         if (i == j)
//           j++;
//         k = 0;
//       }
//     }
//
//     int pos = min(i, j);
//     vector<int> res;
//
//     for (int i = 0; i < len; i++) {
//       res.push_back(dou[pos + i]);
//     }
//
//     return res;
//   };
//
//   vector<int> com = mid;
//   com.insert(com.end(), side.begin(), side.end());
//
//   vector<int> ans = get(com);
//   for (int i = 0; i < n; i++)
//     cout << ans[i] << " \n"[i == n - 1];
//
//   return;
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

using namespace std;

void solve() {
  int n, x, y;
  cin >> n >> x >> y;

  x--, y--;

  vector<int> a;
  vector<int> b;
  for (int i = 0; i < n; i++) {
    int val;
    cin >> val;

    if (i <= x || i > y)
      a.push_back(val);
    else
      b.push_back(val);
  }

  rotate(b.begin(), min_element(b.begin(), b.end()), b.end());
  int m = b[0];

  auto it = a.begin();
  while (it < a.end() && *it < m)
    it++;

  a.insert(it, b.begin(), b.end());
  for (int i = 0; i < n; i++)
    cout << a[i] << " \n"[i == n - 1];
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
