#pragma GCC optimize("O2")
#include <iostream>


void solve() {
    
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./in/in.inp", "r", stdin);
    freopen("./in/in.out", "w", stdout);

    int T;
    std::cin >> T;

    for (int i = 1; i <= T; i++) {
        std::cout << "Case #" << i << ": ";
        solve();
    }

    return 0;
}