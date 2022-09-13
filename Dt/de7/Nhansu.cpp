#pragma GCC optimize("O2")
#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("Nhansu.INP", "r", stdin);
    freopen("Nhansu.OUT", "w", stdout);

    int n, tmp;
    std::vector<int> nums;
    std::cin >> n;
    while(std::cin >> tmp) {
        for (int i : nums)
            if (i == tmp) goto cnt;
        nums.push_back(tmp);
        cnt:;
    }
    for (int i : nums)
        std::cout << i << " ";
    return 0;
}