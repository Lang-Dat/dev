#pragma GCC optimize("O3")

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
vector<pair<double, pair<int, int>>> v;
int cnt = 0;
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	// freopen("BAI3.INP", "r", stdin);
	// freopen("BAI3.OUT", "w", stdout);
	int n; cin >> n;
	v.push_back(make_pair((double)0 / 1, make_pair(0, 1)));
	for (int i = 1 ; i < n; ++i)
		for (int j = i ; j <= n ; ++j)
			v.push_back(make_pair((double)i / j, make_pair(i, j)));
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size() - 1 ; ++i)
	{
		cnt++;
		cout << v[i].second.first << "/" << v[i].second.second << " ";
		while (v[i + 1].first == v[i].first)
			i++;
	}
	cout << "\n" << cnt;
}