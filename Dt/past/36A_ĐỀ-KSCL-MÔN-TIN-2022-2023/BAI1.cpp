#pragma GCC optimize("O2")
#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./BAI1.INP", "r", stdin);
    freopen("./BAI1.OUT", "w", stdout);

    int n, count = 0;
    std::cin >> n;
    double nums[n];
    for (int i = 0; i < n; i++)
        std::cin >> nums[i];
    
    for (int i = 0; i < n; i++)
        if ((i == 0 && nums[i] < nums[i+1]) ||
            (i == n - 1 && nums[i] < nums[i - 1]) ||
            (nums[i] < nums[i-1] && nums[i] < nums[i+1])) count++;
    std::cout << count;
    return 0;
}