#include <bits/stdc++.h>

#define lin(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;

  unordered_map<int, int> ma;
  lin(i, 0, n) {
    int x;
    cin >> x;
    ma[x]++;
  }

  vector<int> fre;
  for (auto const &[kind, val] : ma)
    fre.push_back(val);

  sort(fre.begin(), fre.end(), greater<int>());

  ll ans = 0;
  int cur = fre[0];

  for (int f : fre) {
    int re = min(f, cur);

    if (re > 0) {
      ans += re;
      cur = re - 1;
    } else
      break;
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
