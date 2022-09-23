#pragma GCC optimize("O2")
#include <iostream>
#include <unordered_map>

std::unordered_map<int, int> freq;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./KHOANGCACH.INP", "r", stdin);
    freopen("./KHOANGCACH.OUT", "w", stdout);

    int n;
    long long ans = 0;
    std::cin >> n;
    int nums[n];
    for (int i = 0; i < n; i++)
        std::cin >> nums[i];

    for (int j = 0; j < n - 2; j++) {
        int val = 0;
        for (int t = j + 1; t < n; t++) {
            if (nums[j] == nums[t])
                ans += val;
            val += freq[nums[t]];
        }
        freq[nums[j]]++;
    }
    std::cout << ans;
    return 0;
}