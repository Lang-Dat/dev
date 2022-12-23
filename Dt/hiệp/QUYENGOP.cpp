#include<iostream>
using namespace std;
#define ull unsigned long long

ull tongbp(ull n)
{
	ull sum = 0;
	for (int i = 1; i * i <= n; ++i)
		sum += i*i;
	return sum;
}

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	ull n; cin >> n;

	ull sum = n * (n + 1) / 2;
	db(tongbp(n), sum)
	cout << sum - tongbp(n);
}