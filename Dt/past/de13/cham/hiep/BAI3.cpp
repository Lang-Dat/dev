#pragma GCC optimize("O3")

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long

int n, a[(int)1e5 + 5], dp[(int)1e5 + 5], t;
vector<int> uoc;

void adduoc()
{
	for (int i = 1; i * i <= dp[n]; ++i)
		if (dp[n] % i == 0)
		{
			if (i * i == dp[n]) uoc.push_back(i);
			else
			{
				uoc.push_back(i);
				uoc.push_back(dp[n] / i);
			}
		}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	freopen("BAI3.INP", "r", stdin);
	freopen("BAI3.OUT", "w", stdout);
	cin >> n;
	dp[0] = 0;
	for (int i = 1 ; i <= n ; ++i)
	{
		cin >> a[i];
		dp[i] = dp[i - 1] + a[i];
	}
	adduoc();
	sort(uoc.begin(), uoc.end());
	for (int i = 0 ; i < uoc.size() ; ++i)
	{
		t = 0;
		for (int j = 1 ; j <= n ; ++j)
			if (dp[j] % uoc[i] == 0) t++;
		if (t == dp[n] / uoc[i])
		{
			cout << t << "\n";
			cout << 1 << " ";
			for (int j = 1 ; j <= n ; ++j)
				if (dp[j] % uoc[i] == 0 && j < n)
					cout << j + 1 << " " ;
			return 0;
		}
	}
}