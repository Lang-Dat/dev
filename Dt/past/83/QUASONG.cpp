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
// const int LIM = 2 * 1e5;
const int LIM = 5;
std::vector<int> d;
vector<vector<int>> dp;
int n, k, l, r, ans = 0;

bool numOfSubset(int &target, int pos = 0, int curr_sum = 1) {
    if (curr_sum == target) {
        ans++;
        return true;
    }
    if (curr_sum > target || pos == d.size()) return false;
    if (dp[pos][curr_sum] == 1) {
        ans++;
        return true;
    } else if (dp[pos][curr_sum] == -1) return false;

    dp[pos][curr_sum + d[pos]] = (numOfSubset(target, pos + 1, curr_sum + d[pos])) ? 1 : -1;
    if (dp[pos][curr_sum + d[pos]] == 1) {
        ans++;
        return true;
    }
    dp[pos][curr_sum] = (numOfSubset(target, pos + 1, curr_sum)) ? 1 : -1;
    if (dp[pos][curr_sum] == 1) {
        ans++;
        return true;
    }
    return false;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    // freopen("./QUASONG.INP", "r", stdin);
    // freopen("./QUASONG.OUT", "w", stdout);

    std::cin >> n >> k;
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

    dp.resize(d.size() + 1, vector<int>(n, 0));
    n--;
    numOfSubset(n);
    std::cout << ans << "";
    return 0;
}