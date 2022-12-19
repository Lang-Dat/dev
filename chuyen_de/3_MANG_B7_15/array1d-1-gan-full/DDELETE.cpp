/**
 *	author: Lăng Trọng Đạt
 *	create: 16-12-2022 22:14:20
**/
#include <iostream>
#include <algorithm>
using namespace std;


int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./DDELETE.INP", "r", stdin);
    freopen("./DDELETE.OUT", "w", stdout);
    #endif

    uint64_t sum = 0, chan = 0, le = 0, n, tmp;
    std::cin >> n;
    while (std::cin >> tmp) {
        sum += tmp;
        (tmp & 1) ? le++ : chan++;
    }

    std::cout << (sum & 1 ? le * chan : le*(le - 1)/2 + chan*(chan - 1)/2) << "";
    return 0;
}