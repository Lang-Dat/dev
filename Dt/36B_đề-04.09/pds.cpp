#pragma GCC optimize("O2")
#include <iostream>

#define ull unsigned long long

bool tongChuSo(ull n) {
    int sum = 0, product = 1;
    while(n > 0 && product != 0) {
        int last = n % 10;
        sum += last;
        product = product * last;
        n /= 10;
    }
    return (sum == 0 || product % sum == 0);
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    // freopen("./pds.INP", "r", stdin);
    // freopen("./pds.OUT", "w", stdout);

    int n, count = 0;
    ull i = 1;
    std::cin >> n;
    for (; count < n; i++)
        count += (tongChuSo(i));
    std::cout << i - 1;
    return 0;
}