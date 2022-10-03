#pragma GCC optimize("O2")
#include <iostream>
#include <vector>
#include <algorithm>

#define ull unsigned long long

struct Cline {
    ull start = 0, end = 0, cost = 0;
};

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./BAI4.INP", "r", stdin);
    freopen("./BAI4.OUT", "w", stdout);

    ull n, best = 0, soKhachPhucVu = 0;
    std::cin >> n;
    Cline clines[n];
    std::vector<int> soKhach(n, 1);

    for (int i = 0; i < n; i++) std::cin >> clines[i].start >> clines[i].end >> clines[i].cost;
    std::sort(clines, clines + n, [](Cline a, Cline b) -> bool {return a.end < b.end;});
    for (int i = 0; i < n; i++) {
        int currCost = clines[i].cost;
        for (int j = 0; j < i; j++)
            if (clines[j].end < clines[i].start && 
                clines[j].cost + currCost > clines[i].cost) {
                clines[i].cost = clines[j].cost + currCost;
                soKhach[i] = soKhach[j] + 1;
            }
        if (clines[i].cost > best) {
            best = clines[i].cost;
            soKhachPhucVu = soKhach[i];
        }
    }
    std::cout << soKhachPhucVu << " " << best;
    return 0;
}