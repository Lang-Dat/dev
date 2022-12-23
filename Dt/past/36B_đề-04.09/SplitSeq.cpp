#pragma GCC optimize("O2")
#include <iostream>

void splitToExtraKSub(int n, int k, int odd_ele = 0) {
    int nums[n];
    for (int i = 0; i < n; i++) {
        std::cin >> nums[i];
        if (nums[i] % 2 == 1) odd_ele++;
    }
    if (k > odd_ele ||
        (odd_ele >= k && (odd_ele - k) % 2 == 1)) {
            std::cout << "NO\n";
            return;
        }
    std::cout << "YES\n";
    for (int i = 0; i < n && k > 0; i++)
        if (nums[i] % 2 == 1) {
            std::cout << i + 1 << " ";
            k--;
        }
    std::cout << "\n";
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./Test/SplitSeq/test01/SplitSeq.INP", "r", stdin);
    // freopen("./SplitSeq.OUT", "w", stdout);

    int n, k, q;
    std::cin >> q;
    while (std::cin >> n >> k)
        splitToExtraKSub(n, k); 

    return 0;
}