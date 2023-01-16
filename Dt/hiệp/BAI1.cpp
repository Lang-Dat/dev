#pragma GCC optimize("O3")
#include <iostream>
// #include <vector>
// #include <cstring>
// #include <algorithm>
#include <iomanip>
#include <math.h>
// #include <map>
// #include <set>
using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()
#define ms(x, a) memset(x, a, sizeof(x))
#define each(it, a) for(auto &it : a)
#define el '\n'

void dbg_out() { cerr << '\n'; }
template<typename Head, typename... Tail>
void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const int LIM = 1e6 + 5;

long double a, alpha, h, ans;
const double PI = 3.14159265359;

void convert()
{
	alpha = alpha * PI / 180;
}

void solve()
{
	cin >> a >> alpha >> h;
	convert();
	ans = tan(alpha) * a + h;
	// cout << setprecision(3) << fixed << ans;
	std::cout << fixed << setprecision(3) << ans ;
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("BAI1.INP", "r", stdin);
	freopen("BAI1.OUT", "w", stdout);
	int t = 1;
	// cin >> t;
	while (t--)
		solve();
}