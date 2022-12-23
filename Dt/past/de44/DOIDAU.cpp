#pragma GCC optimize("O2")
#include <iostream>
#include <vector>

const int LIM = 20;
int nums[LIM];
bool isFound = false;
int n, sum = 0;

void dfs(std::vector<bool> is_swap, int pos = 0, int curr_sum = sum) {
    if (curr_sum == 0) {
        for (int i = 0; i < n; i++) {
            if (is_swap[i])
                std::cout << i + 1 << " ";
        }
        std::cout << "\n";
        isFound = true;
        return;
    }
    if (curr_sum < 0 || pos == n) return;
    dfs(is_swap, pos + 1, curr_sum);
    is_swap[pos] = true;
    dfs(is_swap, pos + 1, curr_sum - 2*nums[pos]); // trong curr_sum thi nums[pos] da duoc tinh mot lan nen ta phai nhan 2 len
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./DOIDAU.INP", "r", stdin);
    freopen("./DOIDAU.OUT", "w", stdout);

    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> nums[i];
        sum += nums[i];
    }    
    dfs(std::vector<bool>(n, false));
    if (!isFound) {
        std::cout << "0";
    }
    return 0;
}