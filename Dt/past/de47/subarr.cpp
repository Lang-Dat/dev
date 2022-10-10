#pragma GCC optimize("O2")
#include <iostream>
#include <algorithm>
#include <vector>

#define ll long long
const int LIM = 5 * 1e5 + 1;
ll nums[LIM];

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./subarr.INP", "r", stdin);
    // freopen("./test/subarr/test01/subarr.INP", "r", stdin);
    freopen("./subarr.OUT", "w", stdout);

    ll n, count = 0;
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
        std::cin >> nums[i];
        nums[i] += nums[i-1];
    }
    if (nums[n] % 3 != 0) {
        std::cout << 0;
        return 0;
    }
    const ll sum_of_seq = nums[n] / 3;
    std::vector<int> startSplitPoints; // incresing order
    std::vector<int> endSplitPoints;   // decresing order
    for (int start = 1, end = n; start <= n && end >= 0; start++, end--) {
        if (nums[start] == sum_of_seq) startSplitPoints.push_back(start);
        if (nums[n] - nums[end-1] == sum_of_seq) endSplitPoints.push_back(end);
    }
    std::sort(endSplitPoints.begin(), endSplitPoints.end());
    for (int start : startSplitPoints) {
        int endPoint = std::upper_bound(endSplitPoints.begin(), endSplitPoints.end(), start + 1) - endSplitPoints.begin();
        if (endPoint == endSplitPoints.size()) break;
        else count += endSplitPoints.size() - endPoint;
    }
    std::cout << count;
    return 0;
}