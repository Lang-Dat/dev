#pragma GCC optimize("O2")
#include <math.h>
#include <iostream>

int tongUoc(int n) {
    int sum = 0;
    for (int i = 2; i <= std::sqrt(n); i++) {
        if (i * i == n) sum += i;
        else if (n % i == 0) sum += i + n / i;
    }

    return sum;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./ANHEM.INP", "r", stdin);
    freopen("./ANHEM.OUT", "w", stdout);

    int n, m;
    std::cin >> n >> m;
    
    if (tongUoc(n) == tongUoc(m))
        std::cout << "YES";
    else 
        std::cout << "NO";

    return 0;
}