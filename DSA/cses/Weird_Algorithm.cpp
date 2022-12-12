/**
 *	author: Lăng Trọng Đạt
 *	create: 12-12-2022 49:58:07
**/
#include <iostream>
using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    uint64_t n;
    std::cin >> n;
    while (n != 1) {
        std::cout << n << " ";
        (n & 1) ? n = n*3 + 1 : n /= 2;
    }
    std::cout << 1 << "";
    return 0;
}