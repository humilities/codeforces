#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;

  int mn = 0;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    mn = max(mn, a[i]);
  }

  sort(a.begin(), a.end());

  vector<int> uni;
  vector<int> dup;
  bool ski = false;

  for (int i = 0; i < n; i++) {
    if (a[i] == mn && !ski) {
      ski = true;
      continue;
    }

    if (!uni.empty() && uni.back() == a[i])
      dup.push_back(a[i]);
    else
      uni.push_back(a[i]);
  }

  vector<int> re;
  re.reserve(n);

  re.push_back(mn);
  for (int val : uni)
    re.push_back(val);
  for (int val : dup)
    re.push_back(val);

  ll ans = 0;
  int cuma = 0, cume = 0;

  vector<bool> vis(n + 2, false);
  for (int i = 0; i < n; i++) {
    int val = re[i];

    cuma = max(cuma, val);
    if (val <= n + 1)
      vis[val] = true;

    while (cume <= n + 1 && vis[cume])
      cume++;

    ans += ((ll)cuma + cume);
  }

  cout << ans << "\n";
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
