#pragma GCC optimize("O2")
#include <iostream>
#include <unordered_map>
#include <utility>
#include <algorithm>
#include <map>
using namespace std;

int N, M, Q, x, y, c;
const int LIM = 200005;
map<int, unordered_map<int, int>> g;
map<pair<int, int>, long long> preAns;

void calc(int x, int y) {
    if (preAns.count({x, y})) {
        cout << preAns[{x, y}];
        return;
    }
    if (preAns.count({y, x})) {
        cout << preAns[{y, x}];
        return;
    }
    long long ans = 0;
    if (g.count(x)) {
        ans = 2 * g[x][y];
        for (auto[diemTC, C] : g[x]) {
            if (g.count(diemTC) && g[diemTC].count(y))
                ans += min(C, g[diemTC][y]);
        }
    }
    preAns[{x, y}] = ans;
    cout << ans << " ";
}

void solve(int case_i) {
    g.clear();
    preAns.clear();
    cin >> N >> M >> Q;
    for (int i = 0; i < M; i++)
    {
        cin >> x >> y >> c;
        g[x][y] = c;
        g[y][x] = c;
    }

    for (auto[x, end] : g) {
        cout << x << ": { ";
        for (auto[y, c] : end) {
            cout << y << " -> " << c << "; ";
        }
        cout << "}\n";
    }
    for (int i = 0; i < Q; i++)
    {
        cin >> x >> y;
        // calc(x, y);
    }
    
    cout << "\n";
}

int main()
{
    // Timer time;
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./in/in.inp", "r", stdin);
    freopen("./in/in.out", "w", stdout);

    int T;
    std::cin >> T;

    for (int i = 1; i <= T; i++) {
        std::cout << "Case #" << i << ": ";
        solve(i);
    }

    return 0;
}