#include <iostream>

int solve(int n)
{
    n--;
    return 1 + n / 5;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("in.inp", "r", stdin);
    freopen("in.out", "w", stdout);

    int T, n;
    std::cin >> T;
    
    for (int i = 1; i <= T; i++)
    {
        std::cin >> n;
        int ans = solve(n);
        std::cout << "Case #" << i << ": " << ans << "\n";
    }
    

    return 0;
}