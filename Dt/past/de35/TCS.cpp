#pragma GCC optimize("O2")
#include <iostream>

#define ull unsigned long long

ull tongChuSo(ull n, ull sum = 0) {
    while(n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./TCS.INP", "r", stdin);
    freopen("./TCS.OUT", "w", stdout);

    ull a, b;
    std::cin >> a >> b;
    std::cout << tongChuSo(a) + tongChuSo(b);    

    return 0;
}