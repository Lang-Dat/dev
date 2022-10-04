#pragma GCC optimize("O2")
#include <iostream>

#define ull unsigned long long

bool tongChuSo(ull n) {
    short sum = 0, product = 1;
    while(n > 0 && product != 0) {
        short last = n % 10;
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
    freopen("./pds.INP", "r", stdin);
    freopen("./pds.OUT", "w", stdout);
    
    int n;
    ull i = 0;
    std::cin >> n;
    for (int count = 0; count < n; i++, count += (tongChuSo(i))) {}
    std::cout << i << "\n";
    return 0;
}