#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct Part {
  int low, high, id;
};

struct Actor {
  int low, high, lim, id;
};

bool compp(const Part &x, const Part &y) { return x.low < y.low; }

bool compa(const Actor &x, const Actor &y) { return x.low < y.low; }

void solve() {
  int n, m;
  cin >> n;

  vector<Part> ap(n);
  for (int i = 0; i < n; i++) {
    cin >> ap[i].low >> ap[i].high;
    ap[i].id = i;
  }

  cin >> m;
  vector<Actor> aa(m);
  for (int i = 0; i < m; i++) {
    cin >> aa[i].low >> aa[i].high >> aa[i].lim;
    aa[i].id = i + 1;
  }

  sort(ap.begin(), ap.end(), compp);
  sort(aa.begin(), aa.end(), compa);

  set<pair<int, int>> p;
  vector<int> res(n);
  int act = 0;

  for (int i = 0; i < n; i++) {
    while (act < m && aa[act].low <= ap[i].low) {
      p.insert({aa[act].high, act});
      act++;
    }

    auto it = p.lower_bound({ap[i].high, -1});

    if (it == p.end()) {
      cout << "NO" << endl;
      return;
    }

    int idx = it->second;
    res[ap[i].id] = aa[idx].id;

    aa[idx].lim--;
    if (aa[idx].lim == 0) {
      p.erase(it);
    }
  }

  cout << "YES" << endl;
  for (int i = 0; i < n; i++) {
    cout << res[i] << " \n"[i == n - 1];
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  solve();
  return 0;
}
