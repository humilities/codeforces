#include <bits/stdc++.h>

using namespace std;

void solve() {
  int d, sum;
  cin >> d >> sum;

  vector<pair<int, int>> to;
  int lil = 0, rli = 0;

  for (int i = 0; i < d; i++) {
    int l, r;
    cin >> l >> r;

    to.push_back({l, r});

    lil += l;
    rli += r;
  }

  if (rli < sum || lil > sum) {
    cout << "NO" << endl;
    return;
  }

  int rem = sum - lil;
  vector<int> ans;
  for (int i = 0; i < d; i++) {
    int add = to[i].second - to[i].first;
    add = min(add, rem);

    ans.push_back(to[i].first + add);
    rem -= add;
  }

  cout << "YES" << endl;
  for (int i = 0; i < d; i++)
    cout << ans[i] << " \n"[i == d - 1];
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  solve();

  return 0;
}
