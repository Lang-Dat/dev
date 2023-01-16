/**
 *	author: Lăng Trọng Đạt
 *	create: 28-12-2022 03:30:20
**/
#include <iostream>
#include <cmath>
using namespace std;

inline bool check(int m) {
    m = m*(m + 1) / 2;
    int sq = sqrt(m);
    return (sq*(sq+1) == m);
}

int main()
{
    int n;
    std::cin >> n;
    bool is_print = false;
    for (int i = 2; i <= n; i++) {
        if (check(i))
            std::cout << i << " ";
    }

    if (!is_print)
        std::cout << -1 << "";
    return 0;
}