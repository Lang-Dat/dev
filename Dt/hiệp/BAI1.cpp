#pragma GCC optimize("O3")

#include <iostream>
using namespace std;

#define ll long long
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

int uoc(int n)
{
	int ans = 0;
	for (int i = 1; i * i <= n; ++i)
	{
		if (n % i == 0)
		{
			if (i * i == n) ans += i;
			else ans = ans + i + n / i;
		}
	}
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	freopen("BAI1.INP", "r", stdin);
	freopen("BAI1.OUT", "w", stdout);
	int n, tmp, cnt = 0; cin >> n;
	while (n--)
	{
		cin >> tmp;
		if (uoc(tmp) - tmp == tmp) cnt++;
	}
	cout << cnt;
}