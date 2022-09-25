#include <iostream>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long

ll luythua(ll a, ll b)
{
	ll m = 1;
	while(b--)
		m*=a;
	return m;
}

int main()
{
	freopen("LUYTHUA.INP", "r", stdin);
	freopen("LUYTHUA.OUT", "w", stdout);
	fast;
	ll a,n,d;
	cin >> a >> n >> d;
	cout << (luythua(a,(n+1)*d)-1) / ((luythua(a,d)-1)); 
}