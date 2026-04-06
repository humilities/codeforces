// #include <bits/stdc++.h>
//
// using namespace std;
// using ll = long long;
//
// struct node {
//   ll k;
//   ll high;
//   ll de;
//
//   bool operator<(const node &other) const { return de < other.de; }
// };
//
// void solve() {
//   int n;
//   ll x;
//   cin >> n >> x;
//
//   vector<ll> k(n);
//   vector<ll> h(n);
//
//   ll sum = 0;
//   for (int i = 0; i < n; i++)
//     cin >> k[i] >> h[i], sum += k[i] * pow(h[i], 2);
//
//   priority_queue<node> p;
//   for (int i = 0; i < n; i++)
//     p.push({k[i], h[i], k[i] * (2 * h[i] - 1)});
//
//   int cnt = 0;
//   while (sum > x) {
//     node n = p.top();
//     p.pop();
//
//     sum -= n.de;
//     n.high--;
//
//     if (n.high)
//       p.push({n.k, n.high, n.k * (n.high * 2 - 1)});
//     cnt++;
//   }
//
//   cout << cnt << "\n";
// }
//
// int main() {
//   ios_base::sync_with_stdio(false);
//   cin.tie(NULL);
//
//   int t;
//   cin >> t;
//
//   while (t--)
//     solve();
//
//   return 0;
// }
//
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using i128 = __int128;

struct node {
  ll k, h;
};

ll n, x;
vector<node> tow;

pair<i128, ll> che(ll mid) {
  i128 sum = 0;
  ll att = 0;

  for (int i = 0; i < n; i++) {
    ll hp;

    if ((i128)tow[i].k * (2 * tow[i].h - 1) <= mid)
      hp = tow[i].h;
    else {
      hp = hp = (mid / tow[i].k + 1) / 2;
      hp = min(tow[i].h, max(0LL, hp));
    }

    sum += (i128)tow[i].k * hp * hp;
    att += (tow[i].h - hp);
  }

  return {sum, att};
}

void solve() {
  tow.clear();

  cin >> n >> x;
  tow.resize(n);

  i128 sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> tow[i].k >> tow[i].h;
    sum += (i128)tow[i].k * tow[i].h * tow[i].h;
  }

  if (sum <= (i128)x) {
    cout << 0 << "\n";
    return;
  }

  ll l = 0, best = 1;
  i128 r = 4e18;
  while (l <= r) {
    ll mid = l + (r - l) / 2;

    if (che(mid).first <= (i128)x) {
      best = mid;
      l = mid + 1;
    } else
      r = mid - 1;
  }

  auto ans = che(best);
  i128 s = ans.first;
  ll cnt = ans.second;

  if (best < 2e18) {
    ll re = (ll)((x - s) / (i128)(best + 1));
    cout << max(0LL, cnt - re) << "\n";
  } else {
    cout << cnt << "\n";
  }
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
