#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;

  vector<int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];

  map<int, int> ma;
  for (int i = 0; i < n; i++)
    ma[a[i]]++;

  vector<int> fre;
  for (auto [val, cnt] : ma)
    fre.push_back(cnt);

  sort(fre.begin(), fre.end());
  int ans = 0;

  // for (int i = 0; i < fre.size(); i++)
  // cout << "fre[i]=" << " " << fre[i] << "\n";

  for (int i = 0; i < fre.size(); i++) {
    int val = fre[i];
    int num = (fre.size() - i) * val;

    ans = max(ans, num);
  }

  cout << n - ans << "\n";
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
