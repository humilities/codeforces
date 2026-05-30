#include <bits/stdc++.h>

#define lin(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;

  ll sum = 0;
  vector<int> a(n);
  lin(i, 0, n) cin >> a[i], sum += a[i];

  priority_queue<ll> q;
  q.push(sum);

  multiset<ll> m;
  lin(i, 0, n) m.insert(a[i]);

  while (!q.empty()) {
    auto cur = q.top();
    q.pop();

    if (m.find(cur) != m.end()) {
      m.erase(m.find(cur));
    } else if (m.find(cur) == m.end() && cur != 1) {
      ll l = (cur + 1) / 2;
      ll r = (cur) / 2;

      q.push(l);
      q.push(r);
    } else {
      cout << "NO" << "\n";
      return;
    }

    if (q.size() > m.size()) {
      cout << "NO" << "\n";
      return;
    }
  }

  if (m.size() == 0)
    cout << "YES" << "\n";
  else
    cout << "NO" << "\n";
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
