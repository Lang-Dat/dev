#include <iostream>
#include <map>

using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define endl "\n"
#define ll long long
const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

const int LIM = 500005;
int A[LIM], B[2 * LIM], LPS[LIM];
int n, k, tmp;

void computeLPS() {
	int len = 0;
	LPS[0] = 0;
	int i = 1;
	while (i < n)
	{
		if (A[i] == A[len]) {
			len++;
			LPS[i] = len;
			i++;
		}
		else if (len == 0) {
			LPS[i] = 0;
			i++;
		}
		else if (len != 0) {
			len = LPS[len - 1];
		}
	}
}
bool KMP() {
	computeLPS();
	int i = 0, j = 0;
	while ((2 * n - i) >= (n - j))
	{
		if (A[j] == B[i]) {
			i++;
			j++;
		}
		if (j == n) return true;
		else if (i < 2 * n && A[j] != B[i]) {
			if (j != 0)
				j = LPS[j - 1];
			else
				i++;
		}
	}
	return false;
}

void solve() {
	cin >> n >> k;
	for (int i = 0 ; i < n; ++i)
		cin >> A[i];
	for (int i = 0 ; i < n ; ++i)
	{
		cin >> B[i];
		B[i + n] = B[i];
	}
	if (!KMP()) {cout << "NO" << "\n"; return;}
	if (((k == 0 || (n == 2 && k % 2 == 0)) && A[0] != B[0]) ||
	    ((k == 1 || (n == 2 && k % 2 == 1)) && A[0] == B[0]))
		cout << "NO" << "\n";
	else
		cout << "YES" << "\n";
}

int main() {
	fast;
	freopen("./in/consecutive_cuts_chapter_2_input.txt", "r", stdin);
    // freopen("./in/in.inp", "r", stdin);
    freopen("./in/H.out", "w", stdout);
	int tc = 1;
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		cout << "Case #" << t << ": ";
		solve();
		// cout << 1;
	}
}


