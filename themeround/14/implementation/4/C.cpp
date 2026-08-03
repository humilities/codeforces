#include <bits/stdc++.h>

#define lin(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;
using ll = long long;

struct day {
  int val;
  int id;
};

bool comp(const day &a, const day &b) { return a.val > b.val; }

void solve() {
  int n;
  cin >> n;

  vector<day> a(n);
  vector<day> b(n);
  vector<day> c(n);

  lin(i, 0, n) {
    cin >> a[i].val;
    a[i].id = i;
  }
  lin(i, 0, n) {
    cin >> b[i].val;
    b[i].id = i;
  }
  lin(i, 0, n) {
    cin >> c[i].val;
    c[i].id = i;
  }

  sort(a.begin(), a.end(), comp);
  sort(b.begin(), b.end(), comp);
  sort(c.begin(), c.end(), comp);

  ll ans = 0;
  lin(i, 0, 3) {
    lin(j, 0, 3) {
      lin(k, 0, 3) {
        if (a[i].id != b[j].id && a[i].id != c[k].id && b[j].id != c[k].id) {
          ans = max(ans, (ll)(a[i].val + b[j].val + c[k].val));
        }
      }
    }
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
