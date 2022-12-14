#pragma GCC optimize("O2")
#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./DOANMAX.INP", "r", stdin);
    // freopen("./TEST/DOANMAX/Test12/DOANMAX.INP", "r", stdin);
    freopen("./DOANMAX.OUT", "w", stdout);

    int n, l, r, best = 0, curr = 1, i;
    std::cin >> n;
    short nums[n];
    for (int i = 0; i < n; i++)
        std::cin >> nums[i];
    
    for (i = 1; i < n; i++) {
        if (nums[i] >= nums[i - 1]) curr++;
        else if (nums[i] < nums[i-1]) {
            if (curr > best) {
                r = i;
                l = r - curr;
                best = curr;
            }
            curr = 1;
        }
    }
    if (curr > best) {
        r = i;
        l = r - curr;
        best = curr;
    }
    std::cout << best << "\n";
    for (int i = l; i < r; i++)
        std::cout << nums[i] << " ";
    return 0;
}