#include<iostream>
#include<algorithm>
#include<vector>
#include<math.h>
using namespace std;
#define ull unsigned long long

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
    freopen("./BAI4.INP", "r", stdin);
    freopen("./BAI4.OUT", "w", stdout);
    int n, a[(int)1e5+6], ind, ans = INT32_MAX; cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    int maxn = *max_element(a, a+n), minn = *min_element(a, a+n);
    vector<int> max_p, min_p;
    for (int i = 0; i < n; ++i)
    {
        if (a[i] == maxn) max_p.push_back(i+1);
        if (a[i] == minn) min_p.push_back(i+1);
    }
    for (int it : min_p)
    {
        ind = lower_bound(max_p.begin(), max_p.end(), it) - max_p.begin();
        if (ind + max_p.begin() != max_p.begin()) ans = min(ans, abs(it - max_p[ind - 1]) + 1);
        if (ind + max_p.begin() != max_p.end()) ans = min(ans, abs(it - max_p[ind]) + 1);
    }
    cout << ans;
}