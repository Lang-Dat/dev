#include <iostream>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    // freopen("a.inp", "r", stdin);
    freopen("a.inp", "w", stdout);

    int n = 5000;
    std::cin >> n;
    std::cout << n << "\n";

    
    int x;
    for (int i = 0; i < n; i++) {
        x = rand() % 10000;
        std::cout << x << " ";
    }

    return 0;
}