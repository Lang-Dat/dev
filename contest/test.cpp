#include <iostream>
#include <vector>

int n, k;
std::vector<int> nums;

bool solve(int pos = 0, int sum = 0)
{
    if (pos == n) {
        if (sum == k) return true;
        else return false;
    }

    if (solve(pos + 1, sum + nums[pos]) || solve(pos + 1, sum))
        return true;

    return false; 
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> n;
    nums.resize(n);
    for (int i = 0; i < n; i++)
        std::cin >> nums[i];
    std::cin >> k;

    bool ans = solve();
    if (ans)
        std::cout << "Yes";
    else 
        std::cout << "No";

    return 0;
}