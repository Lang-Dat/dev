/**
 *	author : Lăng Trọng Đạt
 *	creater: 26-01-2023 08:41:48
**/
#include <iostream>
#include <algorithm>
using namespace std;


int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./XOASO.INP", "r", stdin);
    freopen("./XOASO.OUT", "w", stdout);
    #endif

    int64_t chan = 0, le = 0, tong = 0, n, tmp;
    std::cin >> n;
    while (std::cin >> tmp) {
        (tmp & 1) ? le++ : chan++;
        tong += tmp;
    }

    std::cout << (tong & 1 ? le * chan : le*(le - 1) / 2 + chan*(chan - 1) / 2) << "";

    return 0;
}