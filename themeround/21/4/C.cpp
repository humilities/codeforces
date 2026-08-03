#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int get(const string &s, int sta, int end) {
  int ans = 0;
  for (int i = sta; i <= end; i++) {
    ans += (s[i] - '0');
  }

  return ans;
}

void solve() {
  int n;
  cin >> n;

  vector<string> in(n);
  for (int i = 0; i < n; i++)
    cin >> in[i];

  int ma[6][46] = {0};
  for (int i = 0; i < n; i++) {
    int sum = get(in[i], 0, in[i].length() - 1);
    ma[in[i].length()][sum]++;
  }

  ll ans = 0;
  for (int i = 0; i < n; i++) {
    int len1 = in[i].length();

    for (int j = 1; j <= len1; j++) {
      if ((j + len1) % 2 != 0)
        continue;
      int mid = (j + len1) / 2;

      int nee = get(in[i], 0, mid - 1) - get(in[i], mid, len1 - 1);
      ans += ma[j][nee];
    }

    for (int j = 1; j < len1; j++) {
      if ((j + len1) % 2 != 0)
        continue;
      int mid = (j + len1) / 2;

      int nee = get(in[i], len1 - mid, in[i].length() - 1) -
                get(in[i], 0, len1 - mid - 1);
      ans += ma[j][nee];
    }
  }

  cout << ans << "\n";
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
