//1034A
/*
#include <vector>
#include <iostream>
#include <string>
#include <map>
#include <stack>
#include <cstring>
#include <queue>
#include <list>
#include <cstdio>
#include <set>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <iomanip>
#include <cctype>
#include <sstream>
#include <iterator>
#include <functional>
#include <stdlib.h>
#include <time.h>
#include <bitset>
#include <stdio.h>
using namespace std;
#define LL long long
const int inf = 0x3f3f3f3f;
const double eps = 1e-6;
LL gcd(LL a, LL b) { return b ? gcd(b, a % b) : a; }



int n;
int a[300005];
const int MAXN = 2e7;
int Mark[MAXN];
int prime[MAXN], cnt[MAXN];
int Prime() {
	int tot = 0;
	memset(Mark, 0, sizeof(Mark));
	Mark[0] = 1; Mark[1] = 1;
	for (int i = 2; i < MAXN; i++)
	{
		if (Mark[i] == 0) {
			prime[tot++] = i;
		}
		for (int j = 0; j < tot && prime[j] * i < MAXN; j++)
		{
			Mark[i * prime[j]] = 1;
			if (i % prime[j] == 0) {
				break;
			}
		}
	}
	return tot;
}
int main()
{
	memset(cnt, 0, sizeof(cnt));
	int tot = Prime();
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)scanf("%d", &a[i]);
	int gg = a[1];for (int i = 2; i <= n; i++)gg = gcd(gg, a[i]);
	for (int i = 1; i <= n; i++)
	{
		a[i] /= gg;
		for (int j = 0; prime[j] * prime[j] <= a[i]; j++)
		{
			if (a[i] % prime[j] == 0)cnt[prime[j]]++;
			while (a[i] % prime[j] == 0)
				a[i] /= prime[j];
		}
		if (a[i] != 1)cnt[a[i]]++;
	}
	int ans = n;
	for (int i = 2; i < MAXN; i++)
	{
		ans = min(ans, n - cnt[i]);
	}
	if (ans == n)printf("-1\n");
	else
		printf("%d\n", ans);

}*/



/*
#include<iostream>
#include<vector>

using namespace std;

int n;
int a[300005];
const int MAX = 2e7;
int mark[MAX];
int prime[MAX], cnt[MAX];

int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}

int dop() {
	int tot = 0;

	mark[0] = 1, mark[1] = 1;
	for (int i = 2;i < MAX;i++) {
		if (!mark[i]) {
			prime[tot++] = i;
		}

		for (int j = 0;j < tot&&prime[j]*i<MAX;j++) {
			mark[i * prime[j]] = 1;
			if (i % prime[j] == 0) {
				break;
			}
		}
	}

	return tot;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tot = dop();

	cin >> n;

	for (int i = 1;i <= n;i++) {
		cin >> a[i];
	}
	int gg = a[1];
	for (int i = 2;i <= n;i++) {
		gg = gcd(gg, a[i]);
	}

	for (int i = 1;i <= n;i++) {
		a[i] /= gg;

		for (int j = 0;prime[j] * prime[j] <= a[i];j++) {
			if (a[i] % prime[j] == 0) {
				cnt[prime[j]]++;
			}
			while (a[i] % prime[j] == 0) {
				a[i] /= prime[j];
			}
		}

		if (a[i] != 1) cnt[a[i]]++;
	}

	int ans = n;
	for (int i = 2;i < MAX;i++) {
		ans = min(ans, n - cnt[i]);
	}
	if (ans == n) cout << -1 << endl;

	else cout << ans << endl;
	return 0;
}*/