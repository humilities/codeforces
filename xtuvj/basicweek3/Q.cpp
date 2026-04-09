#include <bits/stdc++.h>

#define lin(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;
using ll = long long;

vector<ll> ans;
vector<ll> a;
map<ll, ll> ma;
int n = 0;

bool dfs(ll i) {
  ans.push_back(i);
  ma[i]--;

  if (ans.size() == n)
    return true;

  if (ma[i * 2])
    if (dfs(i * 2))
      return true;

  if (i % 3 == 0 && ma[i / 3])
    if (dfs(i / 3))
      return true;

  ma[i]++;
  ans.pop_back();

  return false;
}

void solve() {
  cin >> n;

  a.resize(n);
  lin(i, 0, n) cin >> a[i], ma[a[i]]++;

  lin(i, 0, n) {
    ans.clear();
    if (dfs(a[i]))
      break;
  }

  lin(i, 0, ans.size()) cout << ans[i] << " \n"[i == ans.size() - 1];
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
