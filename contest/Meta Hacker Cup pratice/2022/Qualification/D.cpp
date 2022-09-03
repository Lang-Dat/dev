#pragma GCC optimize("O2")
#include <iostream>
#include <utility>
#include <map>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long

int N, M, Q;
int a, b, c, x, y;
unordered_map<int, unordered_map<int, int>> paths; // path<diem dau: <diem cuoi, so khach cho duoc>> 
map<pair<int, int>, ll> partResults;
// void printPath() {
//     for (auto[Start, tmp] : paths) {
//         std::cout << "Start: " << Start << "\n";
//         for (auto[End, soKhach] : tmp) {
//             std::cout << "\tEnd: " << End << " C: " << soKhach << "\n";
//         }
//     }
// }

ll calcF(int x, int y) {
    // if (paths.count(x) == 0) return 0;
    if (partResults.count({x, y})) return partResults[{x, y}];
    if (partResults.count({y, x})) return partResults[{y, x}];
    
    unordered_map<int, int> &tmp = paths[x]; // <diem cuoi, C>
    ll diThang = 0;
    if (tmp.count(y))
        diThang = 2*(ll)tmp[y];

    for (auto[diemTrungChuyen, soKhach] : tmp) {
        // if (paths[diemTrungChuyen].count(y))
            diThang += min(soKhach, paths[diemTrungChuyen][y]);
    }

    partResults[{x, y}] = diThang;
    return diThang;
}

void solve(int case_i) {
    paths.clear();
    partResults.clear();
    std::cin >> N >> M >> Q;

    for (int i = 0; i < M; i++) {
        std::cin >> a >> b >> c;
        paths[a].insert({b, c});
        paths[b].insert({a, c});
    }
    std::cout << "Case #" << case_i << ": ";
    for (int i = 0; i < Q; i++) {
        std::cin >> x >> y;
        ll F = calcF(x, y);
        cout << F << " ";
    }
    cout << "\n";
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    // freopen("second_flight_input.txt", "r", stdin);
    // freopen("D.out", "w", stdout);
    freopen("in.inp", "r", stdin);
    freopen("in.out", "w", stdout);

    int T;
    std::cin >> T;
    
    for (int i = 1; i <= T; i++) {
        solve(i);
    }
    
    return 0;
}