#include <bits/stdc++.h>

#define lin(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;
using ll = long long;

void solve() {
  int n, q;
  cin >> n >> q;

  vector<int> a(n + 1);
  lin(i, 1, n + 1) cin >> a[i];

  vector<vector<int>> win(n + 1);
  deque<int> dq;
  lin(i, 1, n + 1) dq.push_back(i);

  lin(i, 1, n + 1) {
    auto t1 = dq.front();
    dq.pop_front();
    auto t2 = dq.front();
    dq.pop_front();

    if (a[t1] > a[t2]) {
      win[t1].push_back(i);
      dq.push_front(t1);
      dq.push_back(t2);
    } else {
      win[t2].push_back(i);
      dq.push_front(t2);
      dq.push_back(t1);
    }
  }

  while (q--) {
    int i, k;
    cin >> i >> k;

    auto th = upper_bound(win[i].begin(), win[i].end(), k);
    int cnt = distance(win[i].begin(), th);

    if (a[i] == n && k > n)
      cnt += (k - n);

    cout << cnt << "\n";
  }
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
