#include<bits/stdc++.h>

using namespace std;
const int al = 26;
int cnts[al], cntt[al];
string s;

bool can(char ch, int k, const vector<vector<int>>&needsuf, int rem[], int slen) {
	int idx = ch - 'a';

	if (ch = s[k]) {
		if (rem[idx] - 1 < needsuf[k + 1][idx]) return false;
		for (int c = 0; c < al; c++) {
			int need = needsuf[k + 1][c];
			int have = (c == idx) ? (rem[c] - 1) : rem[c];
			if (have < need) return false;
		}
	}
	else {
		if (rem[idx] - 1 < needsuf[k][idx]) {
			return false;
		}
		for (int c = 0; c < al; c++) {
			int need = needsuf[k][c];
			int have = (c == idx) ? (rem[c] - 1) : rem[c];
			if (have < need) return false;
		}
	}
	return true;
}

void solve() {
	string t;
	cin >> s >> t;

	int n = s.size(), m = t.size();
	memset(cnts, 0, sizeof(cnts));
	memset(cntt, 0, sizeof(cntt));

	for (char c : s) cnts[c - 'a']++;
	for (char c : t) cntt[c - 'a']++;

	for (int i = 0; i < al; i++) {
		if (cntt[i] < cnts[i]) {
			cout << "Impossible" << endl;
			return;
		}
	}

	int slen = s.size();
	vector<vector<int>> needsuf(slen + 1, vector<int>(al, 0));

	for (int i = slen - 1; i >= 0; i--) {
		for (int c = 0; c < al; c++) {
			needsuf[i][c] = needsuf[i + 1][c];
		}
		needsuf[i][s[i] - 'a']++;
	}

	int rem[al];
	for (int i = 0; i < al; i++) {
		rem[i] = cntt[i];
	}

	int k = 0;
	string ans;
	for (int i = 0; i < m; i++) {
		for (char ch = 'a'; ch <= 'z'; ch++) {
			int idx = ch - 'a';

			if (rem[idx] == 0) continue;
			if (can(ch, k, needsuf, rem, slen)) {
				ans.push_back(ch);
				rem[idx]--;

				if (k < slen && ch == s[k]) k++;
				break;
			}
		}
	}

	cout << ans << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;

	while (t--) {
		solve();
	}

	return 0;
}