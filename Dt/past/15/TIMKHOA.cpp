/**
 *	author: Lăng Trọng Đạt
 *	create: 05-12-2022 01:01:21
**/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./TIMKHOA.INP", "r", stdin);
    freopen("./TIMKHOA.OUT", "w", stdout);
    #endif

    int n, tmp, ucln;
    std::cin >> n >> ucln;
    while (std::cin >> tmp)
        ucln = __gcd(ucln, tmp);
    std::cout << ucln << "";

    return 0;
}