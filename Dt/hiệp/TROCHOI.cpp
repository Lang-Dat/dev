#pragma GCC optimize("O3")
#include <iostream>
// #include <vector>
// #include <cstring>
#include <algorithm>
// #include <iomanip>
// #include <math.h>
#include <unordered_map>
// #include <set>
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
#define sz(x) int((x).size())
#define fi first
#define se second
#define nl '\n'

const ll MOD = 1e9 + 7;
const int INF = 1e9;
const int LIM = 1e6 + 5;

int n, res;
string a[LIM];
unordered_map<string, int> mp;

int number(string s)
{
	res = 0;
	tr(ch, s) res += (ch >= '0' && ch <= '9');
	return res;
}

bool cmp(string &a, string &b)
{
	if (number(a) != number(b))
		return number(a) < number(b);
	else return mp[a] < mp[b];
}

void run_case()
{
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
		mp[a[i]] = i;
	}
	sort(a, a + n, cmp);
	for (int i = 0; i < n; ++i)
		cout << a[i] << nl;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("TROCHOI.INP", "r", stdin);
	freopen("TROCHOI.OUT", "w", stdout);
	int tc = 1;
	// cin >> tc;
	for (int t = 1; t <= tc; t++)
	{
		// cout << "Case #" << t << ": ";
		run_case();
	}
}