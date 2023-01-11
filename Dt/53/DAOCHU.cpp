#pragma GCC optimize("O3")
#include <iostream>
// #include <vector>
// #include <cstring>
// #include <algorithm>
// #include <iomanip>
// #include <math.h>
// #include <iomanip>
// #include <map>
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

int n;
string a[2];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("DAOCHU.INP", "r", stdin);
	freopen("DAOCHU.OUT", "w", stdout);
	cin >> n;
	while (n--)
	{
		cin >> a[0] >> a[1];
		cout << a[1] << ' ' << a[0] << nl;
	}
}