#include <iostream>
#include <map>

using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long
#define ull unsigned long long
const ll MOD = 1e9 + 7;

ll n,k;
const int LIM = 500005;
int a[LIM],b[LIM];

void solve() {
	cin >> n >> k;
	for (int i = 0 ; i < n ; ++i)
	{
		cin >> a[i];
	}
	for (int i = 0 ; i < n; ++i)
	{
		cin >> b[i];
	}
	int start_pos;
	for (int i = 0 ; i < n; ++i)
	{
		if (b[i]==a[0]) {start_pos = i; break;}
	}
	for (int i = 0, j = start_pos ; i < n ; i++,j++)
	{
		if (a[i]!=b[j%n])
		{
			cout << "NO" << "\n";
			return;
		}
	}
	if (((k==0 || (n==2 && k%2==0)) && a[0]!=b[0]) || ((k==1 || (n==2 && k%2==1)) && a[0]==b[0]))
		cout << "NO" << "\n";
	else
		cout << "YES" << "\n";
}

int main() {
	fast;
	freopen("./in/consecutive_cuts_chapter_1_input.txt", "r", stdin);
    // freopen("./in/in.inp", "r", stdin);
    freopen("./in/in.out", "w", stdout);
	int tc = 1;
	log(tc);
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		cout << "Case #" << t << ": ";
		solve();
	}
}