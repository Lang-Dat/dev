#pragma GCC optimize("O2")
#include <math.h>
#include <iostream>
#include <algorithm>
#include <algorithm>

std::vector<int> uocs;
std::vector<std::vector<int>> ans;

void tongUoc(int n) {
    for (int i = 1; i * i <= n; i++)
        if (n % i == 0 && i * i != n) {
            uocs.push_back(i);
            uocs.push_back(n / i);
        }
        else if (n % i == 0 && i * i == n) uocs.push_back(i);
    std::sort(uocs.begin(), uocs.end());
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./CHIADOAN.INP", "r", stdin);
    freopen("./CHIADOAN.OUT", "w", stdout);

    int n, tmp, best;
    std::cin >> n;
    std::vector<int> nums(n+1, 0);
    std::vector<int> ori_nums(n+1, 0);
    for (int i = 1; i <= n; i++) {
        std::cin >> tmp;
        ori_nums[i] = tmp;
        nums[i] += nums[i-1] + tmp;
    }
    tongUoc(nums[n]);
    for (int uoc : uocs) {
        int L, R = 0, count = 0;
        std::vector<std::vector<int>> currBestans;
        while (R != n) {
            count++;
            L = R + 1;
            R = std::lower_bound(nums.begin() + L + 1, nums.end(), uoc + nums[L-1]) - nums.begin();      
            if (R == nums.end() - nums.begin()) break;
            currBestans.push_back({L, R});
            if (R == n && currBestans.size() > ans.size()) {
                ans = currBestans;
                break;
            }
        }
    }
    std::cout << ans.size() << " " << nums[ans[0][1]] - nums[ans[0][0] - 1] << "\n";
    for (int i = 0; i < ans.size(); i++) {
        for (int L = ans[i][0]; L <= ans[i][1]; L++)
            std::cout << ori_nums[L] << " ";
        std::cout << "\n";
    }
    return 0;
}