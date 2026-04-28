// #include <bits/stdc++.h>

// using namespace std;

// typedef long long ll;

// void solve() {
//   int n, h, k;
//   ll cnt = 0;
//   int maxn = 0;
//   int idx=0;
//   cin >> n >> h >> k;

//   vector<ll> a(n);
//   for (int i = 0; i < n; i++) {
//     cin >> a[i];
//     cnt += a[i];
//     if (a[i] > maxn){
//       maxn = a[i];
//       idx=i;
//     }
//   }

//   //swap(a[0],a[idx]);

//   int div=(h-1)/cnt;
//   int rem=h-(div*cnt);

//   ll ans=div*(n+k);
//   ll cur=0;
//   ll minn=1e9;
//   int id=-1;

//   for(int i=0;i<n;i++)
//   {
//     cur+=a[i];

//     if(a[i]<minn) {minn=a[i];id=i;}
//     if(cur>=rem) break;
//   }

//   swap(a[id],a[idx]);

//   int mi=0;
//   for(int i=0;i<n;i++)
//   {
//     mi+=a[i];

//     if(mi>=rem){
//       cout<<ans+i+1<<endl;
//       break;
//     }
//   }
// }

// int main() {
//   ios_base::sync_with_stdio(false);
//   cin.tie(NULL);

//   int t;
//   cin >> t;

//   while (t--)
//     solve();

//   return 0;
// }

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

void solve() {
  ll n, h, k;
  if (!(cin >> n >> h >> k))
    return;

  vector<ll> a(n);
  ll sum_val = 0;
  for (ll &x : a) {
    cin >> x;
    sum_val += x;
  }

  ll num_mags = (h - 1) / sum_val;
  ll total_time = num_mags * (n + k);
  h -= num_mags * sum_val;

  if (h <= 0) {
    cout << total_time << "\n";
    return;
  }

  vector<ll> max_suf(n + 1, 0);
  for (int i = n - 1; i >= 0; i--) {
    max_suf[i] = max(max_suf[i + 1], a[i]);
  }

  ll cur_pre_sum = 0;
  ll min_pre = 2e9;

  for (int i = 0; i < n; i++) {
    cur_pre_sum += a[i];
    min_pre = min(min_pre, a[i]);

    ll swap_potential = cur_pre_sum - min_pre + max_suf[i + 1];

    if (h <= cur_pre_sum || h <= swap_potential) {
      cout << total_time + i + 1 << "\n";
      return;
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--)
    solve();
  return 0;
}
