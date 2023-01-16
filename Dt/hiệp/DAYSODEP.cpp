#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

#define ms(x, a) memset(x, a, sizeof(x))

#define ll long long
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const int LIM = 1e6 + 5;

int n, uoc[LIM], tmp, ans = -INF;
vector<int> v;

void sanguoc()
{
	ms(uoc, 0);
	for (int i = 1; i <= LIM; ++i)
		for (int j = 1; i * j <= LIM; ++j)
			uoc[i * j]++;
}

int lengthOfLIS(vector<int>& nums) {
	vector<int> ans;
	for (int i = 0; i < nums.size(); i++) {
		auto it = lower_bound(ans.begin(), ans.end(), nums[i]);
		if (it == ans.end()) ans.push_back(nums[i]);
		else *it = nums[i];
	}
	return ans.size();
}

void solve()
{
	cin >> n; v.resize(n);
	sanguoc();
	for (int i = 0; i < n; ++i)
	{
		cin >> tmp;
		v[i] = uoc[tmp];
	}
	cout << lengthOfLIS(v);
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("DAYSODEP.INP", "r", stdin);
	// freopen("../14/Testde14/DAYSODEP/Test003/DAYSODEP.INP", "r", stdin);
	freopen("DAYSODEP.OUT", "w", stdout);
	int tc = 1;
	// cin >> tc;
	for (int t = 1; t <= tc; t++) {
		// cout << "Case #" << t << ": ";
		solve();
	}
	return 0;
}