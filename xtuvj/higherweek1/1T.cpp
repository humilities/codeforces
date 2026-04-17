#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int ma = 300005;
int l[ma], r[ma];
bool vis[ma];
int val[ma];

struct node {
  ll v;
  int id;

  bool operator<(const node &b) const { return v < b.v; }
};

void solve() {
  int n, k;
  cin >> n >> k;

  priority_queue<node> q;
  for (int i = 1; i <= n; i++) {
    cin >> val[i];
    l[i] = i - 1;
    r[i] = i + 1;
    q.push({val[i], i});
  }

  r[0] = 1, l[n + 1] = n;
  val[0] = val[n + 1] = -1e9;

  ll ans = 0;
  while (k--) {
    while (!q.empty() && vis[q.top().id])
      q.pop();

    node cur = q.top();
    q.pop();

    if (cur.v <= 0)
      break;

    ans += cur.v;
    int i = cur.id;
    int left = l[i], right = r[i];

    val[i] = val[left] + val[right] - val[i];
    vis[left] = true, vis[right] = true;

    l[i] = l[left];
    r[l[i]] = i;
    r[i] = r[right];
    l[r[i]] = i;

    q.push({val[i], i});
  }

  cout << ans << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  // int t;
  // cin >> t;

  // while (t--)
  solve();

  return 0;
}
