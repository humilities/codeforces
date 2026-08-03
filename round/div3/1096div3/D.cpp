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
//   int len = 2 * n;
//
//   vector<int> a(len + 1);
//   vector<vector<int>> pos(n);
//   {
//     lin(i, 1, len + 1) {
//       cin >> a[i];
//       if (a[i] < n)
//         pos[a[i]].push_back(i);
//     }
//   }
//
//   if (n == 0) {
//     cout << 0 << "\n";
//     return;
//   }
//
//   set<int> can;
//   can.insert(pos[0][0] + pos[0][1]);
//   can.insert(2 * pos[0][0]);
//   can.insert(2 * pos[0][1]);
//
//   int mn = 0;
//
//   for (int s : can) {
//     if (s < 2 || s > 2 * len)
//       continue;
//
//     int l, r;
//     if (s % 2 == 0) {
//       int mid = s / 2;
//       if (mid < 1 || mid > len)
//         continue;
//
//       l = r = mid;
//     } else {
//       int mid1 = s / 2;
//       int mid2 = mid1 + 1;
//
//       if (mid1 < 1 || mid2 > len || a[mid1] != a[mid2])
//         continue;
//       l = mid1;
//       r = mid2;
//     }
//
//     while (l > 1 && r < len && a[l - 1] == a[r + 1]) {
//       l--;
//       r++;
//     }
//
//     int curr = 0;
//     while (curr < n) {
//       bool found = false;
//       int p1 = pos[curr][0];
//       int p2 = pos[curr][1];
//
//       if (p1 >= l && p1 <= r && p2 >= l && p2 <= r && (p1 + p2 == s))
//         found = true;
//       else if (2 * p1 == s && p1 >= l && p1 <= r)
//         found = true;
//       else if (2 * p2 == s && p2 >= l && p2 <= r)
//         found = true;
//
//       if (found)
//         curr++;
//       else
//         break;
//     }
//     if (curr > mn)
//       mn = curr;
//   }
//
//   cout << mn << "\n";
// }
//
// int main() {
//   ios::sync_with_stdio(false);
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

#include <bits/stdc++.h>

#define lin(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;

  int len = 2 * n;
  vector<vector<int>> pos(n);
  vector<int> a(len + 1);
  lin(i, 1, len + 1) {
    cin >> a[i];
    pos[a[i]].push_back(i);
  }

  int p1 = pos[0][0];
  int p2 = pos[0][1];
  set<int> can;

  can.insert(p1 + p2);
  can.insert(2 * p1);
  can.insert(2 * p2);

  int mn = 0;
  for (auto s : can) {
    int l, r;

    if (!(s & 1))
      l = r = s / 2;
    else {
      int mid = s / 2;

      if (mid < 1 || mid + 1 > len || a[mid] != a[mid + 1])
        continue;

      l = mid;
      r = mid + 1;
    }

    while (l > 1 && r < len && a[l - 1] == a[r + 1])
      l--, r++;

    int cur = 0;
    while (cur < n) {
      bool found = false;
      int b1 = pos[cur][0];
      int b2 = pos[cur][1];

      if (b1 + b2 == s && b1 >= l && b1 <= r && b2 >= l && b2 <= r)
        found = true;
      else if (b1 * 2 == s && b1 >= l && b1 <= r)
        found = true;
      else if (b2 * 2 == s && b2 >= l && b2 <= r)
        found = true;
      else
        found = false;

      if (found)
        cur++;
      else
        break;
    }

    // cout << "cur=" << cur << "mn=" << mn << "\n";

    mn = max(mn, cur);

    // cout << l << " " << r << "\n";
  }

  cout << mn << "\n";
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
