// https://leetcode.com/problems/decode-xored-array/
#include <iostream>
#include <vector>

std::vector<int> decode(std::vector<int>& encoded, int first) {
        int n = encoded.size() + 1;
        std::vector<int> ans(n);
        ans[0] = first;

        for (int i = 0; i < n - 1; i++)
        {
            ans[i+1] = first ^ encoded[i];
            first = ans[i+1];
        }   

        return ans;
}

int main()
{
    std::vector<int> nums = {0};
    // int n;
    // std::cin >> n;
    // for (int i = 0; i < n; i++) std::cin >> nums[i];
    logl(decode(nums, 1));
}