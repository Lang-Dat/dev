#pragma GCC optimize("O2")
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>

std::set<std::vector<short>> subset;
std::set<std::vector<short>> res;
int n, m;
void buildSubset(int pos = 1, std::vector<short> tmp = {}) {
    if (pos > n+1) return;
    if (tmp.size() == m) {
        subset.insert(tmp);
        return;
    }
    buildSubset(pos + 1, tmp);
    tmp.push_back(pos);
    buildSubset(pos + 1, tmp);
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("SON.INP", "r", stdin);
    freopen("SON.OUT", "w", stdout);

    std::cin >> n >> m;
    buildSubset();
    for (auto v : subset) {
        std::sort(v.begin(), v.end());
        do
        {
            res.insert(v);
        } while (std::next_permutation(v.begin(), v.end()));
    }
    for (auto v : res) {
        for (auto i : v)
            std::cout << i << " ";
        std::cout << "\n";
    }
    std::cout << res.size();
    return 0;
}