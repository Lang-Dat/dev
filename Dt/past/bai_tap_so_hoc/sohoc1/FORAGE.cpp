/**
 *	author: Lăng Trọng Đạt
 *	create: 08-12-2022 11:04:16
**/
#include <iostream>
#include <algorithm>
using namespace std;


int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./FORAGE.INP", "r", stdin);
    freopen("./FORAGE.OUT", "w", stdout);
    #endif

    uint64_t p, n, k, request;
    cin >> p >> n >> k;
    request = k * (n+1) * n / 2;
    if (p >= request) std::cout << "YES";
    else std::cout << "NO\n" << request - p;
    return 0;
}