#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct node {
  ll k;
  ll high;
  ll de;

  bool operator<(const node &other) const { return de < other.de; }
};

void solve() {
  int n;
  ll x;
  cin >> n >> x;

  vector<ll> k(n);
  vector<ll> h(n);

  ll sum = 0;
  for (int i = 0; i < n; i++)
    cin >> k[i] >> h[i], sum += k[i] * pow(h[i], 2);

  priority_queue<node> p;
  for (int i = 0; i < n; i++)
    p.push({k[i], h[i], k[i] * (2 * h[i] - 1)});

  int cnt = 0;
  while (sum > x) {
    node n = p.top();
    p.pop();

    sum -= n.de;
    n.high--;

    if (n.high)
      p.push({n.k, n.high, n.k * (n.high * 2 - 1)});
    cnt++;
  }

  cout << cnt << "\n";
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
