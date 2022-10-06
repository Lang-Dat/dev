#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long

int BNS(int k, pair<int, int> arr[], int start, int end)
{
	int L = start, R = end, M, pos = 0;
	while (L <= R)
	{
		M = (L + R) / 2;
		if (arr[M].first <= k)
		{
			pos = M;
			L = M + 1;
		}
		else
			R = M - 1;
	}
	return pos;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	freopen("BAI5.INP", "r", stdin);
	freopen("BAI5.OUT", "w", stdout);
	int n, k, best = 0; cin >> n >> k;
	pair<int, int> a[n + 1];
	int dp[n + 1];
	dp[0] = 0;
	a[0].first = a[0].second;
	for (int i = 1; i <= n; ++i)
		cin >> a[i].second >> a[i].first;
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; ++i)
		dp[i] = dp[i - 1] + a[i].second;
	int in_range = k * 2;
	for (int i = 1; i <= n; ++i)
		best = max(best, dp[BNS(in_range + a[i].first, a, i, n)] - dp[i - 1]);
	cout << best;
}