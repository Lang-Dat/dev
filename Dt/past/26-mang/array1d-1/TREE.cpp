/**
 *	author: Lăng Trọng Đạt
 *	create: 17-12-2022 00:41:20
**/
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;


int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./TREE.INP", "r", stdin);
    freopen("../../../chuyen_de/3_MANG_B7_15/array1D_1/TREE/test01/TREE.INP", "r", stdin);
    freopen("./TREE.OUT", "w", stdout);
    #endif

    int n, k;
    std::vector<std::string> ans;
    std::cin >> n >> k;
    int nums[n];
    for (int i = 1; i <= n; i++) {
        std::cin >> nums[i];
    }
    nums[0] = k;
    string ans_out = "";
    for (int i = 1; i <= n; i++) {
        if (nums[i] > nums[i-1]) {
            ans_out = "+ " + std::to_string(i) + " " + to_string(nums[i] - nums[i-1]);
            ans.push_back(ans_out); 
        } else if (nums[i] < nums[i-1]) {
            ans_out = "- " + std::to_string(i) + " " + to_string(nums[i-1] - nums[i]);
            ans.push_back(ans_out); 
        }
        nums[i] = nums[i-1] + k;
    }

    std::cout << ans.size() << "\n";
    for (string ans_out : ans)
        std::cout << ans_out << "\n";
    return 0;
}