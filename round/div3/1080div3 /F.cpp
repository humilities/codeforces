#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct Func {
  ll a, b, c;
};

bool comp(Func f, Func g) {
  if (f.a > g.a)
    return false;
  else if (f.a == g.a)
    return f.b == g.b && f.c < g.c;
  else {
    Func k{g.a - f.a, g.b - f.b, g.c - f.c};
    return k.b * k.b - 4 * k.a * k.c < 0;
  }
}

void solve() {
  int n;
  cin >> n;

  vector<Func> a(n);
  for (Func &F : a)
    cin >> F.a >> F.b >> F.c;

  vector<vector<int>> adj1(n), adj2(n);
  vector<int> id1(n), id2(n), dp1(n, 1), dp2(n, 1);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (comp(a[i], a[j])) {
        adj1[i].push_back(j);
        id1[j]++;
        adj2[j].push_back(i);
        id2[i]++;
      }
    }
  }

  queue<int> q;
  for (int i = 0; i < n; i++)
    if (id1[i] == 0)
      q.push(i);

  while (!q.empty()) {
    int cur = q.front();
    q.pop();
    for (int i : adj1[cur]) {
      id1[i]--;
      dp1[i] = max(dp1[i], dp1[cur] + 1);

      if (id1[i] == 0)
        q.push(i);
    }
  }

  for (int i = 0; i < n; i++)
    if (id2[i] == 0)
      q.push(i);
  while (!q.empty()) {
    int cur = q.front();
    q.pop();
    for (int i : adj2[cur]) {
      id2[i]--;
      dp2[i] = max(dp2[i], dp2[cur] + 1);

      if (id2[i] == 0)
        q.push(i);
    }
  }

  for (int i = 0; i < n; i++) {
    cout << dp1[i] + dp2[i] - 1 << " \n"[i + 1 == n];
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
