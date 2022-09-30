#pragma GCC optimize("O2")
#include <math.h>
#include <iostream>

using std::pow;
#define ull unsigned long long

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./LUYTHUA.INP", "r", stdin);
    freopen("./LUYTHUA.OUT", "w", stdout);

    ull a, n, d, S = 1;
    std:: cin >> a >> n >> d;

    std::cout << (ull)(pow(a, (n+1)*d)-1) / (ull)(pow(a, d) - 1);
    return 0;
}