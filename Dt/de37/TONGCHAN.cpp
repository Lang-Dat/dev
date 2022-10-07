#pragma GCC optimize("O2")
#include <iostream>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./TONGCHAN.INP", "r", stdin);
    freopen("./TONGCHAN.OUT", "w", stdout);

    long long n, tmp, chan = 0, le = 0, sum = 0;
    std::cin >> n;
    while(std::cin >> tmp) {
        (tmp % 2 == 0) ? chan++ : le++;
        sum += tmp;
    }
    if (sum % 2 == 0)
        std::cout << chan*(chan - 1) / 2 + le*(le - 1) / 2;
    else 
        std::cout << chan*le;
    return 0;
}