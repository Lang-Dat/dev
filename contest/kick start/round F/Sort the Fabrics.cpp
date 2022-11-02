#pragma GCC optimize("O2")
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

struct Fabric
{
    std::string C;
    int D, U;
};

const int LIM = 1e3 + 3;
int n, d, u;
std::string c;
std::vector<Fabric> fabrics_ada(LIM);
std::vector<Fabric> fabrics_charles(LIM);

bool ada(Fabric a, Fabric b) {
    return a.C < b.C;
    return a.U < b.U;
}
bool charles(Fabric a, Fabric b) {
    return a.D < b.D;
    return a.U < b.U;
}
void solve() {
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> c >> d >> u;
        fabrics_ada[i].C = c; fabrics_ada[i].D = d; fabrics_ada[i].U = u;
        fabrics_charles[i].C = c; fabrics_charles[i].D = d; fabrics_charles[i].U = u;
    }
    std::sort(fabrics_ada.begin(), fabrics_ada.begin() + n, ada);
    std::sort(fabrics_charles.begin(), fabrics_charles.begin() + n, charles);
    int ans = 0;
    for (int i = 0; i < n; i++)
        ans += fabrics_ada[i].U == fabrics_charles[i].U;

    std::cout << ans << "\n";
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    // freopen("./in/in.inp", "r", stdin);
    // freopen("./in/in.out", "w", stdout);

    int T;
    std::cin >> T;

    for (int i = 1; i <= T; i++) {
        std::cout << "Case #" << i << ": ";
        solve();
    }

    return 0;
}