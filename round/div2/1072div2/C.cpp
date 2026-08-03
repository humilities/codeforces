#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n, k;
  cin >> n >> k;

  if (n == k) {
    cout << 0 << endl;
    return;
  }

  queue<pair<int, int>> q;
  q.push({n, 0});

  set<int> vis;
  vis.insert(n);

  while (!q.empty()) {
    auto [curr, time] = q.front();
    q.pop();

    if (curr < k)
      continue;

    int a = curr / 2;
    int b = (curr + 1) / 2;

    if (a == k || b == k) {
      cout << time + 1 << endl;
      return;
    }

    if (a > k && vis.find(a) == vis.end()) {
      q.push({a, time + 1});
      vis.insert(a);
    }

    if (b > k && vis.find(b) == vis.end()) {
      q.push({b, time + 1});
      vis.insert(b);
    }
  }

  cout << -1 << endl;
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
