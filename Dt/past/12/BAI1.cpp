/**
 *	author: Lăng Trọng Đạt
 *	create: 04-12-2022 05:51:09
**/
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;


int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./BAI1.INP", "r", stdin);
    freopen("./BAI1.OUT", "w", stdout);
    #endif

    int64_t n, tong = 0;
    std::cin >> n;
    for (int64_t i = 1; n > 0; i++) {
        n -= i;
        tong += i * i;
        if (n < 0) tong -= std::abs(n)*i;  
    }
    std::cout << tong << "";
    return 0;
}