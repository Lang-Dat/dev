#pragma GCC optimize("O2")

#include <iostream>
#include <set>
using namespace std;

#define ll long long
#define fast ios_base::sync_with_stdio(false);cin.tie(0);

int d, m, y, t;

set<int> thang31 = {1, 3, 5, 7, 9, 10, 12};
set<int> thang30 = {4, 6, 9, 11};

bool solve()
{
	if (d > 31 || m > 12) return false;
	if ((y % 4 == 0 && m == 2 && d > 29) || (y % 4 != 0 && m == 2 && d > 28))
		return false;
	if ((thang30.count(m) && d > 30) || (thang31.count(m) && d > 31))
		return false;
	return true;
}

int main()
{
	freopen("DATE.INP", "r", stdin);
	freopen("DATE.OUT", "w", stdout);
	fast;
	cin >> t;
	while (t--)
	{
		cin >> d >> m >> y;
		if (solve()) cout << "TRUE" << "\n";
		else cout << "FALSE" << "\n";
	}
}