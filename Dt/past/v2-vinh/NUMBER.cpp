/**
 *	author: Lăng Trọng Đạt
 *	create: 26-12-2022 56:16:22
**/
#include <iostream>
#include <algorithm>
using namespace std;


int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./NUMBER.INP", "r", stdin);
    freopen("./NUMBER.OUT", "w", stdout);
    #endif

    uint64_t n, count = 0;
    std::cin >> n;

    while (n != 1) {
        count++;
        n = (n & 1) ? n*3 + 1 : n / 2;
    }

    std::cout << count << "";

    return 0;
}