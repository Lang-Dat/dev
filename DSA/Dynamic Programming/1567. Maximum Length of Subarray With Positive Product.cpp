// https://leetcode.com/problems/maximum-length-of-subarray-with-positive-product/
#include <iostream>
#include <vector>
#include <algorithm>

    int getMaxLenOfSub(std::vector<int>& nums) {
        int first = 0, last = 0, count = 0, n = nums.size();

        // find the first and the last index of negative number
        for (int i = 0; i < n; i++)
            if (nums[i] < 0) {
                first = i;
                break;
            }
        for (int i = n - 1; i >= 0; i--)
            if (nums[i] < 0) {
                last = i;
                break;
            }
        for (int i = first; i <= last; i++)
            if (nums[i] < 0) count++;

        if (count % 2 == 0 || count == 0) return n;
        return std::max(last /*first*/, n - first - 1 /*last*/);
    }

    int getMaxLen(std::vector<int>& nums) {
        std::vector<int> subNums;
        int res = 0, currRes = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) subNums.push_back(nums[i]);
            if ((nums[i] == 0 || i == nums.size() - 1) && subNums.size() != 0) {
                int currRes = getMaxLenOfSub(subNums);
                if (currRes > res) res = currRes; 
                subNums.clear();
            }        
        }
        return res;
    }

int main()
{
    // std::vector<int> nums {0, 0, 0, 0, 0};
    int n;
    std::cin >> n;
    std::vector<int> nums(n);

    for (int i = 0; i < nums.size(); i++) std::cin >> nums[i];

    std::cout << (getMaxLen(nums));
}