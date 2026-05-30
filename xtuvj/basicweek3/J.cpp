#include <bits/stdc++.h>

#define lin(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;
using ll = long long;

void solve() {
  int n, k;
  cin >> n >> k;

  vector<int> a(n);
  map<int, int> ma;
  lin(i, 0, n) cin >> a[i], ma[a[i]]++;

  vector<int> b;
  for (auto const &[val, seq] : ma)
    if (seq >= k)
      b.push_back(val); //, cout << val << " ";

  // cout << "\n";

  if (b.empty()) {
    cout << "-1" << "\n";
    return;
  }

  int l = b[0], r = b[0];
  int curl = b[0];
  int ans = -1;

  for (int i = 1; i < b.size(); i++) {
    if (b[i] == b[i - 1] + 1) {
      if (b[i] - curl > ans) {
        ans = b[i] - curl;
        l = curl;
        r = b[i];

        // cout << b[i] << "\n";
      }
    } else
      curl = b[i];
  }

  if (ans == -1) {
    cout << b[0] << " " << b[0] << "\n";
    return;
  }
  cout << l << " " << r << "\n";
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
