#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n;
  string s;
  cin >> n >> s;

  vector<int> pre(n, 0);
  int sum = 0;
  for (int i = 0; i < n; i++) {
    sum += (s[i] - '0');
    pre[i] = sum;
  }

  string ans = "";
  int car = 0;
  for (int i = n - 1; i >= 0; i--) {
    int num = pre[i] + car;
    ans.push_back((num % 10) + '0');

    car = num / 10;
  }

  while (car) {
    ans.push_back((car % 10) + '0');
    car /= 10;
  }

  reverse(ans.begin(), ans.end());

  int sta = 0;
  while (sta < (int)ans.size() - 1 && ans[sta] == '0')
    sta++;

  cout << ans.substr(sta) << "\n";
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
