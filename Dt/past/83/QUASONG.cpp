/**
 *	author: Lang Dat
 *	create: 31-10-2022 47:06:08
**/
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

const int MOD = 1e9 + 7;
const int LIM = 2 * 1e5;
std::vector<int> d;
int n, k, l, r;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./QUASONG.INP", "r", stdin);
    // freopen("./QUASONG.OUT", "w", stdout);

    std::cin >> n >> k;
    n--;
    std::vector<pair<int, int>> distance;
    while (std::cin >> l >> r) {
        distance.push_back({l, r});
    }
    sort(distance.begin(), distance.end(),  [](const pair<int, int> &a, const pair<int, int> &b) -> bool {
        if (a.first < b.first) return true;
        else if (a.first == b.first) return a.second < b.second;
        return false;
    });

    int pos = distance[0].first;
    for (auto &p : distance) {
        if (pos < p.first) pos = p.first;
        while (pos <= p.second) {
            d.push_back(pos);
            pos++;
        }
    }

    
    return 0;
}