#pragma GCC optimize("O2")
#include <iostream>
#include <algorithm>
#include <vector>

#define ll long long
const int LIM = 1e4 + 5;

struct Coor {
    ll start = 0, end = 0;
    Coor(ll x, ll d)
     : start(x), end(x + d) {}
};

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./BAI4.INP", "r", stdin);
    freopen("./BAI4.OUT", "w", stdout);

    ll x, d;
    std::vector<Coor> coors;
    coors.reserve(LIM);

    while(std::cin >> x >> d) {
        coors.push_back(Coor(x, d));
    }
    std::sort(coors.begin(), coors.end(), [](Coor &a, Coor &b) -> bool {
        if (a.start == b.start) return a.end < b.end;
        return a.start < b.start;
    });
    // for (auto[start, end] : coors)
    //     log(start, end)
    ll prevStart = coors[0].start, maxEnd = coors[0].end, ans = 0;
    for (int i = 1; i < coors.size(); i++) {
        if (coors[i].start <= maxEnd && coors[i].end > maxEnd) {
            maxEnd = coors[i].end;
        }
        else if (coors[i].start > maxEnd) {
            ans += maxEnd - prevStart;
            prevStart = coors[i].start;
            maxEnd = coors[i].end;
        }
    }
    ans += maxEnd - prevStart;
    std::cout << ans;
    return 0;
}