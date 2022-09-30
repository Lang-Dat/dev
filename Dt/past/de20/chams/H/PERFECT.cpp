#pragma GCC optimize("O3")

#include <iostream>
using namespace std;

#define ll long long
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
int n, x, cnt = 0;

int uoc(int a)
{
	int ans = 0;
	for (int i = 1 ; i * i <= a ; ++i)
	{
		if (a % i == 0)
		{
			if (i * i == a)
				ans += i;
			else ans = ans + i + a / i;
		}
	}
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	freopen("PERFECT.INP", "r", stdin);
	freopen("PERFECT.OUT", "w", stdout);
	cin >> n;
	while (n--)
	{
		cin >> x;
		if (uoc(x) - x == x)
			cnt++;
	}
	cout << cnt;
}