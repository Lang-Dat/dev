#pragma GCC optimize("O3")
#include <iostream>
// #include <vector>
// #include <cstring>
// #include <algorithm>
// #include <iomanip>
// #include <math.h>
// #include <iomanip>
#include <map>
// #include <unordered_map>
// #include <set>
// #include <unordered_set>
// #include <stack>
using namespace std;

template < typename A, typename B > ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template < typename T_container, typename T = typename enable_if < !is_same<T_container, string>::value, typename T_container::value_type >::type > ostream & operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << '\n'; }
template<typename Head, typename... Tail>
void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

#define PI 3.14159265358979323846
#define ll long long
#define ld long double
#define all(x) x.begin(), x.end()
#define ms(x, a) memset(x, a, sizeof(x))
#define tr(it, a) for(auto &it : a)
#define fo(i,s,e) for(ll i = s; i <= e; i++)
#define sz(x) int((x).size())
#define multitest int t; cin >> t; while(t--)
#define fi first
#define se second
#define nl '\n'

const ll MOD = 1e9 + 7;
const int INF = 1e9;
const int LIM = 1e6 + 5;

int n, time = 0, dif;
pair<int, int> p[LIM];
map<int, int> mp;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("CHENHLECH.INP", "r", stdin);
	freopen("CHENHLECH.OUT", "w", stdout);
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> p[i].fi >> p[i].se;
		mp[abs(p[i].fi - p[i].se)]++;
	}
	tr(pair, mp)
	{
		if (pair.se > time)
		{
			time = pair.se;
			dif = pair.fi;
		}
	}
	cout << dif << nl;
	for (int i = 0; i < n; ++i)
		if (abs(p[i].fi - p[i].se) == dif)
			cout << p[i].fi << ' ' << p[i].se << nl;
}