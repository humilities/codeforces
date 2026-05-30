#include <bits/stdc++.h>

#define lin(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;
using ll = long long;

const int mn = 100005;

ll get(vector<int> &a) {
  sort(a.begin(), a.end());

  ll ret = 0;
  lin(i, 0, a.size()) ret += 1LL * a[i] * (ll)(2 * i - (a.size() - 1));

  return ret;
}

void solve() {
  int n, m;
  cin >> n >> m;

  vector<int> row[mn];
  vector<int> col[mn];

  lin(i, 0, n) {
    lin(j, 0, m) {
      int cl;
      cin >> cl;

      row[cl].push_back(i);
      col[cl].push_back(j);
    }
  }

  ll ans = 0;
  lin(i, 0, 100001) {
    ans += get(row[i]);
    ans += get(col[i]);
  }

  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  // int t;
  // cin >> t;
  //
  // while (t--)
  solve();

  return 0;
}
