#pragma GCC optimize("O2")
#include <iostream>

const int LIM = 17;
int W[LIM];
int n, best = 0, C;

void dfs(int pos = 0, int sum = 0) {
    if (pos >= n && sum <= C) {
        best = std::max(sum, best);
        return;
    }
    if (sum > C || best == C) return;
    dfs(pos + 1, sum + W[pos]); // inclu
    dfs(pos + 1, sum); // exclu
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./BAI5.INP", "r", stdin);
    freopen("./BAI5.OUT", "w", stdout);

    std::cin >> C >> n;
    for (int i = 0; i < n; i++) std::cin >> W[i];
    dfs();
    std::cout << best;
    return 0;
}