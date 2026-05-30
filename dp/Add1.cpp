#include<iostream>
#include<vector>

using namespace std;

const int Mod=1e9+7;
const int M = 200005;

int dp[10][M];

void solve() {
	int n, m;
	int ans = 0;
	cin >> n >> m;

	vector<int> a;

	while (n) {
		a.push_back(n % 10);
		n /= 10;
	}

	for (auto& assign : a) {
		ans = (ans + dp[assign][m]) % Mod;
	}

	cout << ans << endl;

}

int main() {
	int t;
	cin >> t;

	for (int i = 0;i < 10;i++) {
		dp[i][0] = 1;
	}

	for (int k = 1;k < M;k++) {
		for (int i = 9;i >= 0;i--) {

			if (i + 1 < 10) {
				dp[i][k] = dp[i + 1][k - 1]%Mod;
			}
			else {
				dp[i][k] = (dp[1][k - 1] + dp[0][k - 1]) % Mod;
			}

		}
	}

	while (t--) {
		solve();
	}

	return 0;
}