#include <iostream>
using namespace std;

const int LIM = 1e6 + 5;

int n, a[LIM], total = 0;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	#ifndef ONLINE_JUDGE
	freopen("./latxu.INP", "r", stdin);
	freopen("./latxu.OUT", "w", stdout);
	#endif

	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	for (int i = 1; i <= n; ++i)
		if (i % 2 == 0 && a[i] != a[i - 1])
			for (int j = i - 1; j >= 1; --j)
			{
				if (a[j] != a[i]) a[j] = a[i];
				else break;
			}
	for (int i = 1; i <= n; ++i)
		total += a[i] == 0;
	cout << total;
}