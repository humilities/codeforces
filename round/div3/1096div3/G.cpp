// #include <iostream>
// #include <vector>
// #include <algorithm>
//
// using namespace std;
// using ll = long long;
//
// // 树状数组模板
// struct FenwickTree {
//     int size;
//     vector<int> tree;
//     FenwickTree(int n) : size(n), tree(n + 1, 0) {}
//     void add(int i, int val) {
//         for (; i <= size; i += i & -i) tree[i] += val;
//     }
//     int query(int i) {
//         int s = 0;
//         for (; i > 0; i -= i & -i) s += tree[i];
//         return s;
//     }
// };
//
// void solve() {
//     int n;
//     cin >> n;
//     vector<ll> a(n + 1);
//     vector<ll> pref(n + 1, 0);
//     vector<ll> coords;
//     coords.push_back(0); // 包含 pref[0]
//
//     for (int i = 1; i <= n; ++i) {
//         cin >> a[i];
//         // 计算交替前缀和: a[1] - a[2] + a[3]...
//         if (i % 2 != 0) pref[i] = pref[i - 1] + a[i];
//         else pref[i] = pref[i - 1] - a[i];
//         coords.push_back(pref[i]);
//     }
//
//     // 离散化坐标
//     sort(coords.begin(), coords.end());
//     coords.erase(unique(coords.begin(), coords.end()), coords.end());
//     auto get_id = [&](ll x) {
//         return lower_bound(coords.begin(), coords.end(), x) - coords.begin()
//         + 1;
//     };
//
//     int m = coords.size();
//     FenwickTree ft_even(m), ft_odd(m); // 分别存储 pref[偶数下标] 和
//     pref[奇数下标]
//
//     ll ans = 0;
//     int count_odd = 0;
//
//     // 初始状态: pref[0] 属于偶数下标集合 (l-1 = 0 是偶数)
//     ft_even.add(get_id(0), 1);
//
//     for (int r = 1; r <= n; ++r) {
//         int cur_id = get_id(pref[r]);
//         if (r % 2 != 0) {
//             // r 是奇数，寻找满足 pref[r] > pref[l-1] 的偶数下标 l-1
//             ans += ft_even.query(cur_id - 1);
//             ft_odd.add(cur_id, 1);
//             count_odd++;
//         } else {
//             // r 是偶数，寻找满足 pref[r] < pref[l-1] 的奇数下标 l-1
//             // 即: 总奇数下标数 - 小于等于 pref[r] 的数量
//             ans += count_odd - ft_odd.query(cur_id);
//             ft_even.add(cur_id, 1);
//         }
//     }
//
//     cout << ans << "\n";
// }
//
// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//
//     int t;
//     cin >> t;
//     while (t--) {
//         solve();
//     }
//     return 0;
// }

#include <bits/stdc++.h>

#define lin(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;
using ll = long long;

struct wick {
  int size;
  vector<int> tree;
  wick(int n) : size(n), tree(n + 1, 0) {}

  void add(int i, int val) {
    for (; i <= size; i += i & -i)
      tree[i] += val;
  }

  int que(int i) {
    int ans = 0;
    for (; i; i -= i & -i)
      ans += tree[i];
    return ans;
  }
};

void solve() {
  int n;
  cin >> n;
  vector<ll> a(n + 1);
  vector<ll> pref(n + 1, 0);
  vector<ll> cor;
  cor.push_back(0);

  lin(i, 1, n + 1) {
    cin >> a[i];
    if (i & 1)
      pref[i] = pref[i - 1] + a[i];
    else
      pref[i] = pref[i - 1] - a[i];
    cor.push_back(pref[i]);
  }

  sort(cor.begin(), cor.end());
  cor.erase(unique(cor.begin(), cor.end()), cor.end());
  auto get_id = [&](ll x) {
    return lower_bound(cor.begin(), cor.end(), x) - cor.begin() + 1;
  };

  int m = cor.size();
  wick even(m), odd(m);

  ll ans = 0;
  int cnt = 0;

  even.add(get_id(0), 1);
  for (int i = 1; i <= n; i++) {
    int cur_id = get_id(pref[i]);

    if (i & 1) {
      ans += even.que(cur_id - 1);
      odd.add(cur_id, 1);
      cnt++;
    } else {
      ans += cnt - odd.que(cur_id);
      even.add(cur_id, 1);
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
