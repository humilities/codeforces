#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  int ans = 0;
  string str;
  cin >> n >> str;

  vector<int> cnt;
  for (int i = 0; i < n; i++)
    if (str[i] == '1')
      cnt.push_back(i);

  if (cnt.size() == 0) {
    cout << (n + 2) / 3 << endl;
    return;
  }
  ans += cnt.size();

  int f = cnt[0];
  ans += (f + 1) / 3;

  for (int i = 0; i < cnt.size() - 1; i++) {
    int num = cnt[i + 1] - cnt[i] - 1;

    ans += num / 3;
  }

  ans += (n - cnt[cnt.size() - 1]) / 3;

  cout << ans << endl;
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
