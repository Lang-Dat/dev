#pragma GCC optimize("O2")
#include <iostream>

int tinhTong(unsigned long long num) {
    int sum = 0;
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("SDB.INP", "r", stdin);
    freopen("SDB.OUT", "w", stdout);

    unsigned long long num;
    std::cin >> num;

    if (num % tinhTong(num) == 0)
        std::cout << 1;
    else
        std::cout << 0;

    return 0;
}