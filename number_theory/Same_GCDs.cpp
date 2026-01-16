//1295D
/*
#include<iostream>
#include<vector>

using namespace std;
typedef long long ll;

void solve() {
	ll a, m;
	ll ans = 0;
	cin >> a >> m;

	vector<ll> yin;
	ll num=m;
	for (ll i = 2;i * i <= num;i++) {
		if (num % i == 0) {
			while (num % i == 0) num /= i;
			yin.push_back(i);
		}
	}
	if (num != 1) {
		yin.push_back(num);
	}

	if (yin.size() == 1) {
		cout << m - 1 << endl;
		return;
	}
	else {
		ll dis = m - 1 + a;
		for (int i = 0;i < yin.size();i++) {
			ll dis1 = dis / yin[i] - a / yin[i];

			ans +=dis - dis1;
		}
	}

	cout << ans << endl;
}

int main() {
	int t;
	cin >> t;

	while (t--) {
		solve();
	}

	return 0;
}
*/
