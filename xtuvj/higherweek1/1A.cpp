#include <bits/stdc++.h>
#include <queue>

using namespace std;

priority_queue<int, vector<int>, greater<int>> p;

void solve() {
  int n;
  cin >> n;

  vector<int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i], p.push(a[i]);

  int ans = 0;
  while (p.size() > 1) {
    int va1 = p.top();
    p.pop();
    int va2 = p.top();
    p.pop();

    ans += va1 + va2;
    p.push(va1 + va2);
  }

  cout << ans << endl;
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
