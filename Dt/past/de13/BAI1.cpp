#pragma GCC optimize("O2")
#include <math.h>
#include <iostream>

int tongUoc(int n) {
    int sum = 0;
    for (int i = 1; i <= std::sqrt(n); i++)
        if (n % i == 0 && i * i != n) sum += i + n / i;
        else if (n % i == 0 && i * i == n) sum += i;
    return sum;
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./BAI1.INP", "r", stdin);
    freopen("./BAI1.OUT", "w", stdout);

    int a, b;
    std::cin >> a >> b;
    if (tongUoc(a) == b || tongUoc(b) == a)
        std::cout << 1;
    else 
        std::cout << 0;
    return 0;
}