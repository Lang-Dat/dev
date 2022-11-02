#pragma GCC optimize("O2")
#include <iostream>

const int LIM = 1e5 + 5;
int n, x, y;
int winners[LIM];

bool Try(int tmp) {
    
}

void solve() {
    std::cin >> n >> x >> y;
    if (Try(x) || Try(y))
        for (int i = 0; i < n; i++)    
            std::cout << winners[i] << " ";
    else 
        std::cout << -1;
    std::cout << "\n";
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