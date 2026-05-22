// #include <bits/stdc++.h>
//
// #define lin(i, a, b) for (int i = (a); i < (b); i++)
// using namespace std;
// using ll = long long;
//
// void solve() {
//   int n, m;
//   cin >> n >> m;
//
//   vector<vector<int>> gra(n, vector<int>(m, 0));
//   for (int i = 0; i < n; i++) {
//     for (int j = 0; j < m; j++)
//       cin >> gra[i][j];
//   }
//
//   vector<pair<int, int>> ans(n);
//   for (int i = 0; i < n; i++) {
//     ans[i].second = i;
//     for (int j = 0; j < m; j++) {
//       if (j == 0)
//         continue;
//       else
//         ans[i].first += -1 * gra[i][j];
//     }
//   }
//
//   sort(ans.begin(), ans.end());
//   ll sum = 0;
//
//   int j = m;
//   for (int i = n - 1; i >= 0; i--) {
//     int idx = ans[i].second;
//     int cnt = m;
//
//     while (cnt--) {
//       sum += (gra[idx] * (ll)(i + 1) * (j));
//       j--;
//     }
//   }
//
//   cout << sum << "\n";
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

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct dar {
  ll sum;
  ll sco;
};

void solve() {
  int n, m;
  cin >> n >> m;

  vector<dar> ar(n);
  for (int i = 0; i < n; ++i) {
    ll s = 0;
    ll sc = 0;
    ll cur = 0;
    for (int j = 0; j < m; ++j) {
      ll val;
      cin >> val;
      s += val;
      cur += val;
      sc += cur;
    }
    ar[i] = {s, sc};
  }

  sort(ar.begin(), ar.end(),
       [](const dar &a, const dar &b) { return a.sum > b.sum; });

  ll tot = 0;
  ll sum = 0;
  for (int i = 0; i < n; ++i) {
    tot += ar[i].sco + sum * m;
    sum += ar[i].sum;
  }

  cout << tot << endl;
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
