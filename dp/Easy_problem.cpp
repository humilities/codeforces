//1096D

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll INF64 = 1e18;
const int N = 1e5 + 7;

ll dp[N][5];

int n;
int num[N];

const string h = "hard";

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	string str;
	cin >> str;

	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 5; j++) {
			dp[i][j] = INF64;
		}
	}

	dp[0][0] = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 4; j++) {
			int next = j+(str[i] == h[j]);

			dp[i + 1][next] = min(dp[i + 1][next], dp[i][j]);
			dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]+num[i]);
		}
	}

	ll ans = *min_element(dp[n], dp[n] + 4);

	cout << ans << endl;
	return 0;
}
